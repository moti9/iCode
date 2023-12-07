import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score
from sklearn.preprocessing import StandardScaler

train_data = pd.read_csv("train.csv", header=None)

X = train_data.iloc[:, :-6]
y = train_data.iloc[:, -6:]

X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=0.2, random_state=42)

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_val_scaled = scaler.transform(X_val)

model = RandomForestClassifier(random_state=42)
model.fit(X_train_scaled, y_train)

y_pred = model.predict(X_val_scaled)

accuracy = accuracy_score(y_val, y_pred)
print(f"Validation Accuracy: {accuracy}")

test_data = pd.read_csv("test.csv", header=None)

X_test_scaled = scaler.transform(test_data)

test_predictions = model.predict(X_test_scaled)

pd.DataFrame(test_predictions, columns=None).to_csv("prediction.csv", header=None, index=None)
