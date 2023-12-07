
def main() -> None:
    n = int(input())
    arr = list(map(int, input().strip().split()))
    
    suff = [0]*(n + 1)

    for i in range(n - 1, -1, -1):
        suff[i] = suff[i + 1] + arr[i]
    
    result = suff[0]
    for i in range(1, n):
        if suff[i] > 0:
            result += suff[i]
    
    print(result)


if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        main()