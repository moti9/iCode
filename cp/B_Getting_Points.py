def main() -> None:
    n, p, l, t = map(int, input().split())

    low, high = 1, n
    req_day = 0

    while low <= high:  
        mid = low + (high - low) // 2

        no_task = (mid + 6) // 7
        no_lesson = mid

        points = (no_task * t * 2) + (no_lesson * l)

        if points >= p:
            req_day = mid
            high = mid - 1
        else:
            low = mid + 1

    print(n - req_day)


if __name__ == "__main__":
    tc = int(input())
    for _ in range(tc):
        main()
