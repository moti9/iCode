if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        n = int(input())
        arr = list(map(int, input().split()))
        # can_sort = True
        # for i in range(1, n - 1):
        #     if (arr[i - 1] > arr[i] < arr[i + 1]) or (arr[i - 1] > arr[i] > arr[i + 1]):
        #         can_sort = False
        #         break

        if arr[0] == 1:
            print("YES")
        else:
            print("NO")
