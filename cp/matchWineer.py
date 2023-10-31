def binary_search(arr, x):
    left, right = 0, len(arr)
    while left < right:
        mid = left + (right - left) // 2
        if arr[mid] <= x:
            left = mid + 1
        else:
            right = mid
    return left

def main():
    ar = list(map(int, input().split()))
    br = list(map(int, input().split()))
    ar.sort()
    ans = []

    for i in br:
        count = binary_search(ar, i)
        ans.append(count)

    print(ans)

if __name__ == "__main__":
    main()


# Example usage:
# team_a_wins = [3, 2, 4, 1, 5]
# team_b_wins = [2, 3, 2, 2, 4]

