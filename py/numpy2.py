import numpy as np

# One
arr = np.ones(6)
print(arr)
print(arr.dtype)

arr2 = np.ones((3, 6))
print(arr2)
print(arr2.dtype)

arr3 = np.ones((3, 4), dtype=int)
print(arr3)
print(arr3.dtype)

# Zero
arr0 = np.zeros(6)
print(arr0)
print(arr0.dtype)

arr02 = np.zeros((3, 6))
print(arr02)
print(arr02.dtype)

arr03 = np.zeros((3, 4), dtype=int)
print(arr03)
print(arr03.dtype)

# Bool
arr_b = np.zeros(6, dtype=bool)
print(arr_b)
print(arr_b.dtype)

arr_b2 = np.ones((3, 6), dtype=bool)
print(arr_b2)
print(arr_b2.dtype)

arr_b3 = np.zeros((3, 4), dtype=bool)
print(arr_b3)
print(arr_b3.dtype)

# Str
arr_str = np.zeros(6, dtype=str)
print(arr_str)
print(arr_str.dtype)

arr_str2 = np.ones((3, 6), dtype=str)
print(arr_str2)
print(arr_str2.dtype)

arr_str3 = np.zeros((3, 4), dtype=str)
print(arr_str3)
print(arr_str3.dtype)
