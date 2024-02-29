def find_k_values(a, b, l):
    distinct_k_values = set()

    a_powers = [a ** x for x in range(31)]
    b_powers = [b ** y for y in range(31)]

    for x in range(31):  
        for y in range(31):  
            k = l // (a_powers[x] * b_powers[y])
            if k * a_powers[x] * b_powers[y] == l and k >= 0:
                distinct_k_values.add(k)

    return len(distinct_k_values)


t = int(input())
for _ in range(t):
    a, b, l = map(int, input().strip().split())
    result = find_k_values(a, b, l)
    print(result)
