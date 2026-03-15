# 📁 Project Structure Explained

## Package Organization

```
com.jwtauth/
├── config/          → Configuration classes (Security, CORS, JWT setup)
├── controller/      → REST API endpoints (@RestController)
├── service/         → Business logic layer
├── repository/      → Database access layer (JPA repositories)
├── entity/          → Database entities (JPA @Entity)
├── dto/             → Data Transfer Objects (request/response models)
├── enums/           → Enumerations (RoleACL, error codes)
├── util/            → Utility classes (bitmask operations, helpers)
├── filter/          → Security filters (JWT validation, headers)
├── exception/       → Custom exceptions and error handling
└── security/        → Security-related classes (UserDetails, etc.)
```

## 📚 Spring Boot Layered Architecture

### **1. Controller Layer** (API Entry Point)
- Handles HTTP requests
- Validates input (@Valid)
- Returns HTTP responses
- **Example:** `@GetMapping("/api/employees")`

### **2. Service Layer** (Business Logic)
- Contains business rules
- Orchestrates operations
- Calls repositories
- **Example:** Employee validation, ACL checks

### **3. Repository Layer** (Data Access)
- Interfaces for database operations
- Extends JpaRepository
- Spring generates implementation automatically
- **Example:** `findByEmployeeId(String id)`

### **4. Entity Layer** (Database Models)
- Maps Java objects to database tables
- Uses JPA annotations (@Entity, @Table, @Column)
- **Example:** Employee, UserAuth entities

### **5. DTO Layer** (Data Transfer)
- Objects for API requests/responses
- Decouples internal entities from external API
- **Example:** LoginRequest, TokenResponse

---

## 🔐 Security Flow Overview

```
Client Request
    ↓
[SecurityHeadersFilter] → Adds security headers
    ↓
[JwtAuthenticationFilter] → Extracts & validates JWT
    ↓
[Spring Security] → Checks @PreAuthorize
    ↓
[Controller] → Handles request
    ↓
[Service] → Business logic + ACL checks
    ↓
[Repository] → Database access
    ↓
Response back to client
```

---

## 🎯 What We'll Build (Phase by Phase)

### **Phase 1: Dependencies & Structure** ✅ COMPLETED
- Added all required Maven dependencies
- Created package structure
- Configured application.properties

### **Phase 2: ACL Bitmask System** (Next)
- Create RoleACL enum
- Implement bitmask operations
- Build utility class for role checking

### **Phase 3: Database Entities**
- Create Employee entity
- Create EmployeeRoleACL entity
- Create UserAuth entity
- Create repositories

### **Phase 4: JWT Service**
- Generate RSA key pairs
- Create JWT with RS256 signature
- Validate JWT tokens
- Token refresh logic

### **Phase 5: Google OAuth**
- Redirect to Google login
- Handle OAuth callback
- Exchange authorization code for tokens
- Extract user info from Google

### **Phase 6: Security Filters**
- JWT extraction from cookie/header
- Token validation middleware
- Security configuration
- CORS setup

### **Phase 7: Auth Controller**
- `/auth/google/signup` endpoint
- `/auth/google/oauth` callback
- `/auth/google/logout` endpoint
- `/auth/google/refreshToken` endpoint

### **Phase 8: Error Handling & Testing**
- Global exception handler
- Custom error codes
- Unit tests
- Integration tests

---

## 💡 Key Concepts You'll Learn

1. **JWT (JSON Web Tokens)**: Stateless authentication
2. **RSA-256**: Asymmetric encryption for token signing
3. **OAuth 2.0**: Third-party authentication (Google)
4. **Bitmask ACL**: Efficient role-based access control
5. **Spring Security**: Enterprise security framework
6. **JPA/Hibernate**: Object-relational mapping
7. **Dependency Injection**: Spring's core feature
8. **Filter Chain**: Request processing pipeline
9. **DTO Pattern**: Separating internal/external models
10. **Exception Handling**: Centralized error management

---

## 🚀 Next Steps

Run `mvn clean install` to download all dependencies, then we'll start building the ACL system!
