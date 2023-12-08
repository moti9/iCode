
def main():
    mat = []
    for _ in range(5):
        mat.append(list(map(int, input().split())))
    res = 0
    for i in range(5):
        for j in range(5):
            if mat[i][j] == 1:
                res = abs(i - 2) + abs(j - 2)
                break

    print(res)
if __name__ == "__main__":
    main()