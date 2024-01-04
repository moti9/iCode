def solve()->None:
    n, k = map(int, input().split())
    
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    t_pts = 0
    pts = 0
    b_max = 0
    
    for i in range(n):
        if k == i:
            # print(t_pts)
            # return
            break
        pts += a[i]
        b_max = max(b_max, b[i])
        t_pts = max(t_pts, pts + (k - i - 1) * b_max)
    
    print(t_pts)


def main():
    tt = int(input())
    
    for _ in range(tt):
        solve()


if __name__ == "__main__":
    main()
