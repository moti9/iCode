import joblib
from sklearn.datasets import load_iris

iris = load_iris()

model = joblib.load("iris_classifier_knn.joblib")

samples = [[5, 5, 3, 2], [2, 4, 3, 5]]

# Make predictions
predicts = [iris.target_names[model.predict([sam])[0]] for sam in samples]

print(predicts)

