import numpy as np

# arange(start, end, steps)
arr1 = np.arange(1, 7)
print(arr1)

arr2 = np.arange(1, 13, 2)
print(arr2)


# linspace
arr3 = np.linspace(1, 6, 4)
print(arr3)

# reshape
arr4 = arr1.reshape(2, 3)
print(arr4)
arr5 = arr1.reshape(
    6,
)
print(arr5)
arr6 = arr1.reshape(1, 2, 3)
print(arr6)


# ravel- Multi-D to Linear-D
print(arr6.ravel())

# flatten
print(arr6.flatten())

# Transpoze- row to column
print(arr6.transpose())
print(arr6.T)
