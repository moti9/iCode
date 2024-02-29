def find_smallest_value(a: int, b: int, r: int)-> int:

        if a > b:
            a, b = b, a

        x = 0
        diff_bit = False

        for j in range(64, -1, -1):
            bit_a = (a >> j) & 1
            bit_b = (b >> j) & 1

            if bit_a != bit_b:
                if diff_bit:
                    if not bit_a and x + (1 << j) <= r:
                        x += (1 << j)
                        a ^= (1 << j)
                        b ^= (1 << j)
                else:
                    diff_bit = True

        return b - a

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        a, b, r = map(int, input().split())
        result = find_smallest_value(a, b, r)
        print(result)
