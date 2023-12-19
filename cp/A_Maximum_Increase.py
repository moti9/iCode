

def solve(n, arr)->int:
    maxLen = 1
    currLen = 1

    for i in range(1, n):
        if arr[i - 1] < arr[i]:
            currLen += 1
            maxLen = max(maxLen, currLen)
        else:
            currLen = 1
    
    return maxLen

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().strip().split()))

    print(solve(n, arr))

