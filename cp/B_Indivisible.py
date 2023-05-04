t = int(input())

for _ in range(t):
    n = int(input())
    if n==1:
        print("1")
    elif n & 1:
        print("-1")
    else:
        permut=[]
        for i in range(1, (n//2)+1):
            permut.append(2*i)
            permut.append(2*i-1)
        print(*permut)
