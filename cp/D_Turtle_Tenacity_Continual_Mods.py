import itertools

def possible_rearrangement(arr):
    for permutation in itertools.permutations(arr):
        result = permutation[0]
        for num in permutation[1:]:
            result %= num
            if result == 0:
                break
        else:
            return "YES"
    return "NO"

def is_power_of_2(n):
    return n != 0 and (n & (n - 1)) == 0

def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True


def solve(arr):
    cnt_p , cnt_p2 = 0, 0
    xr = 0
    for a in arr:
        cnt_p += is_prime(a)
        cnt_p2 += is_power_of_2(a)
        xr ^= a
    
    print(xr)

    if cnt_p == len(arr) or cnt_p2 == len(arr):
        return "NO"
    return "YES"


t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    print(possible_rearrangement(arr))
    # print(solve(arr))
