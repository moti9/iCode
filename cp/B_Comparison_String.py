

if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        n = int(input())
        s = input()
        maxCnt, cnt = 1, 1
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                cnt += 1
            else:
                cnt = 1
            maxCnt = max(maxCnt, cnt)
        
        print(cnt + 1)
