
def solve(k: int, st: str)->None:
    mp = {}

    for c in st:
        mp[c] = mp.get(c, 0) + 1
    
    res = []

    for key, val in mp.items():
        if val % k != 0:
            print(-1)
            return
        else:
            res.extend([key]* (val // k))
    ans = ''.join(res * k)
    print(ans)

    # for _ in range(k):
    #     print(ans, end="")

if __name__ == "__main__":
    k = int(input())
    st = input()
    solve(k, st)