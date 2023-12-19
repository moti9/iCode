def findNumberOfOps(digits):
    n = len(digits)
    start, end = 0, n - 1
    while start < n and digits[start] == '0':
        start += 1
    while end >= 0 and digits[end] == '0':
        end -= 1

    cnt = 0
    while start < end:
        if digits[start] == '0':
            cnt += 1
        if digits[end] == '0':
            cnt += 1
        start += 1
        end -= 1
    
    if start == end and digits[start] == '0': 
        cnt += 1

    return cnt

if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        digits = input().strip()
        res = findNumberOfOps(digits)
        print(res)
