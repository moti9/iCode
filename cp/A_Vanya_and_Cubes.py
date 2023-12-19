
def findLevel(n):
    level = 0
    while n >= 0:
        req = level*(level + 1) // 2
        if req <= n:
            n -= req
            level += 1
        else:
            break
    
    return level - 1

if __name__ == "__main__":
    n = int(input())
    level = findLevel(n)
    print(level)
