package com.jwtauth.config;

import java.util.List;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.method.configuration.EnableMethodSecurity;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configurers.AbstractHttpConfigurer;
import org.springframework.security.config.http.SessionCreationPolicy;
import org.springframework.security.web.SecurityFilterChain;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;
import org.springframework.web.cors.CorsConfiguration;
import org.springframework.web.cors.CorsConfigurationSource;
import org.springframework.web.cors.UrlBasedCorsConfigurationSource;

import com.jwtauth.filter.JwtAuthenticationFilter;

import lombok.RequiredArgsConstructor;

/**
 * Spring Security Configuration.
 * 
 * Configures:
 * - JWT authentication filter
 * - Public vs protected endpoints
 * - CORS policy
 * - Session management (stateless)
 * 
 * @author Moti Yadav
 */
@Configuration
@EnableWebSecurity
@EnableMethodSecurity
@RequiredArgsConstructor
public class SecurityConfig {
    
    private final JwtAuthenticationFilter jwtAuthenticationFilter;
    private final ApplicationProperties applicationProperties;
        
    @Bean
    public SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
        http
                // Disable CSRF (using JWT)
                .csrf(AbstractHttpConfigurer::disable)
                
                // Configure CORS
                .cors(cors -> cors.configurationSource(corsConfigurationSource()))
                
                // Configure authorization
                .authorizeHttpRequests(auth -> auth
                        // Public endpoints - explicitly permit all
                        // Note: requestMatchers work on servlet path (without context-path)
                        // So /api/auth/** in URL becomes /auth/** here
                        .requestMatchers("/health", "/auth/**", "/h2-console/**").permitAll()
                        
                        // All other endpoints require authentication
                        .anyRequest().authenticated()
                )
                
                // Disable sessions (stateless)
                .sessionManagement(session -> session
                        .sessionCreationPolicy(SessionCreationPolicy.STATELESS)
                )
                
                // Add exception handling for 401/403
                .exceptionHandling(exceptions -> exceptions
                        .authenticationEntryPoint((request, response, authException) -> {
                            response.setStatus(401);
                            response.setContentType("application/json");
                            response.getWriter().write("{\"error\":\"Unauthorized\",\"message\":\"" + 
                                authException.getMessage() + "\"}");
                        })
                        .accessDeniedHandler((request, response, accessDeniedException) -> {
                            response.setStatus(403);
                            response.setContentType("application/json");
                            response.getWriter().write("{\"error\":\"Forbidden\",\"message\":\"" + 
                                accessDeniedException.getMessage() + "\"}");
                        })
                )
                
                // Disable form login
                .formLogin(AbstractHttpConfigurer::disable)
                
                // Disable HTTP basic
                .httpBasic(AbstractHttpConfigurer::disable)
                
                // Add JWT filter
                .addFilterBefore(jwtAuthenticationFilter, UsernamePasswordAuthenticationFilter.class)
                
                // Allow H2 console (development only)
                .headers(headers -> headers
                        .frameOptions(frameOptions -> frameOptions.sameOrigin())
                );
        
        return http.build();
    }
    
    /**
     * CORS configuration.
     * 
     * Allows requests from configured allowed origins.
     */
    @Bean
    public CorsConfigurationSource corsConfigurationSource() {
        CorsConfiguration configuration = new CorsConfiguration();
        
        // Get allowed origins from properties
        List<String> allowedOrigins = applicationProperties.getSecurity().getCors().getAllowedOrigins();
        configuration.setAllowedOrigins(allowedOrigins);
        
        // Allow common HTTP methods
        configuration.setAllowedMethods(List.of("GET", "POST", "PUT", "DELETE", "PATCH", "OPTIONS"));
        
        // Allow common headers
        configuration.setAllowedHeaders(List.of("*"));
        
        // Allow credentials (cookies)
        configuration.setAllowCredentials(true);
        
        // Expose authorization header
        configuration.setExposedHeaders(List.of("Authorization"));
        
        // Cache preflight requests for 1 hour
        configuration.setMaxAge(3600L);
        
        UrlBasedCorsConfigurationSource source = new UrlBasedCorsConfigurationSource();
        source.registerCorsConfiguration("/**", configuration);
        
        return source;
    }
}
