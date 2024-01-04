def check(a, n, h, k):
    sum_val = 0
    for i in range(1, n):
        gap = a[i] - a[i - 1]
        if gap >= k:
            sum_val += k
        else:
            sum_val += gap
    
    return sum_val + k >= h

def solve_here():
    n, h = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    low, high = 0, 10**18

    while low <= high:
        mid = low + (high - low) // 2
        if check(a, n, h, mid):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    
    print(ans)

if __name__ == "__main__":
    ttt = int(input())
    for _ in range(ttt):
        solve_here()
