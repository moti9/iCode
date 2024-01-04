t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    ans = []
    i = n - 1

    while i >= 0:
        if s[i] in {'a', 'e'}:
            ans.extend([s[i], s[i - 1], '.'])
            i -= 2
        else:
            ans.extend([s[i], s[i - 1], s[i - 2], '.'])
            i -= 3

    result = ''.join(ans[:-1][::-1]) 
    print(result)
