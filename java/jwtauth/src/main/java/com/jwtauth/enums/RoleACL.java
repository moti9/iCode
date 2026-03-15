package com.jwtauth.enums;

/**
 * Role-Based Access Control (RBAC) using Bitmask
 * 
 * Each role has a unique bit position in a binary number.
 * This allows efficient storage and checking of user roles using bitwise operations.
 * 
 * Example:
 *  - User has [HR, ADMIN] → bitmask = 3 (binary: 0011)
 *  - User has [SUPER_ADMIN] → bitmask = 8 (binary: 1000)
 *  - User has all roles → bitmask = 15 (binary: 1111)
 * 
 * Checking roles:
 *  - Use bitwise AND (&) to check if a role is present
 *  - Use bitwise OR (|) to combine roles
 * 
 * @author Moti Yadav
 * @version 1.0
 */
public enum RoleACL {
    /**
     * HR role - Basic HR operations
     * Bit position: 0 → Bitmask value: 1 (2^0)
     */
    HR(0, "HR", "Human Resources"),
    
    /**
     * ADMIN role - Administrative operations
     * Bit position: 1 → Bitmask value: 2 (2^1)
     */
    ADMIN(1, "ADMIN", "Administrator"),
    
    /**
     * SUPER_HR role - Advanced HR operations
     * Bit position: 2 → Bitmask value: 4 (2^2)
     */
    SUPER_HR(2, "SUPER_HR", "Super HR"),
    
    /**
     * SUPER_ADMIN role - Full system access
     * Bit position: 3 → Bitmask value: 8 (2^3)
     */
    SUPER_ADMIN(3, "SUPER_ADMIN", "Super Administrator");
    
    private final int bitPosition;
    private final String code;
    private final String description;
    
    /**
     * Constructor
     * 
     * @param bitPosition The bit position (0-based) for this role
     * @param code The string code for this role
     * @param description Human-readable description
     */
    RoleACL(int bitPosition, String code, String description) {
        this.bitPosition = bitPosition;
        this.code = code;
        this.description = description;
    }
    
    /**
     * Get the bit position of this role.
     * 
     * @return bit position (0, 1, 2, or 3)
     */
    public int getBitPosition() {
        return bitPosition;
    }
    
    /**
     * Convert this role to its bitmask value.
     * 
     * Formula: 1 << bitPosition (equivalent to 2^bitPosition)
     * 
     * Examples:
     *  - HR:          1 << 0 = 1  (binary: 0001)
     *  - ADMIN:       1 << 1 = 2  (binary: 0010)
     *  - SUPER_HR:    1 << 2 = 4  (binary: 0100)
     *  - SUPER_ADMIN: 1 << 3 = 8  (binary: 1000)
     * 
     * @return the bitmask value for this role
     */
    public int toBitmask() {
        return 1 << bitPosition;
    }
    
    /**
     * Get the string code of this role.
     * 
     * @return role code (e.g., "HR", "ADMIN")
     */
    public String getCode() {
        return code;
    }
    
    /**
     * Get the human-readable description of this role.
     * 
     * @return role description
     */
    public String getDescription() {
        return description;
    }
    
    /**
     * Find a RoleACL by its string code.
     * 
     * @param code The role code to search for
     * @return The matching RoleACL, or null if not found
     */
    public static RoleACL fromCode(String code) {
        if (code == null || code.trim().isEmpty()) {
            return null;
        }
        
        for (RoleACL role : RoleACL.values()) {
            if (role.code.equalsIgnoreCase(code.trim())) {
                return role;
            }
        }
        
        return null;
    }
    
    @Override
    public String toString() {
        return String.format("RoleACL{code='%s', bitPosition=%d, bitmask=%d, description='%s'}", 
                           code, bitPosition, toBitmask(), description);
    }
}
