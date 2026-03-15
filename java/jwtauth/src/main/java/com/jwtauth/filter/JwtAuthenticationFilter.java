package com.jwtauth.filter;

import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.HttpHeaders;
import jakarta.validation.constraints.NotNull;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.web.authentication.WebAuthenticationDetailsSource;
import org.springframework.stereotype.Component;
import org.springframework.web.filter.OncePerRequestFilter;

import com.jwtauth.repository.UserAuthRepository;
import com.jwtauth.service.JwtService;

import jakarta.servlet.FilterChain;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import lombok.RequiredArgsConstructor;

/**
 * JWT Authentication Filter.
 *
 * Intercepts all requests and validates JWT tokens.
 *
 * Process:
 * 1. Skip public endpoints (no authentication required)
 * 2. Extract token from cookie or Authorization header
 * 3. Validate token
 * 4. Check if session is not logged out
 * 5. Set authentication in SecurityContext
 *
 * @author Moti Yadav
 */
@Component
@RequiredArgsConstructor
public class JwtAuthenticationFilter extends OncePerRequestFilter {

    private static final Logger log = LoggerFactory.getLogger(JwtAuthenticationFilter.class);

    // Public paths that should skip JWT validation
    // Note: Paths include context-path (/api) from application.properties
    private static final List<String> PUBLIC_PATHS = List.of(
            "/api/auth/",
            "/api/health",
            "/h2-console/"
    );

    private final JwtService jwtService;
    private final UserAuthRepository userAuthRepository;

    @Override
    protected void doFilterInternal(
            @NotNull HttpServletRequest request,
            @NotNull HttpServletResponse response,
            @NotNull FilterChain filterChain
    ) throws ServletException, IOException {

        String requestPath = request.getRequestURI();

        // Skip JWT validation for public endpoints
        if (isPublicPath(requestPath)) {
            log.info("✓ Skipping JWT validation for public path: {}", requestPath);
            filterChain.doFilter(request, response);
            return;
        }

        log.info("! Processing JWT authentication for path: {}", requestPath);

        try {
            // Extract token
            String token = extractToken(request);

            if (token != null && SecurityContextHolder.getContext().getAuthentication() == null) {
                try {
                    // Validate token
                    jwtService.validateToken(token);
                    String employeeId = jwtService.extractEmployeeId(token);

                    if (employeeId != null) {
                        // Check if session is not logged out
                        boolean isLoggedOut = userAuthRepository.findByEmployeeId(employeeId)
                                .map(auth -> Boolean.TRUE.equals(auth.getIsLoggedOut()) ||
                                     !jwtService.hashToken(token).equals(auth.getAccessTokenHash()))
                                .orElse(true);

                        if (!isLoggedOut) {
                            // Extract roles
                            Integer rolesBitmask = jwtService.extractRoles(token);

                            // Create authentication
                            UsernamePasswordAuthenticationToken authentication =
                                    new UsernamePasswordAuthenticationToken(
                                            employeeId,
                                            null,
                                            getAuthorities(rolesBitmask)
                                    );

                            authentication.setDetails(
                                    new WebAuthenticationDetailsSource().buildDetails(request)
                            );

                            // Set authentication in context
                            SecurityContextHolder.getContext().setAuthentication(authentication);

                            log.debug("✓ Authenticated user: {}", employeeId);
                        } else {
                            log.debug("Session logged out for employee: {}", employeeId);
                        }
                    }
                } catch (Exception validationException) {
                    log.debug("Token validation failed: {}", validationException.getMessage());
                }
            }

        } catch (Exception e) {
            log.error("JWT authentication failed", e);
        }

        // Continue filter chain
        filterChain.doFilter(request, response);
    }

    /**
     * Extract JWT token from request.
     *
     * Tries:
     * 1. Authorization header (Bearer token)
     * 2. Cookie (accessToken)
     *
     * @param request HTTP request
     * @return JWT token or null
     */
    private String extractToken(HttpServletRequest request) {
        // Try Authorization header first
        String authHeader = request.getHeader(HttpHeaders.AUTHORIZATION);
        if (authHeader != null && authHeader.startsWith("Bearer ")) {
            return authHeader.substring(7);
        }

        // Try cookie
        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            return Arrays.stream(cookies)
                    .filter(cookie -> "accessToken".equals(cookie.getName()))
                    .findFirst()
                    .map(Cookie::getValue)
                    .orElse(null);
        }

        return null;
    }

    /**
     * Convert roles bitmask to Spring Security authorities.
     *
     * @param rolesBitmask Roles bitmask
     * @return List of authorities
     */
    private List<SimpleGrantedAuthority> getAuthorities(Integer rolesBitmask) {
        if (rolesBitmask == null) {
            return Collections.emptyList();
        }

        // For now, just create a single authority with the bitmask
        // You can expand this to create individual role authorities
        return List.of(new SimpleGrantedAuthority("ROLE_USER"));
    }

    /**
     * Check if the request path is a public endpoint that doesn't require JWT validation.
     *
     * @param requestPath The request URI
     * @return true if the path is public
     */
    private boolean isPublicPath(String requestPath) {
        return PUBLIC_PATHS.stream().anyMatch(requestPath::contains);
    }
}
