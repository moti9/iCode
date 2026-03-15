package com.jwtauth.exception;

/**
 * Exception thrown when a JWT token is invalid.
 * 
 * @author Moti Yadav
 */
public class InvalidTokenException extends AuthenticationException {
    
    public InvalidTokenException(String message) {
        super(message);
    }
    
    public InvalidTokenException(String message, Throwable cause) {
        super(message, cause);
    }
}
