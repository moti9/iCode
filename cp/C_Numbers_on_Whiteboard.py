import math

def solve(n: int) -> None:
    print(2)
    temp = math.ceil((n + n - 1) / 2)
    print(n - 1, n)
    for i in range(n - 2, 0, -1):
        print(i, temp)
        temp = math.ceil((temp + i) / 2)

def main():
    tt = int(input())
    for _ in range(tt):
        n = int(input())
        solve(n)

if __name__ == "__main__":
    main()
