
def findCipherText(n, st):
    ind = 0
    add = 1
    res = ""
    while ind < n:
        res += st[ind]
        ind += add
        add += 1
    
    return res

if __name__ == "__main__":
    n = int(input())
    st = input()
    res = findCipherText(n, st)
    print(res)