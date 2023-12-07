import numpy as np

arr1 = np.arange(1, 10).reshape((3, 3))
arr2 = np.arange(1, 10).reshape((3, 3))

print(arr1 + arr2)
print(np.add(arr1, arr2))

print(arr1 - arr2)
print(np.subtract(arr1, arr2))

print(arr1 / arr2)
print(np.divide(arr1, arr2))

print(arr1 * arr2)
print(np.multiply(arr1, arr2))

print(arr1 @ arr2)

print(arr1.dot(arr2))

print(arr1.max())

print(arr1.argmax())

print(arr1.max(axis=0))
print(arr2.max(axis=1))
