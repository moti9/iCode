def solvehere():
    rec = input()
    b, s, c = map(int, input().split())
    pb, ps, pc = map(int, input().split())
    r = int(input())
    cb = rec.count('B')
    cs = rec.count('S')
    cc = rec.count('C')
    low, high = 0, r + 102
    while low <= high:
        mid = (low + high) // 2
        r1 = max(cb * mid - b, 0)
        r2 = max(cs * mid - s, 0)
        r3 = max(cc * mid - c, 0)
        pr = r1 * pb + r2 * ps + r3 * pc
        if pr <= r:
            low = mid + 1
        else:
            high = mid - 1
    print(high)


if __name__ == "__main__":
    solvehere()
