def min_penalty(n: int, s: str)->int:
    sum = 0
    for i in range(n):
        sum += (1 if s[i] == '+' else -1)
    # print(abs(sum))
    return(abs(sum))
    pass

if __name__ == "__main__":
    t = int(input())
    test_cases = []
    for _ in range(t):
        n = int(input())
        s = input()
        result = min_penalty(n, s)
        print(result)
