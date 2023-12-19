
def findNumberOfCalls(n):
    same_cnt = len(n) * (len(n) + 1) // 2
    prev = (int(n[0]) - 1) * 10 + same_cnt
    return prev
    pass

if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        n = input()
        noc = findNumberOfCalls(n)
        print(noc)