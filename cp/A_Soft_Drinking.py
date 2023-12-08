
def main():
    n, k, l, c, d, p, nl, np = map(int, input().split())

    res = min((k * l) // nl, c * d, p // np) // n
    print(res)

if __name__== "__main__":
    main()