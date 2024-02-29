
def sum_digit(n: int) -> int:
    sm = 0
    while n > 0:
        sm += (n % 10)
        n //= 10
    return sm

if __name__ == "__main__":
    arr = [0]*(200002)
    for i in range(1, 200002):
        arr[i] = arr[i - 1] + sum_digit(i)

    tt = int(input())
    for _ in range(tt):
        n = int(input())
        print(arr[n])
