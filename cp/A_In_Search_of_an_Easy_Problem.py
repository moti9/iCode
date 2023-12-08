
def solve():
    n = int(input())
    opn = list(map(int, input().split()))

    if opn.count(1):
        print("HARD")
    else:
        print("EASY")

if __name__ == "__main__":
    solve()