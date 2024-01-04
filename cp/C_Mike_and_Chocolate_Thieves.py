import math

def find_ways(n):
    ans = 0
    sz = int(math.cbrt(n))

    for i in range(2, sz + 1):
        ans += n // (i * i * i)
    return ans

def solve_here():
    m = int(input())
    low, high = 0, 10**16

    while low < high:
        mid = low + (high - low) // 2
        if find_ways(mid) < m:
            low = mid + 1
        else:
            high = mid
    
    if find_ways(low) == m:
        print(low)
    else:
        print(-1)

if __name__ == "__main__":
    ttt = 1
    # ttt = int(input())
    for _ in range(ttt):
        solve_here()
