def solution()->None:
    n,m,k = map(int, input().split())
    jelly = list(map(int, input().split()))
    gelly = list(map(int, input().split()))
    
    min_jelly, max_jelly, sum_jelly = 1000000007,0, 0
     
    for jy in jelly:
        sum_jelly += jy
        if jy > max_jelly:
            max_jelly = jy
        if jy < min_jelly:
            min_jelly = jy
            
    min_gelly, max_gelly = 1000000007,0
    for gy in gelly:
        if gy > max_gelly:
            max_gelly = gy
        if gy < min_gelly:
            min_gelly = gy
    
    if min_jelly < max_gelly:
        sum_jelly += (max_gelly - min_jelly)
        if max_gelly > max_jelly:
            max_jelly = max_gelly
        if min_jelly < min_gelly:
            min_gelly = min_jelly
    
    if k % 2 == 0:
        sum_jelly += (min_gelly - max_jelly)
    
    print(sum_jelly)
     


def main():
    tt = int(input())
    for _ in range(tt):
        solution()

if __name__=="__main__":
    main()