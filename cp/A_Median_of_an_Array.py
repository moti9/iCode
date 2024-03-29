
# def countInRange(arr, number, startIndex, endIndex):
#     count = 0
#     for i in range(startIndex, endIndex):
#         if arr[i] == number:
#             count += 1
#     return count


if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        n = int(input())
        arr = list(map(int, input().split()))
        arr.sort()
        mid = (n - 1) // 2
        res = arr[mid:].count(arr[mid])
        print(res)

        # if n & 1:
        #     print(countInRange(arr, arr[mid], mid, n))
        # else:
        #     cnt = countInRange(arr, arr[mid], mid, n)
        #     sum_num = arr[mid] + arr[mid - 1]
        #     if sum_num & 1:
        #         print(cnt)
        #     else:
        #         print(cnt + 1)