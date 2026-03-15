package com.jwtauth.exception;

/**
 * Exception thrown when a JWT token has expired.
 * 
 * @author Moti Yadav
 */
public class TokenExpiredException extends AuthenticationException {
    
    public TokenExpiredException(String message) {
        super(message);
    }
    
    public TokenExpiredException(String message, Throwable cause) {
        super(message, cause);
    }
}
