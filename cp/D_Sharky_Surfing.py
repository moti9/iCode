import sys
import heapq
input = sys.stdin.readline
for _ in range(int(input())):
    n,m,L = map(int,input().split())
    EV = []
    for _ in range(n):
        EV.append((*list(map(int,input().split())),1))
    for _ in range(m):
        EV.append((*list(map(int,input().split())),0))
    EV.sort()
    k = 1
    pwr = []
    for a,b,t in EV:
        if t == 0:
            heapq.heappush(pwr,-b)
        else:
            while pwr and k < b-a + 2:
                k -= heapq.heappop(pwr)
            if k < b-a + 2:
                print(-1)
                break
    else:
        print(m-len(pwr))