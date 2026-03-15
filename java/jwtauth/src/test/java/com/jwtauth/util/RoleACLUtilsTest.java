package com.jwtauth.util;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.Test;

import com.jwtauth.enums.RoleACL;

/**
 * Unit tests for RoleACLUtils.
 * 
 * These tests demonstrate how the bitmask ACL system works.
 * Run this test to understand the concept!
 * 
 * @author Moti Yadav
 */
class RoleACLUtilsTest {
    
    @Test
    void testRoleEnumBitmaskValues() {
        System.out.println("\n=== Test 1: Individual Role Bitmask Values ===");
        
        // Each role has a unique power of 2
        assertEquals(1, RoleACL.HR.toBitmask());           // 2^0 = 1  (0001)
        assertEquals(2, RoleACL.ADMIN.toBitmask());        // 2^1 = 2  (0010)
        assertEquals(4, RoleACL.SUPER_HR.toBitmask());     // 2^2 = 4  (0100)
        assertEquals(8, RoleACL.SUPER_ADMIN.toBitmask());  // 2^3 = 8  (1000)
        
        System.out.println("✓ HR = " + RoleACL.HR.toBitmask() + " (binary: 0001)");
        System.out.println("✓ ADMIN = " + RoleACL.ADMIN.toBitmask() + " (binary: 0010)");
        System.out.println("✓ SUPER_HR = " + RoleACL.SUPER_HR.toBitmask() + " (binary: 0100)");
        System.out.println("✓ SUPER_ADMIN = " + RoleACL.SUPER_ADMIN.toBitmask() + " (binary: 1000)");
    }
    
    @Test
    void testRoleListToBitmask() {
        System.out.println("\n=== Test 2: Converting Role List to Bitmask ===");
        
        // User with HR and ADMIN roles
        List<RoleACL> roles1 = Arrays.asList(RoleACL.HR, RoleACL.ADMIN);
        int bitmask1 = RoleACLUtils.roleListToBitmask(roles1);
        assertEquals(3, bitmask1);  // 0001 | 0010 = 0011 = 3
        System.out.println("✓ [HR, ADMIN] → bitmask = " + bitmask1 + " (binary: 0011)");
        
        // User with only SUPER_ADMIN role
        List<RoleACL> roles2 = Arrays.asList(RoleACL.SUPER_ADMIN);
        int bitmask2 = RoleACLUtils.roleListToBitmask(roles2);
        assertEquals(8, bitmask2);  // 1000 = 8
        System.out.println("✓ [SUPER_ADMIN] → bitmask = " + bitmask2 + " (binary: 1000)");
        
        // User with all roles
        List<RoleACL> allRoles = Arrays.asList(RoleACL.values());
        int bitmask3 = RoleACLUtils.roleListToBitmask(allRoles);
        assertEquals(15, bitmask3);  // 0001 | 0010 | 0100 | 1000 = 1111 = 15
        System.out.println("✓ [All Roles] → bitmask = " + bitmask3 + " (binary: 1111)");
    }
    
    @Test
    void testBitmaskToRoleList() {
        System.out.println("\n=== Test 3: Converting Bitmask to Role List ===");
        
        // Bitmask 3 = HR + ADMIN
        List<RoleACL> roles1 = RoleACLUtils.bitmaskToRoleList(3);
        assertEquals(2, roles1.size());
        assertTrue(roles1.contains(RoleACL.HR));
        assertTrue(roles1.contains(RoleACL.ADMIN));
        System.out.println("✓ Bitmask 3 → " + roles1);
        
        // Bitmask 15 = All roles
        List<RoleACL> roles2 = RoleACLUtils.bitmaskToRoleList(15);
        assertEquals(4, roles2.size());
        System.out.println("✓ Bitmask 15 → " + roles2);
        
        // Bitmask 0 = No roles
        List<RoleACL> roles3 = RoleACLUtils.bitmaskToRoleList(0);
        assertEquals(0, roles3.size());
        System.out.println("✓ Bitmask 0 → " + roles3 + " (empty list)");
    }
    
    @Test
    void testHasAccess() {
        System.out.println("\n=== Test 4: Checking If User Has a Role ===");
        
        // User with bitmask 3 (HR + ADMIN)
        int userBitmask = 3;  // 0011
        
        assertTrue(RoleACLUtils.hasAccess(userBitmask, RoleACL.HR));
        System.out.println("✓ User (0011) has HR (0001): TRUE");
        
        assertTrue(RoleACLUtils.hasAccess(userBitmask, RoleACL.ADMIN));
        System.out.println("✓ User (0011) has ADMIN (0010): TRUE");
        
        assertFalse(RoleACLUtils.hasAccess(userBitmask, RoleACL.SUPER_HR));
        System.out.println("✓ User (0011) has SUPER_HR (0100): FALSE");
        
        assertFalse(RoleACLUtils.hasAccess(userBitmask, RoleACL.SUPER_ADMIN));
        System.out.println("✓ User (0011) has SUPER_ADMIN (1000): FALSE");
    }
    
    @Test
    void testHasAnyAccess() {
        System.out.println("\n=== Test 5: Checking If User Has ANY Required Role ===");
        
        // User with only ADMIN role
        int userBitmask = 2;  // 0010
        
        // Check if user has HR OR ADMIN (should be TRUE)
        boolean result1 = RoleACLUtils.hasAnyAccess(userBitmask, RoleACL.HR, RoleACL.ADMIN);
        assertTrue(result1);
        System.out.println("✓ User (ADMIN) needs [HR OR ADMIN]: TRUE");
        
        // Check if user has SUPER_HR OR SUPER_ADMIN (should be FALSE)
        boolean result2 = RoleACLUtils.hasAnyAccess(userBitmask, RoleACL.SUPER_HR, RoleACL.SUPER_ADMIN);
        assertFalse(result2);
        System.out.println("✓ User (ADMIN) needs [SUPER_HR OR SUPER_ADMIN]: FALSE");
    }
    
    @Test
    void testHasAllAccess() {
        System.out.println("\n=== Test 6: Checking If User Has ALL Required Roles ===");
        
        // User with HR and ADMIN
        int userBitmask = 3;  // 0011
        
        // Check if user has HR AND ADMIN (should be TRUE)
        boolean result1 = RoleACLUtils.hasAllAccess(userBitmask, RoleACL.HR, RoleACL.ADMIN);
        assertTrue(result1);
        System.out.println("✓ User [HR, ADMIN] needs [HR AND ADMIN]: TRUE");
        
        // Check if user has HR AND SUPER_ADMIN (should be FALSE)
        boolean result2 = RoleACLUtils.hasAllAccess(userBitmask, RoleACL.HR, RoleACL.SUPER_ADMIN);
        assertFalse(result2);
        System.out.println("✓ User [HR, ADMIN] needs [HR AND SUPER_ADMIN]: FALSE");
    }
    
    @Test
    void testAddRole() {
        System.out.println("\n=== Test 7: Adding a Role to Bitmask ===");
        
        int bitmask = 1;  // User has only HR (0001)
        System.out.println("Initial: " + RoleACLUtils.describeBitmask(bitmask));
        
        // Add ADMIN role
        bitmask = RoleACLUtils.addRole(bitmask, RoleACL.ADMIN);
        assertEquals(3, bitmask);  // 0001 | 0010 = 0011 = 3
        System.out.println("✓ After adding ADMIN: " + RoleACLUtils.describeBitmask(bitmask));
        
        // Add SUPER_ADMIN role
        bitmask = RoleACLUtils.addRole(bitmask, RoleACL.SUPER_ADMIN);
        assertEquals(11, bitmask);  // 0011 | 1000 = 1011 = 11
        System.out.println("✓ After adding SUPER_ADMIN: " + RoleACLUtils.describeBitmask(bitmask));
    }
    
    @Test
    void testRemoveRole() {
        System.out.println("\n=== Test 8: Removing a Role from Bitmask ===");
        
        int bitmask = 15;  // User has all roles (1111)
        System.out.println("Initial: " + RoleACLUtils.describeBitmask(bitmask));
        
        // Remove SUPER_ADMIN
        bitmask = RoleACLUtils.removeRole(bitmask, RoleACL.SUPER_ADMIN);
        assertEquals(7, bitmask);  // 1111 & ~1000 = 0111 = 7
        System.out.println("✓ After removing SUPER_ADMIN: " + RoleACLUtils.describeBitmask(bitmask));
        
        // Remove HR
        bitmask = RoleACLUtils.removeRole(bitmask, RoleACL.HR);
        assertEquals(6, bitmask);  // 0111 & ~0001 = 0110 = 6
        System.out.println("✓ After removing HR: " + RoleACLUtils.describeBitmask(bitmask));
    }
    
    @Test
    void testRealWorldScenario() {
        System.out.println("\n=== Test 9: Real-World Scenario ===");
        
        // Scenario: Employee Management System
        System.out.println("\n📋 Scenario: Employee wants to create a new employee record");
        
        // User's roles from database
        int userRolesBitmask = 3;  // HR + ADMIN
        System.out.println("User roles: " + RoleACLUtils.describeBitmask(userRolesBitmask));
        
        // Endpoint requirement: User must have HR OR ADMIN OR SUPER_HR OR SUPER_ADMIN
        boolean canCreateEmployee = RoleACLUtils.hasAnyAccess(
            userRolesBitmask, 
            RoleACL.HR, 
            RoleACL.ADMIN, 
            RoleACL.SUPER_HR, 
            RoleACL.SUPER_ADMIN
        );
        
        assertTrue(canCreateEmployee);
        System.out.println("✓ Can create employee: " + canCreateEmployee);
        
        // Another endpoint requirement: Only SUPER_ADMIN can delete employees
        boolean canDeleteEmployee = RoleACLUtils.hasAccess(userRolesBitmask, RoleACL.SUPER_ADMIN);
        
        assertFalse(canDeleteEmployee);
        System.out.println("✓ Can delete employee: " + canDeleteEmployee);
        System.out.println("  ↳ User doesn't have SUPER_ADMIN role!");
    }
    
    @Test
    void testDescribeBitmask() {
        System.out.println("\n=== Test 10: Human-Readable Bitmask Description ===");
        
        assertEquals("No roles", RoleACLUtils.describeBitmask(0));
        System.out.println("✓ Bitmask 0: " + RoleACLUtils.describeBitmask(0));
        
        assertEquals("HR", RoleACLUtils.describeBitmask(1));
        System.out.println("✓ Bitmask 1: " + RoleACLUtils.describeBitmask(1));
        
        assertEquals("HR, ADMIN", RoleACLUtils.describeBitmask(3));
        System.out.println("✓ Bitmask 3: " + RoleACLUtils.describeBitmask(3));
        
        assertEquals("HR, ADMIN, SUPER_HR, SUPER_ADMIN", RoleACLUtils.describeBitmask(15));
        System.out.println("✓ Bitmask 15: " + RoleACLUtils.describeBitmask(15));
    }
}
