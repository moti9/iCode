
import math

if __name__== "__main__":
    tt = int(input())
    for _ in range(tt):
        n = int(input())
        x = int(math.log2(n))
        print(2**x)