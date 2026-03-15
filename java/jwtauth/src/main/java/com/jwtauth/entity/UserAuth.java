package com.jwtauth.entity;

import java.time.LocalDateTime;
import java.util.UUID;

import org.hibernate.annotations.CreationTimestamp;
import org.hibernate.annotations.UpdateTimestamp;
import org.hibernate.annotations.UuidGenerator;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.Index;
import jakarta.persistence.Lob;
import jakarta.persistence.Table;
import jakarta.persistence.UniqueConstraint;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * UserAuth Entity - Stores user authentication information and session data.
 * 
 * This table keeps track of:
 *  1. JWT token hashes (for validation)
 *  2. Google OAuth tokens (for refreshing access)
 *  3. Login/logout status
 *  4. Last login time
 * 
 * Security Note:
 *  - We store HASHES of JWT tokens (SHA-256), NOT the actual tokens
 *  - This prevents attackers from stealing tokens if database is compromised
 * 
 * Example row:
 *  employee_id: EMP001
 *  access_token_hash: a1b2c3d4e5f6... (SHA-256 hash)
 *  is_logged_out: false
 *  last_logged_in: 2026-03-04 10:30:00
 * 
 * @author Moti Yadav
 */
@Entity
@Table(name = "user_auth",
       uniqueConstraints = {
           @UniqueConstraint(name = "uk_user_auth_employee_id", columnNames = "employee_id")
       },
       indexes = {
           @Index(name = "idx_user_auth_employee_id", columnList = "employee_id"),
           @Index(name = "idx_user_auth_access_token_hash", columnList = "access_token_hash")
       })
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class UserAuth {
    
    /**
     * Primary Key - UUID
     */
    @Id
    @UuidGenerator
    @Column(name = "id", updatable = false, nullable = false)
    private UUID id;
    
    /**
     * Employee ID (Foreign Key to employee table)
     * UNIQUE: One employee can have only one active auth session
     */
    @Column(name = "employee_id", length = 50, unique = true, nullable = false)
    private String employeeId;
    
    /**
     * SHA-256 hash of the JWT access token
     * 
     * Why hash?
     *  - If database is compromised, attackers can't use the tokens
     *  - We hash the incoming token during validation and compare hashes
     * 
     * Length: SHA-256 produces 64 hexadecimal characters
     */
    @Column(name = "access_token_hash", length = 64, nullable = false)
    private String accessTokenHash;
    
    /**
     * SHA-256 hash of the JWT refresh token
     * Refresh tokens have longer expiry (30 days)
     */
    @Column(name = "refresh_token_hash", length = 64)
    private String refreshTokenHash;
    
    /**
     * Authentication provider (google, github, etc.)
     * Currently we only support Google OAuth
     */
    @Column(name = "auth_provider", length = 20)
    @Builder.Default
    private String authProvider = "google";
    
    /**
     * Google's access token (for calling Google APIs)
     * 
     * @Lob: Large Object - stores long text
     * This is the actual token from Google, not our JWT
     */
    @Lob
    @Column(name = "provider_access_token", columnDefinition = "TEXT")
    private String providerAccessToken;
    
    /**
     * Google's refresh token (for getting new Google access tokens)
     * More sensitive than access token - handle with care!
     */
    @Lob
    @Column(name = "provider_refresh_token", columnDefinition = "TEXT")
    private String providerRefreshToken;
    
    /**
     * When Google's access token expires
     * Used to know when to refresh the Google token
     */
    @Column(name = "provider_token_expiry")
    private LocalDateTime providerTokenExpiry;
    
    /**
     * Logout flag - if true, user has logged out
     * 
     * Why not just delete the record?
     *  - We want to keep audit trail
     *  - We can track login history
     *  - Helps detect unauthorized access attempts
     */
    @Column(name = "is_logged_out", nullable = false)
    @Builder.Default
    private Boolean isLoggedOut = false;
    
    /**
     * Last successful login time
     * Updated every time user makes an authenticated request
     */
    @Column(name = "last_logged_in")
    private LocalDateTime lastLoggedIn;
    
    /**
     * When this record was created (first login)
     */
    @CreationTimestamp
    @Column(name = "created_at", updatable = false)
    private LocalDateTime createdAt;
    
    /**
     * When this record was last updated
     */
    @UpdateTimestamp
    @Column(name = "updated_at")
    private LocalDateTime updatedAt;
}
