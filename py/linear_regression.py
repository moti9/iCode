import numpy as np
from scipy import stats
import matplotlib.pyplot as plt

##1 - draw the data points

# x = [5, 7, 8, 7, 2, 17, 2, 9, 4, 11, 12, 9, 6]
# y = [99, 86, 87, 88, 111, 86, 103, 87, 94, 78, 77, 85, 86]

# plt.scatter(x, y)
# plt.show()

##2 - Suitable for linear regression

# x = [5, 7, 8, 7, 2, 17, 2, 9, 4, 11, 12, 9, 6]
# y = [99, 86, 87, 88, 111, 86, 103, 87, 94, 78, 77, 85, 86]
# slope, intercept, r, p, std_err = stats.linregress(x, y)


# def myfunc(x):
#     return slope * x + intercept


# mymodel = list(map(myfunc, x))

# print(myfunc(10))
# print(slope)
# print(intercept)
# print(r)
# print(p)
# print(std_err)


# plt.scatter(x, y)
# plt.plot(x, mymodel)
# plt.show()


##3- Not Suitable for linear regression(Bad fit)

x = [89, 43, 36, 36, 95, 10, 66, 34, 38, 20, 26, 29, 48, 64, 6, 5, 36, 66, 72, 40]
y = [21, 46, 3, 35, 67, 95, 53, 72, 58, 10, 26, 34, 90, 33, 38, 20, 56, 2, 47, 15]

slope, intercept, r, p, std_err = stats.linregress(x, y)


def myfunc(x):
    return slope * x + intercept


mymodel = list(map(myfunc, x))
print(r)
print(p)
print(std_err)
plt.scatter(x, y)
plt.plot(x, mymodel)
plt.show()
