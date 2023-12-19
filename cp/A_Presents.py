def find_gift_givers(n, gift_list):
    result = [0] * n

    for i in range(n):
        result[gift_list[i] - 1] = i + 1

    return result

def main():
    n = int(input())
    gift_list = list(map(int, input().split()))

    result = find_gift_givers(n, gift_list)
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()
