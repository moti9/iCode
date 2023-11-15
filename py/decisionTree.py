import pandas as pd
from sklearn import tree
from sklearn.tree import DecisionTreeClassifier
import matplotlib.pyplot as plt

df = pd.read_csv("shows.csv")
d = {"UK": 0, "USA": 1, "N": 3}
df["Nationality"] = df["Nationality"].map(d)

d = {"YES": 1, "NO": 0}
df["Go"] = df["Go"].map(d)

features = ["Age", "Experience", "Rank", "Nationality"]
X = df[features]
y = df["Go"]

# print(X)
# print(y)

dtree = DecisionTreeClassifier()
dtree = dtree.fit(X, y)

print(dtree.predict([[40, 10, 7, 1]]))

tree.plot_tree(dtree, feature_names=features)
plt.show()
