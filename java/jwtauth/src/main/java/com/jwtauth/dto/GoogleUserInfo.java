package com.jwtauth.dto;

import com.fasterxml.jackson.annotation.JsonProperty;

import lombok.Data;

/**
 * Google User Info Response DTO.
 * 
 * Maps the response from Google's UserInfo endpoint.
 * 
 * @author Moti Yadav
 */
@Data
public class GoogleUserInfo {
    
    @JsonProperty("sub")
    private String sub;  // Google's unique user identifier
    
    @JsonProperty("email")
    private String email;
    
    @JsonProperty("email_verified")
    private Boolean emailVerified;
    
    @JsonProperty("name")
    private String name;
    
    @JsonProperty("picture")
    private String picture;
    
    @JsonProperty("given_name")
    private String givenName;
    
    @JsonProperty("family_name")
    private String familyName;
}
