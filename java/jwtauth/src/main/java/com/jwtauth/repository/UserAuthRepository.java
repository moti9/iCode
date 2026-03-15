package com.jwtauth.repository;

import java.util.Optional;
import java.util.UUID;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import com.jwtauth.entity.UserAuth;

/**
 * UserAuth Repository - Database access for user authentication data.
 * 
 * This is a critical security component that handles:
 *  1. Token validation (checking token hashes)
 *  2. Session management (login/logout status)
 *  3. OAuth token storage
 * 
 * @author Moti Yadav
 */
@Repository
public interface UserAuthRepository extends JpaRepository<UserAuth, UUID> {
    
    /**
     * Find user auth record by employee ID.
     * 
     * Use Case: When user logs in or we need to validate their session
     * 
     * @param employeeId The employee ID
     * @return Optional containing UserAuth if found
     */
    Optional<UserAuth> findByEmployeeId(String employeeId);
    
    /**
     * Find user auth record by access token hash.
     * 
     * Use Case: During JWT validation, we:
     *  1. Hash the incoming token (SHA-256)
     *  2. Look up this hash in the database
     *  3. Verify the user hasn't logged out
     * 
     * This is faster than finding by employee ID and then checking hash
     * (thanks to the index on access_token_hash)
     * 
     * @param accessTokenHash SHA-256 hash of the JWT token
     * @return Optional containing UserAuth if found
     */
    Optional<UserAuth> findByAccessTokenHash(String accessTokenHash);
    
    /**
     * Find user auth record by refresh token hash.
     * 
     * Use Case: When user tries to refresh their access token
     * 
     * @param refreshTokenHash SHA-256 hash of the refresh token
     * @return Optional containing UserAuth if found
     */
    Optional<UserAuth> findByRefreshTokenHash(String refreshTokenHash);
    
    /**
     * Check if a user auth record exists for an employee.
     * 
     * @param employeeId The employee ID
     * @return true if record exists, false otherwise
     */
    boolean existsByEmployeeId(String employeeId);
    
    /**
     * Custom query: Mark user as logged out.
     * 
     * @Modifying: Tells Spring this query modifies data (UPDATE/DELETE)
     * @Query: Custom JPQL update query
     * 
     * Use Case: When user clicks logout:
     *  1. Set is_logged_out = true
     *  2. JWT validation will reject tokens for logged out users
     * 
     * Why not delete the record?
     *  - Keep audit trail of login/logout history
     *  - Can implement "logout from all devices" feature
     *  - Helps detect security breaches
     * 
     * @param employeeId The employee ID
     * @return Number of records updated (should be 1)
     */
    @Modifying
    @Query("UPDATE UserAuth u SET u.isLoggedOut = true WHERE u.employeeId = :employeeId")
    int markAsLoggedOut(@Param("employeeId") String employeeId);
    
    /**
     * Delete user auth record by employee ID.
     * 
     * Use Case: Complete session cleanup or user deletion
     * 
     * @param employeeId The employee ID
     */
    void deleteByEmployeeId(String employeeId);
    
    /**
     * Find all active (not logged out) sessions.
     * 
     * Use Case: Admin dashboard showing active users
     * 
     * @return List of UserAuth records where isLoggedOut = false
     */
    @Query("SELECT u FROM UserAuth u WHERE u.isLoggedOut = false")
    java.util.List<UserAuth> findAllActiveSessions();
    
    /**
     * Count active sessions.
     * 
     * @return Number of users currently logged in
     */
    @Query("SELECT COUNT(u) FROM UserAuth u WHERE u.isLoggedOut = false")
    long countActiveSessions();
}
