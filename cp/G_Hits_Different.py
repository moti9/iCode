import math

# function to calculate the sum of an arithmetic series
def arithmetic_sum(n, a, d):
    return n * (2 * a + (n - 1) * d) // 2

t = int(input())

for i in range(t):
    n = int(input())
    sqrt_n = math.isqrt(n)
    row = sqrt_n % 2023
    col = (n - sqrt_n**2) // (2*row) + 1
    total = 0
    for j in range(row):
        start_num = j*2023 + col
        num_cans = 2023 - j
        total += arithmetic_sum(num_cans, start_num, 1)
    print(total)
