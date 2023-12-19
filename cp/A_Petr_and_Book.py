n = int(input())
pages_per_day = list(map(int, input().split()))

remaining_pages = n
day = 0

while remaining_pages > 0:
    day = (day % 7) + 1 
    remaining_pages -= pages_per_day[day - 1]

print(day)
