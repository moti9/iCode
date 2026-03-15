package com.jwtauth.controller;

import java.io.IOException;
import java.time.Duration;
import java.time.LocalDateTime;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseCookie;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import com.jwtauth.dto.AuthRequest;
import com.jwtauth.dto.TokenResponse;
import com.jwtauth.entity.Employee;
import com.jwtauth.exception.AuthenticationException;
import com.jwtauth.repository.EmployeeRepository;
import com.jwtauth.repository.UserAuthRepository;
import com.jwtauth.service.GoogleOAuthService;
import com.jwtauth.service.JwtService;

import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import lombok.RequiredArgsConstructor;

/**
 * Authentication Controller.
 * 
 * Endpoints:
 * - GET  /api/auth/google           - Redirect to Google OAuth
 * - GET  /api/auth/google/callback  - Handle OAuth callback
 * - POST /api/auth/refresh          - Refresh access token
 * - POST /api/auth/logout           - Logout user
 * - GET  /api/auth/me               - Get current user info
 * 
 * @author Moti Yadav
 */
@RestController
@RequestMapping("/auth")
@RequiredArgsConstructor
public class AuthController {
    
    private static final Logger log = LoggerFactory.getLogger(AuthController.class);
    
    private final GoogleOAuthService googleOAuthService;
    private final JwtService jwtService;
    private final UserAuthRepository userAuthRepository;
    private final EmployeeRepository employeeRepository;
    
    /**
     * Initiate Google OAuth flow.
     * 
     * Redirects user to Google's consent screen.
     * 
     * GET /api/auth/google
     * 
     * @param response HTTP response for redirect
     */
    @GetMapping("/google")
    public void googleAuth(HttpServletResponse response) {
        try {
            String authUrl = googleOAuthService.getAuthorizationUrl();
            log.info("✅ Redirecting to Google OAuth: {}", authUrl);
            response.sendRedirect(authUrl);
        } catch (IllegalStateException e) {
            log.error("❌ OAuth configuration error: {}", e.getMessage());
            response.setStatus(HttpServletResponse.SC_INTERNAL_SERVER_ERROR);
            response.setContentType("application/json");
            try {
                response.getWriter().write("{\"error\":\"Configuration Error\",\"message\":\"" + 
                    e.getMessage().replace("\"", "\\\"").replace("\n", " ") + "\"}");
            } catch (IOException ioException) {
                log.error("Failed to write error response", ioException);
            }
        } catch (IOException e) {
            log.error("❌ Failed to redirect to Google", e);
            throw new AuthenticationException("Failed to initiate authentication");
        }
    }
    
    /**
     * Handle Google OAuth callback.
     * 
     * Receives authorization code from Google, exchanges it for tokens,
     * creates/updates user, and returns JWT tokens.
     * 
     * GET /api/auth/google/callback?code={code}
     * 
     * @param code Authorization code from Google
     * @param response HTTP response to set cookies
     * @return TokenResponse with JWT tokens and user info
     */
    @GetMapping("/google/callback")
    public ResponseEntity<?> googleCallback(
            @RequestParam("code") String code,
            HttpServletResponse response
    ) {
        log.info("Received OAuth callback");
        
        try {
            // Authenticate and get tokens
            TokenResponse tokenResponse = googleOAuthService.handleCallback(code);
            
            // Set tokens in HTTP-only cookies for security
            setTokenCookies(response, tokenResponse.getAccessToken(), tokenResponse.getRefreshToken());
            
            log.info("✓ Authentication successful");
            return ResponseEntity.ok(tokenResponse);
            
        } catch (AuthenticationException e) {
            log.error("❌ Authentication failed: {}", e.getMessage());
            
            // Return user-friendly HTML error page for browser
            String errorHtml = """
                <!DOCTYPE html>
                <html>
                <head>
                    <title>Authentication Error</title>
                    <style>
                        body { font-family: Arial, sans-serif; padding: 50px; background: #f5f5f5; }
                        .container { max-width: 600px; margin: 0 auto; background: white; padding: 40px; border-radius: 8px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); }
                        h1 { color: #d32f2f; margin-top: 0; }
                        .error-code { color: #666; font-size: 14px; margin-top: 20px; padding: 15px; background: #f5f5f5; border-radius: 4px; }
                        .button { display: inline-block; margin-top: 20px; padding: 12px 24px; background: #1976d2; color: white; text-decoration: none; border-radius: 4px; }
                        .button:hover { background: #1565c0; }
                    </style>
                </head>
                <body>
                    <div class="container">
                        <h1>🔒 Authentication Failed</h1>
                        <p><strong>The authentication process could not be completed.</strong></p>
                        <p>This usually happens because:</p>
                        <ul>
                            <li>The authorization code has expired</li>
                            <li>The authorization code was already used</li>
                            <li>There was an issue with the OAuth provider</li>
                        </ul>
                        <p><strong>What to do next:</strong></p>
                        <p>Please try logging in again by clicking the button below.</p>
                        <a href="/api/auth/google" class="button">🔑 Login with Google</a>
                        <div class="error-code">
                            <strong>Error details:</strong><br>
                            %s
                        </div>
                    </div>
                </body>
                </html>
                """.formatted(e.getMessage().replace("<", "&lt;").replace(">", "&gt;"));
            
            response.setContentType("text/html; charset=UTF-8");
            return ResponseEntity.status(HttpStatus.UNAUTHORIZED)
                    .body(errorHtml);
                    
        } catch (Exception e) {
            log.error("❌ Unexpected error during callback: {}", e.getMessage(), e);
            
            String errorHtml = """
                <!DOCTYPE html>
                <html>
                <head>
                    <title>Server Error</title>
                    <style>
                        body { font-family: Arial, sans-serif; padding: 50px; background: #f5f5f5; }
                        .container { max-width: 600px; margin: 0 auto; background: white; padding: 40px; border-radius: 8px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); }
                        h1 { color: #d32f2f; margin-top: 0; }
                        .button { display: inline-block; margin-top: 20px; padding: 12px 24px; background: #1976d2; color: white; text-decoration: none; border-radius: 4px; }
                        .button:hover { background: #1565c0; }
                    </style>
                </head>
                <body>
                    <div class="container">
                        <h1>⚠️ Server Error</h1>
                        <p>An unexpected error occurred during authentication.</p>
                        <p>Please try again or contact support if the problem persists.</p>
                        <a href="/api/auth/google" class="button">🔑 Try Again</a>
                    </div>
                </body>
                </html>
                """;
            
            response.setContentType("text/html; charset=UTF-8");
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR)
                    .body(errorHtml);
        }
    }
    
    /**
     * Refresh access token using refresh token.
     * 
     * POST /api/auth/refresh
     * Body: { "refreshToken": "..." }
     * 
     * Or refresh token from cookie
     * 
     * @param request HTTP request to read cookies
     * @param authRequest Request body with refresh token
     * @param response HTTP response to set cookies
     * @return New TokenResponse with refreshed tokens
     */
    @PostMapping("/refresh")
    public ResponseEntity<?> refreshToken(
            HttpServletRequest request,
            @RequestBody(required = false) AuthRequest authRequest,
            HttpServletResponse response
    ) {
        try {
            // Get refresh token from body or cookie
            String refreshToken = authRequest != null && authRequest.getRefreshToken() != null
                    ? authRequest.getRefreshToken()
                    : getRefreshTokenFromCookie(request);
            
            if (refreshToken == null || refreshToken.isEmpty()) {
                return ResponseEntity.status(HttpStatus.BAD_REQUEST)
                        .body(Map.of("error", "Refresh token required"));
            }
            
            // Validate refresh token
            try {
                jwtService.validateToken(refreshToken);
            } catch (Exception e) {
                return ResponseEntity.status(HttpStatus.UNAUTHORIZED)
                        .body(Map.of("error", "Invalid refresh token"));
            }
            
            // Extract employee ID
            String employeeId = jwtService.extractEmployeeId(refreshToken);
            if (employeeId == null) {
                return ResponseEntity.status(HttpStatus.UNAUTHORIZED)
                        .body(Map.of("error", "Invalid token"));
            }
            
            // Get employee info
            Employee employee = employeeRepository.findById(employeeId)
                    .orElseThrow(() -> new RuntimeException("Employee not found"));
            
            // Get current roles
            Integer rolesBitmask = jwtService.extractRoles(refreshToken);
            
            // Generate new tokens
            String newAccessToken = jwtService.createAccessToken(
                    employeeId,
                    employee.getEmail(),
                    employee.getName(),
                    rolesBitmask
            );
            String newRefreshToken = jwtService.createRefreshToken(employee.getId(), employee.getEmail());
            
            // Update session in database
            updateAuthSession(employeeId, newAccessToken, newRefreshToken);
            
            // Set new cookies
            setTokenCookies(response, newAccessToken, newRefreshToken);
            
            log.info("✓ Tokens refreshed for employee: {}", employeeId);
            
            Map<String, Object> responseBody = new HashMap<>();
            responseBody.put("accessToken", newAccessToken);
            responseBody.put("refreshToken", newRefreshToken);
            responseBody.put("tokenType", "Bearer");
            responseBody.put("expiresIn", 86400);
            
            return ResponseEntity.ok(responseBody);
            
        } catch (Exception e) {
            log.error("Token refresh failed", e);
            return ResponseEntity.status(HttpStatus.UNAUTHORIZED)
                    .body(Map.of("error", "Token refresh failed"));
        }
    }
    
    /**
     * Logout user.
     * 
     * Marks session as logged out and clears cookies.
     * 
     * POST /api/auth/logout
     * 
     * @param request HTTP request to read token
     * @param response HTTP response to clear cookies
     * @return Success message
     */
    @PostMapping("/logout")
    public ResponseEntity<?> logout(
            HttpServletRequest request,
            HttpServletResponse response
    ) {
        try {
            // Get access token from cookie or header
            String accessToken = getAccessTokenFromRequest(request);
            
            if (accessToken != null) {
                try {
                    jwtService.validateToken(accessToken);
                    String employeeId = jwtService.extractEmployeeId(accessToken);
                    
                    // Mark session as logged out
                    userAuthRepository.findByEmployeeId(employeeId)
                            .ifPresent(auth -> {
                                auth.setIsLoggedOut(true);
                                auth.setUpdatedAt(LocalDateTime.now());
                                userAuthRepository.save(auth);
                            });
                    
                    log.info("✓ User logged out: {}", employeeId);
                } catch (Exception e) {
                    log.debug("Token validation failed during logout");
                }
            }
            
            // Clear cookies
            clearTokenCookies(response);
            
            return ResponseEntity.ok(Map.of(
                    "message", "Logged out successfully",
                    "timestamp", LocalDateTime.now()
            ));
            
        } catch (Exception e) {
            log.error("Logout failed", e);
            return ResponseEntity.ok(Map.of("message", "Logged out"));
        }
    }
    
    /**
     * Get current authenticated user info.
     * 
     * GET /api/auth/me
     * 
     * @param request HTTP request to read token
     * @return User information
     */
    @GetMapping("/me")
    public ResponseEntity<?> getCurrentUser(HttpServletRequest request) {
        try {
            String accessToken = getAccessTokenFromRequest(request);
            
            if (accessToken == null) {
                return ResponseEntity.status(HttpStatus.UNAUTHORIZED)
                        .body(Map.of("error", "Unauthorized"));
            }
            
            try {
                jwtService.validateToken(accessToken);
            } catch (Exception e) {
                return ResponseEntity.status(HttpStatus.UNAUTHORIZED)
                        .body(Map.of("error", "Invalid or expired token"));
            }
            
            String employeeId = jwtService.extractEmployeeId(accessToken);
            Integer rolesBitmask = jwtService.extractRoles(accessToken);
            
            Map<String, Object> userInfo = new HashMap<>();
            userInfo.put("employeeId", employeeId);
            userInfo.put("rolesBitmask", rolesBitmask);
            userInfo.put("authenticated", true);
            
            return ResponseEntity.ok(userInfo);
            
        } catch (Exception e) {
            log.error("Failed to get user info", e);
            return ResponseEntity.status(HttpStatus.UNAUTHORIZED)
                    .body(Map.of("error", "Unauthorized"));
        }
    }
    
    // ========== Helper Methods ==========
    
    /**
     * Set JWT tokens in HTTP-only cookies.
     */
    private void setTokenCookies(HttpServletResponse response, String accessToken, String refreshToken) {
        // Access token cookie (1 day)
        ResponseCookie accessCookie = ResponseCookie.from("accessToken", accessToken)
                .httpOnly(true)
                .secure(false) // Set to true in production with HTTPS
                .path("/")
                .maxAge(Duration.ofDays(1))
                .sameSite("Lax")
                .build();
        
        response.addHeader(HttpHeaders.SET_COOKIE, accessCookie.toString());
        
        // Refresh token cookie (30 days)
        ResponseCookie refreshCookie = ResponseCookie.from("refreshToken", refreshToken)
                .httpOnly(true)
                .secure(false) // Set to true in production with HTTPS
                .path("/")
                .maxAge(Duration.ofDays(30))
                .sameSite("Lax")
                .build();
        
        response.addHeader(HttpHeaders.SET_COOKIE, refreshCookie.toString());
    }
    
    /**
     * Clear authentication cookies.
     */
    private void clearTokenCookies(HttpServletResponse response) {
        ResponseCookie accessCookie = ResponseCookie.from("accessToken", "")
                .httpOnly(true)
                .secure(false)
                .path("/")
                .maxAge(0)
                .build();
        
        response.addHeader(HttpHeaders.SET_COOKIE, accessCookie.toString());
        
        ResponseCookie refreshCookie = ResponseCookie.from("refreshToken", "")
                .httpOnly(true)
                .secure(false)
                .path("/")
                .maxAge(0)
                .build();
        
        response.addHeader(HttpHeaders.SET_COOKIE, refreshCookie.toString());
    }
    
    /**
     * Get access token from request (cookie or Authorization header).
     */
    private String getAccessTokenFromRequest(HttpServletRequest request) {
        // Try cookie first
        String token = getTokenFromCookie(request, "accessToken");
        if (token != null) {
            return token;
        }
        
        // Try Authorization header
        String authHeader = request.getHeader(HttpHeaders.AUTHORIZATION);
        if (authHeader != null && authHeader.startsWith("Bearer ")) {
            return authHeader.substring(7);
        }
        
        return null;
    }
    
    /**
     * Get refresh token from cookie.
     */
    private String getRefreshTokenFromCookie(HttpServletRequest request) {
        return getTokenFromCookie(request, "refreshToken");
    }
    
    /**
     * Get token from cookie by name.
     */
    private String getTokenFromCookie(HttpServletRequest request, String name) {
        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            return Arrays.stream(cookies)
                    .filter(cookie -> name.equals(cookie.getName()))
                    .findFirst()
                    .map(Cookie::getValue)
                    .orElse(null);
        }
        return null;
    }
    
    /**
     * Update authentication session with new tokens.
     */
    private void updateAuthSession(String employeeId, String accessToken, String refreshToken) {
        userAuthRepository.findByEmployeeId(employeeId)
                .ifPresent(auth -> {
                    auth.setAccessTokenHash(jwtService.hashToken(accessToken));
                    auth.setRefreshTokenHash(jwtService.hashToken(refreshToken));
                    auth.setUpdatedAt(LocalDateTime.now());
                    userAuthRepository.save(auth);
                });
    }
}
