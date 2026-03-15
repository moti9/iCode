package com.jwtauth.service;

import java.time.LocalDateTime;
import java.util.List;
import java.util.UUID;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpMethod;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.LinkedMultiValueMap;
import org.springframework.util.MultiValueMap;
import org.springframework.web.client.RestTemplate;
import org.springframework.web.util.UriComponentsBuilder;

import com.jwtauth.config.ApplicationProperties;
import com.jwtauth.dto.GoogleTokenResponse;
import com.jwtauth.dto.GoogleUserInfo;
import com.jwtauth.dto.TokenResponse;
import com.jwtauth.entity.Employee;
import com.jwtauth.entity.EmployeeRoleACL;
import com.jwtauth.entity.UserAuth;
import com.jwtauth.enums.RoleACL;
import com.jwtauth.exception.AuthenticationException;
import com.jwtauth.repository.EmployeeRepository;
import com.jwtauth.repository.EmployeeRoleACLRepository;
import com.jwtauth.repository.UserAuthRepository;
import com.jwtauth.util.RoleACLUtils;

import lombok.RequiredArgsConstructor;

/**
 * Google OAuth Service.
 * 
 * Handles Google OAuth 2.0 authentication flow:
 * 1. Generate authorization URL
 * 2. Exchange authorization code for tokens
 * 3. Fetch user info from Google
 * 4. Create or update employee record
 * 5. Generate JWT tokens
 * 
 * @author Moti Yadav
 */
@Service
@RequiredArgsConstructor
public class GoogleOAuthService {
    
    private static final Logger log = LoggerFactory.getLogger(GoogleOAuthService.class);
    
    private final ApplicationProperties appProperties;
    private final JwtService jwtService;
    private final EmployeeRepository employeeRepository;
    private final EmployeeRoleACLRepository employeeRoleACLRepository;
    private final UserAuthRepository userAuthRepository;
    private final RestTemplate restTemplate = new RestTemplate();
    
    /**
     * Generate Google OAuth authorization URL.
     * 
     * This URL redirects users to Google's consent screen.
     * 
     * @return Authorization URL
     */
    public String getAuthorizationUrl() {
        ApplicationProperties.Google.GoogleOAuth oauth = appProperties.getGoogle().getOauth();
        
        // Validate OAuth configuration
        if (oauth.getClientId() == null || oauth.getClientId().equals("YOUR_GOOGLE_CLIENT_ID")) {
            throw new IllegalStateException(
                """
                Google OAuth is not configured. Please update application.properties with your Google OAuth credentials.
                Get credentials from: https://console.cloud.google.com/apis/credentials
                Required properties:
                  - app.google.oauth.client-id
                  - app.google.oauth.client-secret
                """);
        }
        
        return UriComponentsBuilder.fromUriString(oauth.getAuthorizationUrl())
                .queryParam("client_id", oauth.getClientId())
                .queryParam("redirect_uri", oauth.getRedirectUri())
                .queryParam("response_type", "code")
                .queryParam("scope", oauth.getScope())
                .queryParam("access_type", oauth.getAccessType())
                .queryParam("prompt", oauth.getPrompt())
                .build()
                .toUriString();
    }
    
    /**
     * Handle OAuth callback and authenticate user.
     * 
     * Steps:
     * 1. Exchange authorization code for access token
     * 2. Fetch user info from Google
     * 3. Validate email domain
     * 4. Create/update employee record
     * 5. Generate JWT tokens
     * 6. Store session in database
     * 
     * @param code Authorization code from Google
     * @return TokenResponse with JWT tokens and user info
     * @throws AuthenticationException if authentication fails
     */
    @Transactional
    public TokenResponse handleCallback(String code) {
        try {
            log.info("Processing OAuth callback...");
            
            // Step 1: Exchange code for tokens
            GoogleTokenResponse googleTokens = exchangeCodeForToken(code);
            log.debug("Received Google tokens");
            
            // Step 2: Fetch user info
            GoogleUserInfo userInfo = fetchUserInfo(googleTokens.getAccessToken());
            log.info("Authenticated user: {}", userInfo.getEmail());
            
            // Step 3: Validate email domain
            validateEmailDomain(userInfo.getEmail());
            
            // Step 4: Create or update employee
            Employee employee = createOrUpdateEmployee(userInfo);
            
            // Step 5: Assign default role if new user
            ensureEmployeeHasRole(employee);
            
            // Step 6: Get employee's roles
            List<RoleACL> roles = getEmployeeRoles(employee.getId());
            int rolesBitmask = RoleACLUtils.roleListToBitmask(roles);
            
            // Step 7: Generate JWT tokens
            String accessToken = jwtService.createAccessToken(
                    employee.getId(),
                    employee.getEmail(),
                    employee.getName(),
                    rolesBitmask
            );
            String refreshToken = jwtService.createRefreshToken(employee.getId(), employee.getEmail());
            
            // Step 8: Store session
            storeUserAuthSession(
                employee.getId(),
                accessToken,
                refreshToken,
                googleTokens.getAccessToken(),
                googleTokens.getRefreshToken(),
                googleTokens.getExpiresIn()
            );
            
            log.info("✓ Authentication successful for: {}", employee.getEmail());
            
            // Return response
            return TokenResponse.builder()
                    .accessToken(accessToken)
                    .refreshToken(refreshToken)
                    .tokenType("Bearer")
                    .expiresIn(jwtService.getAccessTokenExpirySeconds())
                    .employee(TokenResponse.EmployeeInfo.builder()
                            .id(employee.getId())
                            .email(employee.getEmail())
                            .name(employee.getName())
                            .profilePicture(employee.getProfilePicture())
                            .roleACL(rolesBitmask)
                            .build())
                    .build();
            
        } catch (AuthenticationException e) {
            throw e;
        } catch (Exception e) {
            log.error("OAuth callback failed", e);
            throw new AuthenticationException("Authentication failed: " + e.getMessage());
        }
    }
    
    /**
     * Exchange authorization code for access token.
     * 
     * @param code Authorization code
     * @return Google token response
     */
    private GoogleTokenResponse exchangeCodeForToken(String code) {
        ApplicationProperties.Google.GoogleOAuth oauth = appProperties.getGoogle().getOauth();
        
        // Prepare request
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_FORM_URLENCODED);
        
        MultiValueMap<String, String> body = new LinkedMultiValueMap<>();
        body.add("code", code);
        body.add("client_id", oauth.getClientId());
        body.add("client_secret", oauth.getClientSecret());
        body.add("redirect_uri", oauth.getRedirectUri());
        body.add("grant_type", "authorization_code");
        
        HttpEntity<MultiValueMap<String, String>> request = new HttpEntity<>(body, headers);
        
        // Send request
        ResponseEntity<GoogleTokenResponse> response = restTemplate.exchange(
                oauth.getTokenUrl(),
                HttpMethod.POST,
                request,
                GoogleTokenResponse.class
        );
        
        if (response.getBody() == null) {
            throw new AuthenticationException("Failed to get tokens from Google");
        }
        
        return response.getBody();
    }
    
    /**
     * Fetch user info from Google.
     * 
     * @param accessToken Google access token
     * @return Google user info
     */
    private GoogleUserInfo fetchUserInfo(String accessToken) {
        ApplicationProperties.Google.GoogleOAuth oauth = appProperties.getGoogle().getOauth();
        
        HttpHeaders headers = new HttpHeaders();
        headers.setBearerAuth(accessToken);
        
        HttpEntity<String> request = new HttpEntity<>(headers);
        
        ResponseEntity<GoogleUserInfo> response = restTemplate.exchange(
                oauth.getUserInfoUrl(),
                HttpMethod.GET,
                request,
                GoogleUserInfo.class
        );
        
        if (response.getBody() == null) {
            throw new AuthenticationException("Failed to get user info from Google");
        }
        
        GoogleUserInfo userInfo = response.getBody();
        
        if (!Boolean.TRUE.equals(userInfo.getEmailVerified())) {
            throw new AuthenticationException("Email not verified");
        }
        
        return userInfo;
    }
    
    /**
     * Validate email domain against allowed domains.
     * 
     * @param email User's email
     */
    private void validateEmailDomain(String email) {
        List<String> allowedDomains = appProperties.getSecurity().getAllowedEmailDomains();
        
        // If no domains specified, allow all
        if (allowedDomains.isEmpty()) {
            return;
        }
        
        String domain = email.substring(email.indexOf('@') + 1);
        
        if (!allowedDomains.contains(domain)) {
            log.warn("Email domain not allowed: {}", domain);
            throw new AuthenticationException("Email domain not allowed: " + domain);
        }
    }
    
    /**
     * Create or update employee record.
     * 
     * @param userInfo Google user info
     * @return Employee entity
     */
    private Employee createOrUpdateEmployee(GoogleUserInfo userInfo) {
        return employeeRepository.findByEmail(userInfo.getEmail())
                .map(employee -> {
                    // Update existing employee
                    employee.setName(userInfo.getName());
                    employee.setProfilePicture(userInfo.getPicture());
                    employee.setUpdatedAt(LocalDateTime.now());
                    log.debug("Updating existing employee: {}", employee.getId());
                    return employeeRepository.save(employee);
                })
                .orElseGet(() -> {
                    // Create new employee
                    Employee newEmployee = Employee.builder()
                            .id(generateEmployeeId())
                            .email(userInfo.getEmail())
                            .name(userInfo.getName())
                            .profilePicture(userInfo.getPicture())
                            .status(Employee.EmployeeStatus.ACTIVE)
                            .createdAt(LocalDateTime.now())
                            .updatedAt(LocalDateTime.now())
                            .build();
                    log.info("Creating new employee: {}", newEmployee.getEmail());
                    return employeeRepository.save(newEmployee);
                });
    }
    
    /**
     * Ensure employee has at least one role.
     * Assign HR role by default for new users.
     * 
     * @param employee Employee entity
     */
    private void ensureEmployeeHasRole(Employee employee) {
        List<EmployeeRoleACL> existingRoles = employeeRoleACLRepository.findByEmployeeId(employee.getId());
        
        if (existingRoles.isEmpty()) {
            try {
                // Assign default HR role
                // Let Hibernate handle ID generation and timestamps via @UuidGenerator, @CreationTimestamp, @UpdateTimestamp
                EmployeeRoleACL roleACL = EmployeeRoleACL.builder()
                        .employeeId(employee.getId())
                        .roleAcl(RoleACL.HR)
                        .build();
                
                employeeRoleACLRepository.save(roleACL);
                log.info("Assigned default HR role to: {}", employee.getEmail());
            } catch (Exception e) {
                // Handle race condition: role might have been created by concurrent request
                log.warn("Role assignment conflict for employee {}, checking existing roles: {}", 
                        employee.getEmail(), e.getMessage());
                
                // Re-query to verify role exists
                List<EmployeeRoleACL> requeried = employeeRoleACLRepository.findByEmployeeId(employee.getId());
                if (requeried.isEmpty()) {
                    // If still no roles, this is a real error
                    throw new RuntimeException("Failed to assign role to employee: " + employee.getEmail(), e);
                }
                log.info("Employee {} already has {} role(s)", employee.getEmail(), requeried.size());
            }
        }
    }
    
    /**
     * Get employee's roles from database.
     * 
     * @param employeeId Employee ID
     * @return List of roles
     */
    private List<RoleACL> getEmployeeRoles(String employeeId) {
        return employeeRoleACLRepository.findByEmployeeId(employeeId)
                .stream()
                .map(EmployeeRoleACL::getRoleAcl)
                .toList();
    }
    
    /**
     * Store user authentication session in database.
     * 
     * @param employeeId Employee ID
     * @param accessToken JWT access token
     * @param refreshToken JWT refresh token
     * @param providerAccessToken Google access token
     * @param providerRefreshToken Google refresh token
     * @param expiresIn Token expiry in seconds
     */
    private void storeUserAuthSession(
            String employeeId,
            String accessToken,
            String refreshToken,
            String providerAccessToken,
            String providerRefreshToken,
            Integer expiresIn
    ) {
        // Logout any existing sessions
        userAuthRepository.findByEmployeeId(employeeId)
                .ifPresent(existingAuth -> {
                    existingAuth.setIsLoggedOut(true);
                    // updatedAt is handled by @UpdateTimestamp
                    userAuthRepository.save(existingAuth);
                });
        
        // Create new session
        LocalDateTime providerTokenExpiry = expiresIn != null 
                ? LocalDateTime.now().plusSeconds(expiresIn.longValue())
                : LocalDateTime.now().plusHours(1);
        
        // Let Hibernate handle ID generation and timestamps via annotations
        UserAuth userAuth = UserAuth.builder()
                .employeeId(employeeId)
                .accessTokenHash(jwtService.hashToken(accessToken))
                .refreshTokenHash(jwtService.hashToken(refreshToken))
                .authProvider("GOOGLE")
                .providerAccessToken(providerAccessToken)
                .providerRefreshToken(providerRefreshToken)
                .providerTokenExpiry(providerTokenExpiry)
                .isLoggedOut(false)
                .lastLoggedIn(LocalDateTime.now())
                .build();
        
        userAuthRepository.save(userAuth);
        log.debug("Stored auth session for employee: {}", employeeId);
    }
    
    /**
     * Generate unique employee ID.
     * 
     * Format: EMP-{timestamp}-{random}
     * 
     * @return Employee ID
     */
    private String generateEmployeeId() {
        return "EMP-" + System.currentTimeMillis() + "-" + 
               UUID.randomUUID().toString().substring(0, 8).toUpperCase();
    }
}
