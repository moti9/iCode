package com.jwtauth.entity;

import java.time.LocalDateTime;

import org.hibernate.annotations.CreationTimestamp;
import org.hibernate.annotations.UpdateTimestamp;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.EnumType;
import jakarta.persistence.Enumerated;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * Employee Entity - Represents an employee in the system.
 * 
 * This entity maps to the 'employee' table in the database.
 * 
 * @Entity: Marks this class as a JPA entity
 * @Table: Specifies the table name
 * @Data: Lombok annotation - auto-generates getters/setters/toString/equals/hashCode
 * @Builder: Lombok - provides builder pattern for object creation
 * @NoArgsConstructor: Lombok - generates no-args constructor (required by JPA)
 * @AllArgsConstructor: Lombok - generates constructor with all fields
 * 
 * @author Moti Yadav
 */
@Entity
@Table(name = "employee")
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class Employee {
    
    /**
     * Primary Key - Employee ID
     * 
     * @Id: Marks this field as the primary key
     * @Column: Specifies column properties (name, length, constraints)
     */
    @Id
    @Column(name = "id", length = 50, nullable = false)
    private String id;  // e.g., "EMP001"
    
    /**
     * Employee's full name
     */
    @Column(name = "name", nullable = false, length = 100)
    private String name;
    
    /**
     * Employee's email address (must be unique)
     * This is used for authentication
     */
    @Column(name = "email", unique = true, nullable = false, length = 100)
    private String email;
    
    /**
     * Employee's profile picture URL (from Google OAuth)
     */
    @Column(name = "profile_picture", length = 500)
    private String profilePicture;
    
    /**
     * Employee's phone number
     */
    @Column(name = "phone", length = 20)
    private String phone;
    
    /**
     * Employee's department
     */
    @Column(name = "department", length = 100)
    private String department;
    
    /**
     * Employee's designation/job title
     */
    @Column(name = "designation", length = 100)
    private String designation;
    
    /**
     * Employee status: ACTIVE, INACTIVE, TERMINATED
     * 
     * @Enumerated: Tells JPA how to store the enum
     * EnumType.STRING: Store as string ("ACTIVE") instead of ordinal (0, 1, 2)
     */
    @Enumerated(EnumType.STRING)
    @Column(name = "status", length = 20, nullable = false)
    @Builder.Default
    private EmployeeStatus status = EmployeeStatus.ACTIVE;
    
    /**
     * Timestamp when employee record was created
     * 
     * @CreationTimestamp: Automatically set on insert
     * updatable = false: Never update this field after creation
     */
    @CreationTimestamp
    @Column(name = "created_at", updatable = false)
    private LocalDateTime createdAt;
    
    /**
     * Timestamp when employee record was last updated
     * 
     * @UpdateTimestamp: Automatically updated on every update
     */
    @UpdateTimestamp
    @Column(name = "updated_at")
    private LocalDateTime updatedAt;
    
    /**
     * Employee ID who created this record
     */
    @Column(name = "created_by", length = 50)
    private String createdBy;
    
    /**
     * Employee ID who last updated this record
     */
    @Column(name = "updated_by", length = 50)
    private String updatedBy;
    
    /**
     * Employee status enum
     */
    public enum EmployeeStatus {
        ACTIVE,    // Can log in and use the system
        INACTIVE,  // Temporarily disabled
        TERMINATED // Permanently removed
    }
}
