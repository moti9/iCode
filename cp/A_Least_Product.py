
import math

def solve():
    n = int(input())
    arr = list(map(int, input().split()))

    mult = math.prod(arr)

    if(mult <= 0):
        print(0)
    else:
        print(1)
        print("1 0")

if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        solve()