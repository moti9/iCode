import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import r2_score

# np.random.seed(2)

x = np.random.normal(3, 1, 100)
y = np.random.normal(150, 48, 100)


train_x = x[:80]
test_x = x[80:]

train_y = y[:80]
test_y = y[80:]


# plt.scatter(train_x, train_y)
# plt.show()

# plt.scatter(test_x, test_y)
# plt.show()

mymodel = np.poly1d(np.polyfit(train_x, train_y, 4))

myline = np.linspace(0, 6, 100)

plt.scatter(train_x, train_y)
plt.plot(myline, mymodel(myline))
plt.show()

print(r2_score(train_y, mymodel(train_x)))
print(r2_score(test_y, mymodel(test_x)))
print(mymodel(6))
