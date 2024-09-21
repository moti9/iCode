

if __name__ == "__main__":
    tt = int(input())

    for _ in range(tt):
        n , x = map(int, input().split())
        gas = list(map(int, input().split()))

        ans = gas[0]
        for i in range(n - 1):
            ans = max(ans, gas[i + 1] - gas[i])
        ans = max(ans, 2 * (x - gas[n - 1]))

        print(ans)
        
