package com.jwtauth.util;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

import com.jwtauth.enums.RoleACL;

/**
 * Utility class for bitwise operations on RoleACL.
 * 
 * This class provides methods to:
 *  1. Convert a list of roles to a bitmask
 *  2. Convert a bitmask back to a list of roles
 *  3. Check if a user has specific role(s)
 *  4. Check if a user has ANY of the required roles (OR operation)
 *  5. Check if a user has ALL of the required roles (AND operation)
 * 
 * Bitwise Operations Used:
 *  - OR (|):  Combine roles      → 0001 | 0010 = 0011
 *  - AND (&): Check if role exists → 0011 & 0010 = 0010 (≠ 0, so true)
 * 
 * @author Moti Yadav
 * @version 1.0
 */
public class RoleACLUtils {
    
    /**
     * Private constructor to prevent instantiation.
     * This is a utility class with only static methods.
     */
    private RoleACLUtils() {
        throw new UnsupportedOperationException("Utility class cannot be instantiated");
    }
    
    /**
     * Convert a list of RoleACL to a bitmask.
     * 
     * Process:
     *  1. For each role, get its bitmask value (2^bitPosition)
     *  2. Combine all values using OR operation
     * 
     * Example:
     *  Input:  [HR, ADMIN]
     *  Step 1: HR.toBitmask() = 1 (0001)
     *  Step 2: ADMIN.toBitmask() = 2 (0010)
     *  Step 3: 0001 | 0010 = 0011 = 3
     *  Output: 3
     * 
     * @param roles List of roles to convert
     * @return The combined bitmask, or 0 if the list is null/empty
     */
    public static int roleListToBitmask(List<RoleACL> roles) {
        if (roles == null || roles.isEmpty()) {
            return 0;
        }
        
        return roles.stream()
                .mapToInt(RoleACL::toBitmask)
                .reduce(0, (a, b) -> a | b);  // Bitwise OR
    }
    
    /**
     * Convert a bitmask back to a list of RoleACL.
     * 
     * Process:
     *  1. For each RoleACL enum value
     *  2. Check if its bit is set in the bitmask
     *  3. If yes, add it to the result list
     * 
     * Example:
     *  Input:  3 (binary: 0011)
     *  Check:  0011 & 0001 (HR) = 0001 → Add HR
     *  Check:  0011 & 0010 (ADMIN) = 0010 → Add ADMIN
     *  Check:  0011 & 0100 (SUPER_HR) = 0000 → Skip
     *  Check:  0011 & 1000 (SUPER_ADMIN) = 0000 → Skip
     *  Output: [HR, ADMIN]
     * 
     * @param bitmask The bitmask to convert
     * @return List of roles represented by the bitmask
     */
    public static List<RoleACL> bitmaskToRoleList(int bitmask) {
        if (bitmask == 0) {
            return new ArrayList<>();
        }
        
        return Arrays.stream(RoleACL.values())
                .filter(role -> hasAccess(bitmask, role))
                .collect(Collectors.toList());
    }
    
    /**
     * Check if a bitmask contains a specific role.
     * 
     * Logic: Use AND operation
     *  - If (bitmask & role.toBitmask()) != 0, the role is present
     * 
     * Example 1: User has bitmask 3 (0011), check if has ADMIN (0010)
     *  0011 & 0010 = 0010 ≠ 0 → TRUE
     * 
     * Example 2: User has bitmask 3 (0011), check if has SUPER_ADMIN (1000)
     *  0011 & 1000 = 0000 = 0 → FALSE
     * 
     * @param bitmask The user's role bitmask
     * @param role The role to check for
     * @return true if the user has the role, false otherwise
     */
    public static boolean hasAccess(int bitmask, RoleACL role) {
        if (role == null) {
            return false;
        }
        return (bitmask & role.toBitmask()) != 0;
    }
    
    /**
     * Check if a bitmask contains ANY of the required roles (OR logic).
     * 
     * Use Case: "User must be HR OR ADMIN"
     * 
     * Example:
     *  User has: [ADMIN] → bitmask = 2 (0010)
     *  Required: [HR, SUPER_ADMIN] → check if has HR OR SUPER_ADMIN
     *  Check HR: 0010 & 0001 = 0000 → No
     *  Check SUPER_ADMIN: 0010 & 1000 = 0000 → No
     *  Result: FALSE (user doesn't have any of the required roles)
     * 
     * @param bitmask The user's role bitmask
     * @param requiredRoles List of roles to check (ANY match is sufficient)
     * @return true if the user has at least one of the required roles
     */
    public static boolean hasAnyAccess(int bitmask, List<RoleACL> requiredRoles) {
        if (requiredRoles == null || requiredRoles.isEmpty()) {
            return false;
        }
        
        return requiredRoles.stream()
                .anyMatch(role -> hasAccess(bitmask, role));
    }
    
    /**
     * Convenience method: Check if user has ANY of the required roles (varargs).
     * 
     * @param bitmask The user's role bitmask
     * @param requiredRoles Roles to check (variable arguments)
     * @return true if the user has at least one of the required roles
     */
    public static boolean hasAnyAccess(int bitmask, RoleACL... requiredRoles) {
        return hasAnyAccess(bitmask, Arrays.asList(requiredRoles));
    }
    
    /**
     * Check if a bitmask contains ALL of the required roles (AND logic).
     * 
     * Use Case: "User must be HR AND ADMIN"
     * 
     * Example:
     *  User has: [HR, ADMIN] → bitmask = 3 (0011)
     *  Required: [HR, ADMIN] → check if has HR AND ADMIN
     *  Check HR: 0011 & 0001 = 0001 → Yes
     *  Check ADMIN: 0011 & 0010 = 0010 → Yes
     *  Result: TRUE (user has all required roles)
     * 
     * @param bitmask The user's role bitmask
     * @param requiredRoles List of roles to check (ALL must match)
     * @return true if the user has all of the required roles
     */
    public static boolean hasAllAccess(int bitmask, List<RoleACL> requiredRoles) {
        if (requiredRoles == null || requiredRoles.isEmpty()) {
            return true;  // No requirements = always true
        }
        
        return requiredRoles.stream()
                .allMatch(role -> hasAccess(bitmask, role));
    }
    
    /**
     * Convenience method: Check if user has ALL of the required roles (varargs).
     * 
     * @param bitmask The user's role bitmask
     * @param requiredRoles Roles to check (variable arguments)
     * @return true if the user has all of the required roles
     */
    public static boolean hasAllAccess(int bitmask, RoleACL... requiredRoles) {
        return hasAllAccess(bitmask, Arrays.asList(requiredRoles));
    }
    
    /**
     * Get a human-readable representation of a bitmask.
     * 
     * @param bitmask The bitmask to describe
     * @return A string representation (e.g., "HR, ADMIN" or "No roles")
     */
    public static String describeBitmask(int bitmask) {
        if (bitmask == 0) {
            return "No roles";
        }
        
        List<RoleACL> roles = bitmaskToRoleList(bitmask);
        return roles.stream()
                .map(RoleACL::getCode)
                .collect(Collectors.joining(", "));
    }
    
    /**
     * Add a role to an existing bitmask.
     * 
     * @param bitmask Current bitmask
     * @param role Role to add
     * @return New bitmask with the role added
     */
    public static int addRole(int bitmask, RoleACL role) {
        if (role == null) {
            return bitmask;
        }
        return bitmask | role.toBitmask();
    }
    
    /**
     * Remove a role from an existing bitmask.
     * 
     * @param bitmask Current bitmask
     * @param role Role to remove
     * @return New bitmask with the role removed
     */
    public static int removeRole(int bitmask, RoleACL role) {
        if (role == null) {
            return bitmask;
        }
        return bitmask & ~role.toBitmask();  // Use NOT (~) and AND
    }
    
    /**
     * Check if a bitmask is valid (contains only defined roles).
     * 
     * @param bitmask The bitmask to validate
     * @return true if valid, false if contains undefined role bits
     */
    public static boolean isValidBitmask(int bitmask) {
        if (bitmask < 0) {
            return false;
        }
        
        // Calculate max valid bitmask (all roles combined)
        int maxBitmask = roleListToBitmask(Arrays.asList(RoleACL.values()));
        
        // Check if bitmask has any extra bits set
        return (bitmask & ~maxBitmask) == 0;
    }
}
