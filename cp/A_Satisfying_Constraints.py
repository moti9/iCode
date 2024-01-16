


if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        cs1, cs2, cs3 = 0, 10 ** 9 + 2, []
        n = int(input())
        for _ in range(n):
            a, x = map(int, input().split())
            if a == 1:
                cs1 = max(cs1, x)
            elif a == 2:
                cs2 = min(cs2, x)
            else:
                cs3.append(x)
    
        if cs1 > cs2:
            print(0)
        else:
            cnt = cs2 - cs1 + 1
            for num in cs3:
                if cs1 <= num <= cs2:
                    cnt -= 1
            
            print(cnt)


