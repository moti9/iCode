n=int(input())
arr=list(map(int,input().split()))
t=int(input())
Lam=[]
for i in range(t):
    Lam.append(input())
for k in range(t):
    for i in range(n):
        x=arr[i]
        arr[i]=eval(Lam[k])
print(*arr)