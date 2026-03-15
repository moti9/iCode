package com.jwtauth.entity;

import java.time.LocalDateTime;
import java.util.UUID;

import org.hibernate.annotations.CreationTimestamp;
import org.hibernate.annotations.UpdateTimestamp;
import org.hibernate.annotations.UuidGenerator;

import com.jwtauth.enums.RoleACL;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.EnumType;
import jakarta.persistence.Enumerated;
import jakarta.persistence.Id;
import jakarta.persistence.Index;
import jakarta.persistence.Table;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * EmployeeRoleACL Entity - Maps employees to their assigned roles.
 * 
 * This table creates a many-to-many relationship between employees and roles.
 * One employee can have multiple roles (HR, ADMIN, etc.)
 * 
 * Example rows:
 *  id                                  | employee_id | role_acl      | created_at
 *  123e4567-e89b-12d3-a456-426614174000 | EMP001      | HR            | 2026-03-01
 *  223e4567-e89b-12d3-a456-426614174000 | EMP001      | ADMIN         | 2026-03-01
 *  323e4567-e89b-12d3-a456-426614174000 | EMP002      | SUPER_ADMIN   | 2026-03-02
 * 
 * @author Moti Yadav
 */
@Entity
@Table(name = "employee_role_acl", 
       indexes = {
           @Index(name = "idx_employee_role_acl_employee_id", columnList = "employee_id")
       },
       uniqueConstraints = {
           @jakarta.persistence.UniqueConstraint(name = "uk_employee_role", columnNames = {"employee_id", "role_acl"})
       })
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class EmployeeRoleACL {
    
    /**
     * Primary Key - UUID (Universally Unique Identifier)
     * 
     * @UuidGenerator: Automatically generate UUID values
     */
    @Id
    @UuidGenerator
    @Column(name = "id", updatable = false, nullable = false)
    private UUID id;
    
    /**
     * Employee ID (Foreign Key to employee table)
     * 
     * IMPORTANT: We store the employee_id as a String, not a direct relationship.
     * This gives us flexibility in case we need to decouple services later.
     */
    @Column(name = "employee_id", length = 50, nullable = false)
    private String employeeId;
    
    /**
     * Role assigned to the employee
     * 
     * Stored as STRING in database: "HR", "ADMIN", "SUPER_HR", "SUPER_ADMIN"
     * 
     * @Enumerated(EnumType.STRING): Store enum name instead of ordinal
     */
    @Enumerated(EnumType.STRING)
    @Column(name = "role_acl", length = 20, nullable = false)
    private RoleACL roleAcl;
    
    /**
     * When this role was assigned
     */
    @CreationTimestamp
    @Column(name = "created_at", updatable = false)
    private LocalDateTime createdAt;
    
    /**
     * When this role assignment was last updated
     */
    @UpdateTimestamp
    @Column(name = "updated_at")
    private LocalDateTime updatedAt;
    
    /**
     * Who assigned this role
     */
    @Column(name = "created_by", length = 50)
    private String createdBy;
    
    /**
     * Who last modified this role assignment
     */
    @Column(name = "updated_by", length = 50)
    private String updatedBy;
}
