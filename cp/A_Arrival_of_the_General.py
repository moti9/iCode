def solve():
    n = int(input())
    nums = list(map(int, input().split()))
    maxi, mini = 0, 0
    maxh, minh = 0, 101
    for i in range(n):
        if nums[i] > maxh:
            maxi = i
            maxh = nums[i]
        if nums[i] <= minh:
            mini = i
            minh = nums[i]
    res = maxi + (n - mini - 1)
    if maxi < mini:
        print(res)
    else:
        print(res - 1)
    

if __name__ == "__main__":
    solve()
