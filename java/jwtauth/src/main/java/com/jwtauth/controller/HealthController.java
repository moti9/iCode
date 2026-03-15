package com.jwtauth.controller;

import java.time.LocalDateTime;
import java.util.HashMap;
import java.util.Map;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * Health Check Controller - Verify the application is running.
 * 
 * @RestController: Combines @Controller + @ResponseBody
 * 
 * Note: Context path is set to /api in application.properties,
 * so these endpoints are accessible at:
 * - http://localhost:8080/api/health
 * - http://localhost:8080/api/
 * 
 * @author Moti Yadav
 */
@RestController
public class HealthController {
    
    /**
     * Health check endpoint.
     * 
     * Access: http://localhost:8080/api/health
     * 
     * @return Health status with timestamp
     */
    @GetMapping("/health")
    public ResponseEntity<Map<String, Object>> health() {
        Map<String, Object> response = new HashMap<>();
        response.put("status", "UP");
        response.put("message", "JWT Auth Service is running!");
        response.put("timestamp", LocalDateTime.now());
        response.put("version", "1.0.0");
        
        return ResponseEntity.ok(response);
    }
    
    /**
     * Root endpoint.
     * 
     * Access: http://localhost:8080/api/
     * 
     * @return Welcome message
     */
    @GetMapping("/")
    public ResponseEntity<Map<String, String>> root() {
        Map<String, String> response = new HashMap<>();
        response.put("message", "Welcome to JWT Authentication Service");
        response.put("documentation", "See PROJECT_STRUCTURE.md for details");
        response.put("health", "/api/health");
        response.put("h2Console", "/api/h2-console");
        
        return ResponseEntity.ok(response);
    }
}
