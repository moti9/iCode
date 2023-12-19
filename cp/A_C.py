def min_operations(a, b, n):
    count = 0
    while max(a, b) <= n:
        if a < b:
            a += b
        else:
            b += a
        count += 1
    return count

def main():
    tt = int(input())
    for _ in range(tt):
        a, b, n = map(int, input().split())
        result = min_operations(a, b, n)
        print(result)

if __name__ == "__main__":
    main()
