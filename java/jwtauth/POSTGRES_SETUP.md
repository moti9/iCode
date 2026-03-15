# PostgreSQL Setup Guide

## 📦 Installation

### macOS (Homebrew)
```bash
# Install PostgreSQL
brew install postgresql@16

# Start PostgreSQL service
brew services start postgresql@16

# Or run manually
postgres -D /opt/homebrew/var/postgresql@16
```

### Ubuntu/Debian
```bash
sudo apt update
sudo apt install postgresql postgresql-contrib
sudo systemctl start postgresql
sudo systemctl enable postgresql
```

### Windows
1. Download installer from: https://www.postgresql.org/download/windows/
2. Run installer and follow wizard
3. Set password for `postgres` user
4. Start PostgreSQL service

---

## 🗄️ Database Setup

### 1. Access PostgreSQL CLI
```bash
# macOS/Linux
psql postgres

# If authentication fails, try:
sudo -u postgres psql
```

### 2. Create Database and User
```sql
-- Create database
CREATE DATABASE jwtauth_db;

-- Create user (if needed)
CREATE USER jwtauth_user WITH ENCRYPTED PASSWORD 'your_secure_password';

-- Grant privileges
GRANT ALL PRIVILEGES ON DATABASE jwtauth_db TO jwtauth_user;

-- Connect to database
\c jwtauth_db

-- Grant schema privileges (PostgreSQL 15+)
GRANT ALL ON SCHEMA public TO jwtauth_user;

-- Exit
\q
```

### 3. Verify Connection
```bash
psql -U postgres -d jwtauth_db -h localhost -p 5432
```

---

## ⚙️ Update Environment Variables

Edit `.env` file:
```properties
DB_URL=jdbc:postgresql://localhost:5432/jwtauth_db
DB_USERNAME=postgres
DB_PASSWORD=postgres
```

**For custom user:**
```properties
DB_URL=jdbc:postgresql://localhost:5432/jwtauth_db
DB_USERNAME=jwtauth_user
DB_PASSWORD=your_secure_password
```

---

## 🚀 Run Application

### Load .env and Start
```bash
# Export environment variables (macOS/Linux)
export $(cat .env | grep -v '^#' | xargs)

# Run application
./mvnw spring-boot:run
```

### Or use Spring Boot Plugin
```bash
# Run with profile
./mvnw spring-boot:run -Dspring-boot.run.profiles=prod
```

---

## 🔍 Useful PostgreSQL Commands

```sql
-- List all databases
\l

-- Connect to database
\c jwtauth_db

-- List all tables
\dt

-- Describe table structure
\d employee

-- View data
SELECT * FROM employee;
SELECT * FROM employee_role_acl;
SELECT * FROM user_auth;

-- Drop database (careful!)
DROP DATABASE jwtauth_db;
```

---

## 🐳 Docker Setup (Alternative)

If you prefer Docker:

```bash
# Run PostgreSQL container
docker run --name jwtauth-postgres \
  -e POSTGRES_DB=jwtauth_db \
  -e POSTGRES_USER=postgres \
  -e POSTGRES_PASSWORD=postgres \
  -p 5432:5432 \
  -d postgres:16-alpine

# Stop container
docker stop jwtauth-postgres

# Start container
docker start jwtauth-postgres

# Remove container
docker rm -f jwtauth-postgres
```

---

## 🔧 Troubleshooting

### Connection Refused
```bash
# Check if PostgreSQL is running
brew services list | grep postgresql
# or
sudo systemctl status postgresql
```

### Authentication Failed
```bash
# Edit pg_hba.conf (macOS)
code /opt/homebrew/var/postgresql@16/pg_hba.conf

# Change this line:
# local   all   all   peer
# To:
local   all   all   md5

# Restart PostgreSQL
brew services restart postgresql@16
```

### Port Already in Use
```bash
# Find process using port 5432
lsof -i :5432

# Kill process
kill -9 <PID>
```

---

## 📊 Database Migration from H2 to PostgreSQL

Your application will automatically create tables on first run thanks to:
```properties
spring.jpa.hibernate.ddl-auto=update
```

**Note:** In production, use **Flyway** or **Liquibase** for schema migrations.

---

## ✅ Verification

After starting the application, check logs:
```
Hibernate: create table employee ...
Hibernate: create table employee_role_acl ...
Hibernate: create table user_auth ...
```

Access database:
```bash
psql -U postgres -d jwtauth_db
\dt
```

You should see:
- employee
- employee_role_acl
- user_auth
