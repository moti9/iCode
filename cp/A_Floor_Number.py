t=int(input())
for _ in range(t):
    n,x=map(int,input().split())
    if n<=2:
        print(1)
    else:
        fl=(n-3+x)//x
        print(fl+1)