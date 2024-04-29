
def check(n, nums) -> bool:
    if n == 1:
        return True
    ans = False

    for num in nums:
        if n % num == 0:
            ans |= check(n // num, nums)
        if num > n:
            break
    return ans

if __name__ == "__main__":
    nums = []
    for i in range(2, 10**5 + 1):
        num = i
        flag = True
        while num > 0:
            if num % 10 > 1:
                flag = False
                break
            num //= 10
        if flag:
            nums.append(i)
    

    tt = int(input())
    for _ in range(tt):
        n = int(input())
        if check(n, nums):
            print("YES")
        else:
            print("NO")