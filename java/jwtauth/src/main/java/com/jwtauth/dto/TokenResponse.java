package com.jwtauth.dto;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * Token Response DTO - Sent to client after successful authentication.
 * 
 * This is what the client receives after logging in via Google OAuth.
 * 
 * Example JSON response:
 * {
 *   "accessToken": "eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9...",
 *   "refreshToken": "eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9...",
 *   "tokenType": "Bearer",
 *   "expiresIn": 86400,
 *   "employee": {
 *     "id": "EMP001",
 *     "name": "John Doe",
 *     "email": "john@company.com",
 *     "roleACL": 3
 *   }
 * }
 * 
 * @author Moti Yadav
 */
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class TokenResponse {
    
    /**
     * JWT access token (used for API authentication)
     * Expires in 1 day
     */
    private String accessToken;
    
    /**
     * JWT refresh token (used to get new access token)
     * Expires in 30 days
     */
    private String refreshToken;
    
    /**
     * Token type (always "Bearer")
     * Used in Authorization header: Authorization: Bearer <token>
     */
    @Builder.Default
    private String tokenType = "Bearer";
    
    /**
     * Access token expiry time in seconds
     * 1 day = 86400 seconds
     */
    private Long expiresIn;
    
    /**
     * Employee information
     */
    private EmployeeInfo employee;
    
    /**
     * Nested class for employee information
     */
    @Data
    @Builder
    @NoArgsConstructor
    @AllArgsConstructor
    public static class EmployeeInfo {
        private String id;
        private String name;
        private String email;
        private String profilePicture;
        private Integer roleACL;  // Bitmask of user's roles
        private String roleName;  // Human-readable role names (e.g., "HR, ADMIN")
    }
}
