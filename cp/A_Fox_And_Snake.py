
def solve():
    n, m = map(int, input().split())

    for i in range(n):
        if i % 2 == 0:
            row = ('#' * m)
            print(row)
        else:
            if (i // 2) % 2 == 0:
                row = ('.' * (m - 1) + '#')
                print(row)
            else:
                row = ('#' + '.' * (m - 1))
                print(row)

solve()