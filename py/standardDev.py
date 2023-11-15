import numpy as np
import math

arr = [int(x) for x in input().split()]

n = len(arr)
# mean = np.mean(arr)
mean = 0.0
for ar in arr:
    mean += ar

mean /= n                                                                                                                                                                                                                                                                                                       

ans = 0.0
sum_val = 0.0
for a in arr:
    sum_val += (a - mean) ** 2

ans = math.sqrt(sum_val / n)

print(ans)
print(np.std(arr))
