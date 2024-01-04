def solve_here():
    n, k = map(int, input().split())
    sum_val = (k * (k + 1) // 2) - 1

    if n > sum_val:
        print(-1)
        return

    ans = -1
    low, high = 0, k - 1

    while low <= high:
        mid = (low + high) // 2
        sum_val = mid * (2 * k - mid - 1) // 2

        if n - 1 <= sum_val:
            ans = mid
            high = mid - 1
        else:
            low = mid + 1

    print(ans)

if __name__ == "__main__":
    solve_here()
