package com.jwtauth.repository;

import java.util.List;
import java.util.UUID;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import com.jwtauth.entity.EmployeeRoleACL;
import com.jwtauth.enums.RoleACL;

/**
 * EmployeeRoleACL Repository - Database access for employee role assignments.
 * 
 * This repository helps us:
 *  1. Find all roles for a specific employee
 *  2. Check if an employee has a specific role
 *  3. Add/remove roles for employees
 * 
 * @author Moti Yadav
 */
@Repository
public interface EmployeeRoleACLRepository extends JpaRepository<EmployeeRoleACL, UUID> {
    
    /**
     * Find all role assignments for a specific employee.
     * 
     * Generated query: 
     * SELECT * FROM employee_role_acl WHERE employee_id = ?
     * 
     * Use Case: When user logs in, we fetch all their roles to build the bitmask
     * 
     * Example:
     *  employee_id = "EMP001"
     *  Returns: [
     *    EmployeeRoleACL{roleAcl=HR},
     *    EmployeeRoleACL{roleAcl=ADMIN}
     *  ]
     * 
     * @param employeeId The employee ID
     * @return List of role assignments for the employee
     */
    List<EmployeeRoleACL> findByEmployeeId(String employeeId);
    
    /**
     * Check if an employee has a specific role.
     * 
     * Generated query:
     * SELECT COUNT(*) > 0 FROM employee_role_acl 
     * WHERE employee_id = ? AND role_acl = ?
     * 
     * @param employeeId The employee ID
     * @param roleAcl The role to check
     * @return true if employee has the role, false otherwise
     */
    boolean existsByEmployeeIdAndRoleAcl(String employeeId, RoleACL roleAcl);
    
    /**
     * Delete all roles for a specific employee.
     * 
     * Use Case: When removing an employee or resetting their roles
     * 
     * @param employeeId The employee ID
     */
    void deleteByEmployeeId(String employeeId);
    
    /**
     * Custom query: Get distinct employee IDs who have a specific role.
     * 
     * @Query: When method naming isn't expressive enough, write custom JPQL
     * JPQL (Java Persistence Query Language): Like SQL but for entities
     * 
     * Use Case: Find all HRs or all ADMINs
     * 
     * @param roleAcl The role to search for
     * @return List of employee IDs with that role
     */
    @Query("SELECT DISTINCT e.employeeId FROM EmployeeRoleACL e WHERE e.roleAcl = :roleAcl")
    List<String> findEmployeeIdsByRole(@Param("roleAcl") RoleACL roleAcl);
    
    /**
     * Count how many roles an employee has.
     * 
     * @param employeeId The employee ID
     * @return Number of roles assigned to the employee
     */
    long countByEmployeeId(String employeeId);
}
