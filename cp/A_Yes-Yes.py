t=int(input())

while t:
    s=input()
    # n=len(s)
    # n=(n+2)//3
    st=""
    for _ in range(21):
        st+="Yes"
    if s in st:
        print("YES")
    else :
        print("NO")
    # print(n)
    t-=1