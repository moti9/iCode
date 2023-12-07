
def main()->None:
    n = int(input())
    mat = []
    for _ in range(n):
        row = list(map(int, input().strip().split()))
        mat.append(row)
    
    arr = [(1 << 30) - 1] * n

    for i in range(n):
        for j in range(n):
            if i != j:
                arr[i] &= mat[i][j]
                arr[j] &= mat[i][j]

    for i in range(n):
        for j in range(n):
            if i != j:
                if (arr[i] | arr[j]) != mat[i][j]:
                    print("NO")
                    return
    
    print("YES")
    for i in range(n):
        print(arr[i], end=" ")
    print()
        

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        main()