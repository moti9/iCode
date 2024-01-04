def main():
    n, k = map(int, input().split())
    b = list(map(int, input().split()))

    mult = b[0]
    for i in range(1, n):
        mult *= b[i]
    
    if mult > 2023:
        print("NO")
    elif 2023 % mult == 0:
        print("YES")
        print(2023 // mult, end=" ")
        for _ in range(1, k):
            print(1, end=" ");
        print()
    else:
        print("NO")


if __name__=="__main__":
    tt = int(input())
    for _ in range(tt):
        main()