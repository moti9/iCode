def compute_gcd(x: int, y: int) -> int:
    while y:
        x, y = y, x % y
    return x

def main():
    a, b = map(int, input().split())
    if b % a == 0:
        print((b * b) // a)
        return
    gcd = compute_gcd(a, b)

    ans = (a * b) // gcd
    if(ans > b):
        print(ans)
    else:
        print(ans * 2)

if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        main()