if __name__ == "__main__":
    tt = int(input())
    for _ in range(tt):
        n = int(input())
        arr = list(map(int, input().split()))

        mp = {}
        ans = 0
        for num in arr:
            if num not in mp or mp[num] == 0:
                ans += 1
                temp = ((1 << 31) - 1) ^ num
                mp[temp] = mp.get(temp, 0) + 1
            else:
                mp[num] -= 1
        
        print(ans)
