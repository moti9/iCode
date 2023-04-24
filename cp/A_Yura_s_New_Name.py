def solve(st):
    n=len(st)
    if n==1 and st=="^":
        print(1)
        return
    cnt=0
    for i in range(n):
        if st[i]=='_' and (i==0 or st[i-1]!='^'):
            cnt+=1
    if st[n-1]=='_':
        cnt+=1
    print(cnt)
    return

if __name__=="__main__":
    t=int(input())
    for _ in range(t):
        s=input()
        solve(s)