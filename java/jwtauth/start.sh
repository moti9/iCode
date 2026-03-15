#!/bin/bash

# Load environment variables from .env file and start Spring Boot application

# Colors for output
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${YELLOW}🔧 JWT Auth Starter Script${NC}"
echo ""

# Check if .env file exists
if [ ! -f ".env" ]; then
    echo -e "${RED}❌ .env file not found!${NC}"
    echo -e "${YELLOW}📝 Creating .env from .env.example...${NC}"
    
    if [ -f ".env.example" ]; then
        cp .env.example .env
        echo -e "${GREEN}✅ .env file created${NC}"
        echo -e "${YELLOW}⚠️  Please edit .env and add your credentials${NC}"
        exit 1
    else
        echo -e "${RED}❌ .env.example not found either!${NC}"
        exit 1
    fi
fi

# Load environment variables
echo -e "${GREEN}📦 Loading environment variables from .env...${NC}"
export $(cat .env | grep -v '^#' | grep -v '^$' | xargs)

echo -e "${GREEN}✅ Environment variables loaded${NC}"
echo ""
echo "📊 Configuration:"
echo "  - Database: ${DB_URL}"
echo "  - Port: ${SERVER_PORT:-8080}"
echo "  - Google OAuth: ${GOOGLE_CLIENT_ID:0:20}..."
echo ""

# Check if PostgreSQL is required and running
if [[ "$DB_URL" == *"postgresql"* ]]; then
    echo -e "${YELLOW}🐘 PostgreSQL database detected${NC}"
    
    # Check if PostgreSQL is running (macOS)
    if command -v pg_isready &> /dev/null; then
        if pg_isready -h localhost -p 5432 > /dev/null 2>&1; then
            echo -e "${GREEN}✅ PostgreSQL is running${NC}"
        else
            echo -e "${RED}❌ PostgreSQL is not running!${NC}"
            echo -e "${YELLOW}Starting PostgreSQL...${NC}"
            
            # Try to start PostgreSQL (macOS with Homebrew)
            if command -v brew &> /dev/null; then
                brew services start postgresql@16 2>/dev/null || brew services start postgresql 2>/dev/null
                sleep 2
                
                if pg_isready -h localhost -p 5432 > /dev/null 2>&1; then
                    echo -e "${GREEN}✅ PostgreSQL started${NC}"
                else
                    echo -e "${RED}❌ Failed to start PostgreSQL${NC}"
                    echo -e "${YELLOW}💡 Please start PostgreSQL manually or check POSTGRES_SETUP.md${NC}"
                    exit 1
                fi
            else
                echo -e "${YELLOW}💡 Please start PostgreSQL manually${NC}"
                exit 1
            fi
        fi
    else
        echo -e "${YELLOW}⚠️  pg_isready not found. Assuming PostgreSQL is running...${NC}"
    fi
    echo ""
fi

# Kill any existing Spring Boot process
echo -e "${YELLOW}🧹 Cleaning up old processes...${NC}"
pkill -9 -f "spring-boot:run" 2>/dev/null
lsof -ti:${SERVER_PORT:-8080} | xargs kill -9 2>/dev/null
sleep 1

echo -e "${GREEN}✅ Cleanup complete${NC}"
echo ""

# Start application
echo -e "${GREEN}🚀 Starting Spring Boot application...${NC}"
echo ""

./mvnw spring-boot:run
