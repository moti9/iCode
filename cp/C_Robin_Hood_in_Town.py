import sys
input = lambda: sys.stdin.readline().rstrip('\r\n')
sint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################
if __name__ == "__main__":
    tt = sint()
    for _ in range(tt):
        n = sint()
        arr = aint()

        if n < 3:
            print(-1)
            continue

        _sum = sum(arr)
        arr.sort()

        k = n // 2

        x = 2 * n * arr[k] - _sum + 1
        print(max(0, x))