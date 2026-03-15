package com.jwtauth.config;

import lombok.Data;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Configuration;

import java.util.List;

/**
 * Application Configuration Properties.
 * 
 * This class binds custom properties from application.properties to Java objects.
 * 
 * @ConfigurationProperties: Binds properties with prefix "app" to this class
 * @Configuration: Makes this a Spring configuration bean
 * 
 * @author Moti Yadav
 */
@Data
@Configuration
@ConfigurationProperties(prefix = "app")
public class ApplicationProperties {
    
    private Google google = new Google();
    private Jwt jwt = new Jwt();
    private Security security = new Security();
    
    /**
     * Google Configuration.
     */
    @Data
    public static class Google {
        private GoogleOAuth oauth = new GoogleOAuth();
        
        @Data
        public static class GoogleOAuth {
            private String clientId;
            private String clientSecret;
            private String redirectUri;
            private String tokenUrl;
            private String userInfoUrl;
            private String authorizationUrl;
            private String scope;
            private String accessType;
            private String prompt;
        }
    }
    
    /**
     * JWT Configuration.
     */
    @Data
    public static class Jwt {
        private int accessTokenExpiryDays = 1;
        private int refreshTokenExpiryDays = 30;
    }
    
    /**
     * Security Configuration.
     */
    @Data
    public static class Security {
        private List<String> allowedEmailDomains = List.of();
        private boolean devAuthEnabled = false;
        private List<String> developerEmails = List.of();
        private Cors cors = new Cors();
        private Cookie cookie = new Cookie();
        
        @Data
        public static class Cors {
            private List<String> allowedOrigins = List.of("http://localhost:3000", "http://localhost:8080");
            private int maxAge = 3600;
        }
        
        @Data
        public static class Cookie {
            private boolean secure = false;
            private String sameSite = "Lax";
        }
    }
}
