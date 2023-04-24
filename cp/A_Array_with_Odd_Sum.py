t=int(input())
for _ in range(t):
    n=int(input())
    ls=[]
    ls=[int(ele) for ele in input().split()]
    sum=0;odd=0;even=0
    for ele in ls:
        sum+=ele
        if(ele%2):
            odd+=1
        else:
            even+=1
    if(sum%2==0 and (odd==0 or even==0)):
        print("NO")
    else:
        print("YES")
