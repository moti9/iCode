package com.jwtauth;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

/**
 * Main Spring Boot Application.
 * 
 * @SpringBootApplication: Combines @Configuration, @EnableAutoConfiguration, @ComponentScan
 */
@SpringBootApplication
public class JwtauthApplication {

	public static void main(String[] args) {
		SpringApplication.run(JwtauthApplication.class, args);
	}

}
