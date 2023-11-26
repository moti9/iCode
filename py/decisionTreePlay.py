import pandas as pd
from sklearn import tree
from sklearn.tree import DecisionTreeClassifier
import matplotlib.pyplot as plt

df = pd.read_csv("weather_forecast.csv")

# print(df)

features = ["Outlook", "Temperature", "Humidity", "Windy"]

d = {"Sunny": 1, "Overcast": 2, "Rain": 3}
df["Outlook"] = df["Outlook"].map(d)

d = {"High": 1, "Mild": 2, "Cool": 3}
df["Temperature"] = df["Temperature"].map(d)

d = {"High": 1, "Normal": 2}
df["Humidity"] = df["Humidity"].map(d)

d = {"Strong": 1, "Weak": 2}
df["Windy"] = df["Windy"].map(d)

X = df[features]
y = df["Play"]

dtree = DecisionTreeClassifier()
dtree = dtree.fit(X, y)


tree.plot_tree(dtree, feature_names=features)
plt.show()
