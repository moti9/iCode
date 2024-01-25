def soldier_game(n):
    prime_divisors = [0] * (n + 1)
    for i in range(2, int(n ** 0.5) + 1):
        if prime_divisors[i] == 0:
            for j in range(i * i, n + 1, i):
                if prime_divisors[j] == 0:
                    prime_divisors[j] = i

    prime_factors = [0] * (n + 1)
    for i in range(2, n + 1):
        if prime_divisors[i] == 0:
            prime_factors[i] = 1
        else:
            prime_factors[i] = prime_factors[i // prime_divisors[i]] + 1

    prefix_sums = [0] * (n + 1)
    for i in range(2, n + 1):
        prefix_sums[i] = prefix_sums[i - 1] + prime_factors[i]

    return prefix_sums

if __name__ == "__main__":
    upper_limit = 5000001

    prefix_sums = soldier_game(upper_limit)

    t = int(input())

    for _ in range(t):
        a, b = map(int, input().split())
        answer = prefix_sums[a] - prefix_sums[b]
        print(answer)
