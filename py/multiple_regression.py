import pandas as pd
from sklearn import linear_model
from sklearn.preprocessing import StandardScaler

df = pd.read_csv("car_data.csv")

# # print(df)

# X = df[["Weight", "Volume"]]
# y = df["CO2"]

# # print(X)
# # print(Y)


# regr = linear_model.LinearRegression()

# regr.fit(X, y)

# # predict the CO2 emission of a car where the weight is 2300kg, and the volume is 1300cm3:
# predictedCO2 = regr.predict([[2300, 1300]])


X = df[["Weight", "Volume"]]
y = df["CO2"]

regr = linear_model.LinearRegression()
# regr.fit(X, y)

# predict the CO2 emission of a car where the weight is 2300kg, and the volume is 1300cm3:
# predictedCO2 = regr.predict([[2300, 1300]])

# print(predictedCO2)
# print(regr.coef_)

# predictedCO2 = regr.predict([[3300, 1300]])

# print(predictedCO2)

scale = StandardScaler()

scaledX = scale.fit_transform(X)
# print(scaledX)

regr.fit(scaledX, y)

scaled = scale.transform([[2300, 1.3]])

predictedCO2 = regr.predict([scaled[0]])
print(predictedCO2)
