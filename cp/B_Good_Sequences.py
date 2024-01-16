from math import gcd

def prime_factors(n):
    factors = set()
    while n % 2 == 0:
        factors.add(2)
        n //= 2
    for i in range(3, int(n**0.5) + 1, 2):
        while n % i == 0:
            factors.add(i)
            n //= i
    if n > 1:
        factors.add(n)
    return factors

def dp(index, prev_factors, n, a, memo):
    if index == n:
        return 0

    if (index, tuple(prev_factors)) in memo:
        return memo[(index, tuple(prev_factors))]

    current_factors = prime_factors(a[index])

    # Case 1: Start a new sequence
    result1 = 1 + dp(index + 1, current_factors, n, a, memo)

    # Case 2: Extend the current sequence
    result2 = 0
    if gcd(a[index - 1], a[index]) > 1 or current_factors.intersection(prev_factors):
        result2 = dp(index + 1, current_factors, n, a, memo)

    memo[(index, tuple(prev_factors))] = max(result1, result2)
    return memo[(index, tuple(prev_factors))]

def longest_good_sequence(n, a):
    memo = {}
    return dp(1, prime_factors(a[0]), n, a, memo)  # Start with index 1

# Example usage
n = int(input())
a = list(map(int, input().split()))
result = longest_good_sequence(n, a)
print(result)
