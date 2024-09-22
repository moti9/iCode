

if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))

        if arr.count(k) > 0:
            print("YES")
        else:
            print("NO")