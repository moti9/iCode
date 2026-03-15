package com.jwtauth.exception;

/**
 * Base exception for authentication-related errors.
 * 
 * @author Moti Yadav
 */
public class AuthenticationException extends RuntimeException {
    
    public AuthenticationException(String message) {
        super(message);
    }
    
    public AuthenticationException(String message, Throwable cause) {
        super(message, cause);
    }
}
