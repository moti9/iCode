
def solve(n, a, adj):
    global ans
    dp = [[] for _ in range(n)]
    ans = 0
    
    def calc(y, p=-1):
        global ans
        chd = []
        for x in adj[y]:
            if x != p:
                calc(x, y)
                chd.extend(dp[x])
        
        chd.sort()
        i = 0
        while i < len(chd):
            j = i - 1
            mx1, mx2 = 0, 0
            while j + 1 < len(chd) and chd[j + 1][0] == chd[i][0]:
                j += 1
                if chd[j][1] >= mx1:
                    mx2, mx1 = mx1, chd[j][1]
                elif chd[j][1] > mx2:
                    mx2 = chd[j][1]
            
            if a[y] % chd[i][0] == 0:
                ans = max(ans, mx1 + mx2 + 1)
                dp[y].append((chd[i][0], mx1 + 1))
                while a[y] % chd[i][0] == 0:
                    a[y] //= chd[i][0]
            else:
                ans = max(ans, mx1)
            
            i = j + 1
        
        for i in range(2, int(a[y]**0.5) + 1):
            if a[y] % i == 0:
                dp[y].append((i, 1))
                ans = max(ans, 1)
                while a[y] % i == 0:
                    a[y] //= i
        
        if a[y] > 1:
            dp[y].append((a[y], 1))
            ans = max(ans, 1)
    
    calc(0)
    print(ans)


if __name__ == "__main__":
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    adj = [[] for _ in range(n)]

    for _ in range(n - 1):
        x, y = map(int, input().strip().split())
        x -= 1
        y -= 1
        adj[x].append(y)
        adj[y].append(x)

    solve(n, a, adj)


