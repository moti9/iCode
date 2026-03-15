package com.jwtauth.service;

import java.security.KeyPair;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.time.LocalDateTime;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

import org.apache.commons.codec.digest.DigestUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import com.jwtauth.entity.UserAuth;
import com.jwtauth.exception.InvalidTokenException;
import com.jwtauth.exception.TokenExpiredException;
import com.jwtauth.repository.UserAuthRepository;
import com.jwtauth.util.RSAKeyUtil;

import io.jsonwebtoken.Claims;
import io.jsonwebtoken.ExpiredJwtException;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.MalformedJwtException;
import io.jsonwebtoken.UnsupportedJwtException;
import io.jsonwebtoken.security.SignatureException;
import jakarta.annotation.PostConstruct;

/**
 * JWT Service - Handles JWT token creation and validation.
 * 
 * 📚 IMPORTANT CONCEPTS:
 * 
 * 1. JWT Structure: header.payload.signature
 *    - Header: Algorithm (RS256) and type (JWT)
 *    - Payload: Claims (user data, expiry, issuer)
 *    - Signature: RSA signature using private key
 * 
 * 2. JWT Validation Steps:
 *    a) Verify signature using public key
 *    b) Check expiration time
 *    c) Verify issuer
 *    d) Check if user has logged out (database check)
 *    e) Verify token hash matches database
 * 
 * 3. Token Types:
 *    - Access Token: Short-lived (1 day), used for API calls
 *    - Refresh Token: Long-lived (30 days), used to get new access tokens
 * 
 * @author Moti Yadav
 */
@Service
public class JwtService {
    
    private static final Logger log = LoggerFactory.getLogger(JwtService.class);
    
    @Value("${app.google.oauth.client-id}")
    private String googleClientId;  // Used as issuer and audience
    
    @Value("${app.jwt.access-token-expiry-days:1}")
    private int accessTokenExpiryDays;
    
    @Value("${app.jwt.refresh-token-expiry-days:30}")
    private int refreshTokenExpiryDays;
    
    private final UserAuthRepository userAuthRepository;
    
    private PrivateKey privateKey;
    private PublicKey publicKey;
    
    public JwtService(UserAuthRepository userAuthRepository) {
        this.userAuthRepository = userAuthRepository;
    }
    
    /**
     * Initialize RSA keys after bean creation.
     * 
     * @PostConstruct: Called after dependency injection
     * 
     * In production: Load keys from secure storage (AWS Secrets Manager, Vault)
     * For development: Generate new keys on startup
     */
    @PostConstruct
    public void initKeys() {
        try {
            log.info("Initializing RSA keys for JWT...");
            
            // For development: Generate new keys
            // NEED TO DO: In production, load from secure storage (AWS Secrets Manager, Vault)
            KeyPair keyPair = RSAKeyUtil.generateKeyPair();
            this.privateKey = keyPair.getPrivate();
            this.publicKey = keyPair.getPublic();
            
            log.info("✓ JWT keys initialized successfully");
            log.info("Public Key Algorithm: {}", publicKey.getAlgorithm());
            log.info("Private Key Algorithm: {}", privateKey.getAlgorithm());
            
        } catch (NoSuchAlgorithmException e) {
            log.error("RSA algorithm not available", e);
            throw new RuntimeException("Failed to initialize JWT keys: RSA algorithm not available", e);
        } catch (RuntimeException e) {
            log.error("Failed to initialize JWT keys", e);
            throw e;
        }
    }
    
    /**
     * Create an access token.
     * 
     * Access Token Payload:
     * {
     *   "sub": "EMP001",              // Employee ID (subject)
     *   "email": "user@company.com",
     *   "name": "John Doe",
     *   "role": "EMPLOYEE",           // Fixed role name
     *   "roleACL": 3,                 // Bitmask (HR + ADMIN = 3)
     *   "aud": "google_client_id",    // Audience
     *   "iss": "google_client_id",    // Issuer
     *   "iat": 1709500000,            // Issued at
     *   "exp": 1709586400             // Expiration
     * }
     * 
     * @param employeeId Employee ID
     * @param email Employee email
     * @param name Employee name
     * @param roleACL Role bitmask
     * @return JWT access token string
     */
    public String createAccessToken(String employeeId, String email, String name, Integer roleACL) {
        log.debug("Creating access token for employee: {}", employeeId);
        
        Date now = new Date();
        Date expiry = new Date(now.getTime() + (accessTokenExpiryDays * 24L * 60 * 60 * 1000));
        
        Map<String, Object> claims = new HashMap<>();
        claims.put("email", email);
        claims.put("name", name);
        claims.put("role", "EMPLOYEE");  // Fixed role designation
        claims.put("roleACL", roleACL);
        
        String token = Jwts.builder()
                .claims(claims)
                .subject(employeeId)
                .audience().add(googleClientId).and()
                .issuer(googleClientId)
                .issuedAt(now)
                .expiration(expiry)
                .signWith(privateKey, Jwts.SIG.RS256)  // RSA-256 signature
                .compact();
        
        log.debug("✓ Access token created (expires: {})", expiry);
        return token;
    }
    
    /**
     * Create a refresh token.
     * 
     * Refresh Token Payload (minimal - only what's needed to refresh):
     * {
     *   "sub": "EMP001",
     *   "email": "user@company.com",
     *   "iss": "google_client_id",
     *   "iat": 1709500000,
     *   "exp": 1712092000
     * }
     * 
     * @param employeeId Employee ID
     * @param email Employee email
     * @return JWT refresh token string
     */
    public String createRefreshToken(String employeeId, String email) {
        log.debug("Creating refresh token for employee: {}", employeeId);
        
        Date now = new Date();
        Date expiry = new Date(now.getTime() + (refreshTokenExpiryDays * 24L * 60 * 60 * 1000));
        
        String token = Jwts.builder()
                .subject(employeeId)
                .claim("email", email)
                .issuer(googleClientId)
                .issuedAt(now)
                .expiration(expiry)
                .signWith(privateKey, Jwts.SIG.RS256)
                .compact();
        
        log.debug("✓ Refresh token created (expires: {})", expiry);
        return token;
    }
    
    /**
     * Validate a JWT token and return its claims.
     * 
     * Validation Steps:
     * 1. Verify RSA signature
     * 2. Check expiration
     * 3. Verify issuer
     * 4. Check issued time
     * 5. Query database for logout status
     * 6. Verify token hash
     * 7. Update last login time
     * 
     * @param token JWT token to validate
     * @return Claims from the token
     * @throws TokenExpiredException if token has expired
     * @throws InvalidTokenException if token is invalid
     */
    public Claims validateToken(String token) {
        try {
            log.debug("Validating JWT token...");
            
            // Step 1: Parse and verify signature
            Claims claims = Jwts.parser()
                    .verifyWith(publicKey)
                    .build()
                    .parseSignedClaims(token)
                    .getPayload();
            
            // Step 2: Check expiration
            Date expiration = claims.getExpiration();
            if (expiration.before(new Date())) {
                log.warn("Token has expired: {}", expiration);
                throw new TokenExpiredException("Token has expired");
            }
            
            // Step 3: Verify issuer
            String issuer = claims.getIssuer();
            if (!googleClientId.equals(issuer)) {
                log.warn("Invalid token issuer: {}", issuer);
                throw new InvalidTokenException("Invalid token issuer");
            }
            
            // Step 4: Check issued time
            Date issuedAt = claims.getIssuedAt();
            if (issuedAt == null || issuedAt.after(new Date()) || issuedAt.after(expiration)) {
                log.warn("Invalid token issued time: {}", issuedAt);
                throw new InvalidTokenException("Invalid token issued time");
            }
            
            // Step 5 & 6: Database validation
            String employeeId = claims.getSubject();
            validateTokenInDatabase(token, employeeId);
            
            log.debug("✓ Token validated successfully for employee: {}", employeeId);
            return claims;
            
        } catch (ExpiredJwtException e) {
            log.warn("Token expired: {}", e.getMessage());
            throw new TokenExpiredException("Token has expired");
        } catch (SignatureException e) {
            log.warn("Invalid JWT signature: {}", e.getMessage());
            throw new InvalidTokenException("Invalid JWT signature");
        } catch (MalformedJwtException e) {
            log.warn("Malformed JWT token: {}", e.getMessage());
            throw new InvalidTokenException("Malformed JWT token");
        } catch (UnsupportedJwtException e) {
            log.warn("Unsupported JWT token: {}", e.getMessage());
            throw new InvalidTokenException("Unsupported JWT token");
        } catch (IllegalArgumentException e) {
            log.warn("JWT claims string is empty: {}", e.getMessage());
            throw new InvalidTokenException("JWT claims string is empty");
        }
    }
    
    /**
     * Validate token against database records.
     * 
     * Checks:
     * 1. User exists in database
     * 2. User hasn't logged out
     * 3. Token hash matches stored hash
     * 4. Updates last login time
     * 
     * @param token JWT token
     * @param employeeId Employee ID from token
     * @throws InvalidTokenException if validation fails
     */
    private void validateTokenInDatabase(String token, String employeeId) {
        // Hash the token
        String tokenHash = DigestUtils.sha256Hex(token);
        
        // Find user auth record
        UserAuth userAuth = userAuthRepository.findByEmployeeId(employeeId)
                .orElseThrow(() -> new InvalidTokenException("User not found"));
        
        // Check if user has logged out
        if (Boolean.TRUE.equals(userAuth.getIsLoggedOut())) {
            log.warn("User has logged out: {}", employeeId);
            throw new InvalidTokenException("User has logged out");
        }
        
        // Verify token hash
        if (!tokenHash.equals(userAuth.getAccessTokenHash())) {
            log.warn("Token hash mismatch for employee: {}", employeeId);
            throw new InvalidTokenException("Invalid access token");
        }
        
        // Update last login time
        userAuth.setLastLoggedIn(LocalDateTime.now());
        userAuthRepository.save(userAuth);
        
        log.debug("✓ Token database validation passed for: {}", employeeId);
    }
    
    /**
     * Extract employee ID from token without full validation.
     * Use this when you need the employee ID but token might be expired.
     * 
     * @param token JWT token
     * @return Employee ID (subject)
     */
    public String getEmployeeIdFromToken(String token) {
        try {
            Claims claims = Jwts.parser()
                    .verifyWith(publicKey)
                    .build()
                    .parseSignedClaims(token)
                    .getPayload();
            return claims.getSubject();
        } catch (io.jsonwebtoken.JwtException e) {
            log.error("Invalid JWT token: {}", e.getMessage());
            return null;
        } catch (IllegalArgumentException e) {
            log.error("Token cannot be null or empty", e);
            return null;
        }
    }
    
    /**
     * Extract employee ID from a validated token.
     * 
     * @param token JWT token
     * @return Employee ID or null
     */
    public String extractEmployeeId(String token) {
        return getEmployeeIdFromToken(token);
    }
    
    /**
     * Extract roles bitmask from token.
     * 
     * @param token JWT token
     * @return Roles bitmask or null
     */
    public Integer extractRoles(String token) {
        try {
            Claims claims = Jwts.parser()
                    .verifyWith(publicKey)
                    .build()
                    .parseSignedClaims(token)
                    .getPayload();
            return claims.get("roleACL", Integer.class);
        } catch (SignatureException | MalformedJwtException | UnsupportedJwtException | IllegalArgumentException e) {
            log.error("Failed to extract roles from token", e);
            return null;
        }
    }
    
    /**
     * Hash a token using SHA-256.
     * Alias for generateTokenHash.
     * 
     * @param token JWT token
     * @return SHA-256 hash
     */
    public String hashToken(String token) {
        return generateTokenHash(token);
    }
    
    /**
     * Generate SHA-256 hash of a token for database storage.
     * 
     * @param token JWT token
     * @return SHA-256 hash (64 hexadecimal characters)
     */
    public String generateTokenHash(String token) {
        return DigestUtils.sha256Hex(token);
    }
    
    /**
     * Get access token expiry time in seconds.
     * 
     * @return Expiry time in seconds
     */
    public long getAccessTokenExpirySeconds() {
        return accessTokenExpiryDays * 24L * 60 * 60;
    }
    
    /**
     * Get refresh token expiry time in seconds.
     * 
     * @return Expiry time in seconds
     */
    public long getRefreshTokenExpirySeconds() {
        return refreshTokenExpiryDays * 24L * 60 * 60;
    }
}
