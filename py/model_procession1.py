import numpy as np
import pandas as pd
from sklearn.datasets import load_iris
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split

from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics

import joblib

iris = load_iris()

X = iris.data
y = iris.target

# print(f"Feature names : {iris.feature_names}")
# print(f"Target names : {iris.target_names}")
# print("First 10 rows : \n", X[:10])

#spilit the data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=1)

# print(X_train.shape)
# print(X_test.shape)
# print(y_train.shape)
# print(y_test.shape)


#train the model


classifier_knn = KNeighborsClassifier(n_neighbors=3)
classifier_knn.fit(X_train, y_train)

y_predict = classifier_knn.predict(X_test) 

accuracy = metrics.accuracy_score(y_test, y_predict)

print(f"Accuracy of the model : {accuracy}")

sample = [[5, 5, 3, 2], [2, 4, 3, 5]]
preds = classifier_knn.predict(sample)
print(preds)
pred_species = [iris.target_names[p] for p in preds] 
print("Predictions:", pred_species)


joblib.dump(classifier_knn, "iris_classifier_knn.joblib")

