

def solve():
    n, m = map(int, input().split())

    conv = []
    for _ in range(n):
        belt = input()
        conv.append(belt)
    
    res = 0

    for j in range(m - 1):
        if conv[n - 1][j] == 'D':
            res += 1
    
    for i in range(n - 1):
        if conv[i][m - 1] == 'R':
            res += 1

    print(res)


if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        solve()
