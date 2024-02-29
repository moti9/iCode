if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        n = int(input())
        s = input()
        ans = 0
        for i in range(n):
            ans += (s[i] == '@')
            if s[i] == '*' and s[i - 1] == '*':
                break
        
        print(ans)