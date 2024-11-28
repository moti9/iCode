if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        a, b, n = map(int, input().split())
        tools = list(map(int, input().split()))
        time = 0
        for i in range(n):
            if b > 1:
                time += b - 1
                b = 1
            b = min(a, b + tools[i])
        print(time + b)
