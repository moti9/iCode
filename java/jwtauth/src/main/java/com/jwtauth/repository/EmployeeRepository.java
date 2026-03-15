package com.jwtauth.repository;

import java.util.Optional;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.jwtauth.entity.Employee;

/**
 * Employee Repository - Database access for Employee entity.
 * 
 * 📚 IMPORTANT CONCEPT: Spring Data JPA Magic!
 * 
 * By extending JpaRepository, Spring automatically provides:
 *  - save(employee) - Insert or update
 *  - findById(id) - Find by primary key
 *  - findAll() - Get all employees
 *  - delete(employee) - Delete employee
 *  - count() - Count total employees
 *  - existsById(id) - Check if employee exists
 * 
 * You can also define custom queries using method naming conventions!
 * Spring understands method names like:
 *  - findByEmail(email) → SELECT * FROM employee WHERE email = ?
 *  - findByNameContaining(name) → SELECT * FROM employee WHERE name LIKE %?%
 *  - findByStatusAndDepartment(status, dept) → WHERE status = ? AND department = ?
 * 
 * @Repository: Marks this as a repository component (Spring will scan and create)
 * JpaRepository<Employee, String>: Generic types are <Entity, ID Type>
 * 
 * @author Moti Yadav
 */
@Repository
public interface EmployeeRepository extends JpaRepository<Employee, String> {
    
    /**
     * Find an employee by email address.
     * 
     * Spring automatically generates the query:
     * SELECT * FROM employee WHERE email = ?
     * 
     * @param email The email to search for
     * @return Optional containing the employee if found, empty otherwise
     */
    Optional<Employee> findByEmail(String email);
    
    /**
     * Check if an employee exists with the given email.
     * 
     * Generated query: SELECT COUNT(*) > 0 FROM employee WHERE email = ?
     * 
     * @param email The email to check
     * @return true if employee exists, false otherwise
     */
    boolean existsByEmail(String email);
    
    /**
     * Find all employees with a specific status.
     * 
     * Generated query: SELECT * FROM employee WHERE status = ?
     * 
     * @param status The employee status (ACTIVE, INACTIVE, TERMINATED)
     * @return List of employees with the given status
     */
    java.util.List<Employee> findByStatus(Employee.EmployeeStatus status);
}
