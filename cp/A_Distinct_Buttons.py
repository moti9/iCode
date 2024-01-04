def solvehere():
    n = int(input())
    dl = 0
    dr = 0
    ul = 0
    ur = 0

    for _ in range(n):
        x, y = map(int, input().split())
        if x <= 0:
            if y <= 0:
                ul = 1
            else:
                ur = 1
        else:
            if y <= 0:
                dl = 1
            else:
                dr = 1

    total_sum = dl + dr + ul + ur
    if total_sum > 2:
        print("NO")
    elif total_sum == 2:
        if (ul and dr) or (ur and dl):
            print("NO")
        else:
            print("YES")
    else:
        print("YES")

def main():
    t = int(input())
    for _ in range(t):
        solvehere()

if __name__ == "__main__":
    main()
