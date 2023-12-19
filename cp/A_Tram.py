
def solve() -> None:
    n = int(input())
    res, temp = 0, 0
    for _ in range(n):
        a, b = map(int, input().split())
        temp -= a
        temp += b
        res = max(res, temp)
    
    print(res)



if __name__ == "__main__":
    solve()