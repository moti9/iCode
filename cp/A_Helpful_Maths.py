def solve() -> None:
    s = list(map(int, input().split('+')))
    s.sort()
    s = list(map(str, s))
    print('+'.join(s))

if __name__ == "__main__":
    solve()
