
def solve() -> None:
    s = input()
    nums = list(map(int, str(s)))
    res = []
    n = len(nums)
    for i in range(n):
        if nums[i] != 0:
            res.append(nums[i] * (10 ** (n - i - 1)))
    print(len(res))
    for r in res:
        print(r, end=" ")
    print()

if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        solve()