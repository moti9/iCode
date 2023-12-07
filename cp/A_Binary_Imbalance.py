
def main() -> None:
    n = int(input())
    s = input()

    cnt0, cnt1 = 0, 0
    for c in s:
        if c == '0':
            cnt0 += 1
    
    cnt1 = n - cnt0
    
    for i in range(n - 1):
        if s[i] != s[i + 1]:
            print("YES")
            return
    
    if cnt0 > cnt1:
        print("YES")
    else:
        print("NO")

if __name__=="__main__":
    tt = int(input())
    for _ in range(tt):
        main()