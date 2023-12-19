
def isLucky(n) -> bool:
    if n == 0:
        return False
    while n > 0:
        dig = n % 10
        if dig != 7 and dig != 4:
            return False
        
        n //= 10
    return True


def solve():
    s = input()
    cnt = s.count('7') + s.count('4')
    # print(cnt)
    print("YES") if isLucky(cnt) else print("NO")
    pass

if __name__ == "__main__":
    solve()

