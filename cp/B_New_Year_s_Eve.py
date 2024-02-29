def max_xor_sum(n, k):
    if k == 1:
        return n
    else:
        p = 1
        while (p << 1) <= n:
            p <<= 1
        return (1 << (p.bit_length())) - 1
    
if __name__ == "__main__":
    n, k = map(int, input().split())
    print(max_xor_sum(n, k))
