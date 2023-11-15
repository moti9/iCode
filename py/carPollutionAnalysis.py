import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn import metrics

# Read the dataset
df = pd.read_csv("car_data.csv")

# Extract features (X) and target variable (y)
X = df[["Weight", "Volume"]]
y = df["CO2"]

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# Create a linear regression model
regr = LinearRegression()

# Train the model using the training sets
regr.fit(X_train, y_train)

# Make predictions on the testing set
y_pred = regr.predict(X_test)

# Evaluate the model
mse = metrics.mean_squared_error(y_test, y_pred)
r2 = metrics.r2_score(y_test, y_pred)

print(f"Mean Squared Error: {mse}")
print(f"R-squared: {r2}")

# Predict the CO2 emission of a car where the weight is 2300kg, and the volume is 1300cm3
predictedCO2 = regr.predict([[2300, 1300]])
print(f"Predicted CO2 Emission: {predictedCO2}")
