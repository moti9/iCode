
def main() -> None:
    x = input()

    digits = list(map(int, str(x)))

    for i in range(len(digits)):
        digits[i] = min(digits[i], 9 - digits[i])

    if digits[0] == 0:
        digits[0] = 9

    res = int(''.join(map(str, digits)))

    print(res)


if __name__ == "__main__":
    main()