# 🚀 Environment Variables & PostgreSQL Migration Guide

## 📦 What Was Done

### ✅ Created Files
1. **`.env`** - Contains your actual credentials (already populated with current values)
2. **`.env.example`** - Template for other developers (commit this to git)
3. **`start.sh`** - Script to load .env and start the application
4. **`POSTGRES_SETUP.md`** - Detailed PostgreSQL installation guide

### ✅ Updated Files
1. **`application.properties`** - Now uses environment variables: `${VARIABLE_NAME:default}`
2. **`.gitignore`** - Added `.env` exclusion (keeps secrets safe!)

---

## 🔄 Quick Start Options

### Option 1: Continue with H2 (In-Memory)
```bash
# Just run the start script
./start.sh
```
The `.env` file is already configured for PostgreSQL, but will fall back to H2 if PostgreSQL isn't available.

### Option 2: Migrate to PostgreSQL

#### Step 1: Install PostgreSQL
```bash
# macOS (Homebrew)
brew install postgresql@16
brew services start postgresql@16
```

For other OS, see [POSTGRES_SETUP.md](POSTGRES_SETUP.md)

#### Step 2: Create Database
```bash
# Access PostgreSQL
psql postgres

# Run these SQL commands:
CREATE DATABASE jwtauth_db;
\q
```

#### Step 3: Verify .env Configuration
Your `.env` is already configured with PostgreSQL:
```properties
DB_URL=jdbc:postgresql://localhost:5432/jwtauth_db
DB_USERNAME=postgres
DB_PASSWORD=postgres
```

#### Step 4: Run Application
```bash
./start.sh
```

That's it! The application will automatically create tables.

---

## 📝 Environment Variables Reference

| Variable | Description | Current Value |
|----------|-------------|---------------|
| `DB_URL` | Database connection URL | `jdbc:postgresql://localhost:5432/jwtauth_db` |
| `DB_USERNAME` | Database username | `postgres` |
| `DB_PASSWORD` | Database password | `postgres` |
| `GOOGLE_CLIENT_ID` | Google OAuth Client ID | `638509788...` |
| `GOOGLE_CLIENT_SECRET` | Google OAuth Client Secret | `GOCSPX-...` |
| `JWT_ACCESS_TOKEN_EXPIRY_DAYS` | Access token validity | `1` day |
| `JWT_REFRESH_TOKEN_EXPIRY_DAYS` | Refresh token validity | `30` days |
| `ALLOWED_EMAIL_DOMAINS` | Allowed email domains for OAuth | `gmail.com,company.com` |
| `CORS_ALLOWED_ORIGINS` | CORS allowed origins | `http://localhost:3000,...` |
| `SERVER_PORT` | Server port | `8080` |

---

## 🔧 Running the Application

### Recommended: Use start.sh Script
```bash
./start.sh
```

**What it does:**
- ✅ Checks if `.env` exists
- ✅ Loads environment variables
- ✅ Checks PostgreSQL status (if configured)
- ✅ Cleans up old processes
- ✅ Starts Spring Boot application

### Manual Method (if you prefer)
```bash
# Load environment variables
export $(cat .env | grep -v '^#' | xargs)

# Run application
./mvnw spring-boot:run
```

---

## 🔍 Verify Migration

### Check Database Connection
After starting the application, look for these logs:

**H2 (In-Memory):**
```
HikariPool-1 - Starting...
HikariPool-1 - Driver class org.h2.Driver
```

**PostgreSQL:**
```
HikariPool-1 - Starting...
HikariPool-1 - Driver class org.postgresql.Driver
Hibernate: create table employee ...
```

### Check Tables Created
```bash
# Access PostgreSQL
psql -U postgres -d jwtauth_db

# List tables
\dt

# You should see:
#  employee
#  employee_role_acl
#  user_auth

# View table structure
\d employee
```

---

## 🔐 Security Best Practices

### ✅ DO:
- Keep `.env` file in `.gitignore`
- Share `.env.example` with team (no secrets)
- Use different credentials for each environment (dev/staging/prod)
- Rotate secrets regularly

### ❌ DON'T:
- Never commit `.env` to git
- Never share `.env` via Slack/email
- Never hardcode secrets in code

---

## 🐘 PostgreSQL vs H2 Comparison

| Feature | H2 (In-Memory) | PostgreSQL |
|---------|----------------|------------|
| **Data Persistence** | ❌ Lost on restart | ✅ Persisted to disk |
| **Performance** | ⚡ Very fast | 🚀 Fast (production-grade) |
| **Use Case** | Development/Testing | Production/Staging |
| **Setup** | No setup needed | Requires installation |
| **SQL Compatibility** | Good | Excellent |

---

## 🆘 Troubleshooting

### .env not found
```bash
# Copy from example
cp .env.example .env

# Edit with your credentials
nano .env
```

### PostgreSQL connection failed
```bash
# Check if running
brew services list | grep postgresql

# Start PostgreSQL
brew services start postgresql@16

# Check connection
psql -U postgres -h localhost -p 5432
```

### Environment variables not loaded
```bash
# Load manually
export $(cat .env | grep -v '^#' | xargs)

# Verify
echo $DB_URL
```

### Port 8080 already in use
```bash
# Kill existing process
lsof -ti:8080 | xargs kill -9

# Or change port in .env
SERVER_PORT=8081
```

---

## 🎯 Next Steps

1. **Test OAuth Flow**
   ```bash
   # Start application
   ./start.sh
   
   # Visit in browser
   open http://localhost:8080/api/auth/google
   ```

2. **Verify Database**
   ```bash
   # After successful OAuth login, check data
   psql -U postgres -d jwtauth_db
   SELECT * FROM employee;
   SELECT * FROM employee_role_acl;
   SELECT * FROM user_auth;
   ```

3. **Production Deployment**
   - Use production PostgreSQL credentials in `.env`
   - Set `DDL_AUTO=validate` (don't auto-create tables)
   - Use Flyway/Liquibase for schema migrations
   - Enable SSL for database connection
   - Use secrets management (AWS Secrets Manager, HashiCorp Vault)

---

## 📚 Additional Resources

- [PostgreSQL Setup Guide](POSTGRES_SETUP.md)
- [Spring Boot Environment Variables](https://docs.spring.io/spring-boot/docs/current/reference/html/features.html#features.external-config)
- [PostgreSQL Documentation](https://www.postgresql.org/docs/)

---

**✨ Your application is now environment-aware and PostgreSQL-ready!**
