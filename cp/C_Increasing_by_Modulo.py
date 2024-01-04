
def main():

    n, m = map(int, input().split())

    a = list(map(int, input().split()))

    low, high = 0, m

    while low < high:
        mid = (low + high) // 2
        prev = 0
        flag = False

        for i in range(n):
            lf, rf = a[i], a[i] + mid

            if (lf <= prev <= rf) or (lf <= prev + m <= rf):
                continue
            elif lf < prev:
                flag = True
                break
            else:
                prev = lf

        if flag:
            low = mid + 1
        else:
            high = mid

    print(high)

if __name__ == "__main__":
    main()
