import math
a, b = map(int, input().split())
if a==b:
    print("Equal")
elif b * math.log(a) > a * math.log(b):
    print("First")
else :
    print("Second")