t = int(input())

for _ in range(t):
    n = int(input())
    start = [int(x) for x in input()]
    finish = [int(x) for x in input()]
    pairs = list(zip(start, finish))
    add_amnt = sum(int(a < b) for a, b in pairs)
    rmv_amnt = sum(int(a > b) for a, b in pairs)
    print(max(add_amnt, rmv_amnt))