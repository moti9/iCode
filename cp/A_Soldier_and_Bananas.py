
def solve() -> None:
    k, n, w = map(int, input().split())
    total = (w * k * (w + 1)) // 2
    print(total - n) if total >= n else print(0)



if __name__ == "__main__":
    solve()