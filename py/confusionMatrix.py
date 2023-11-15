import numpy as np
from sklearn import metrics
import matplotlib.pyplot as plt


actual = np.random.binomial(1, 0.9, 1000)
predicted = np.random.binomial(1, 0.9, 1000)


confusion_matrix = metrics.confusion_matrix(actual, predicted)

cm_display = metrics.ConfusionMatrixDisplay(
    confusion_matrix=confusion_matrix, display_labels=[True, False]
)

cm_display.plot()
plt.show()


accuracy = metrics.accuracy_score(actual, predicted)
print(accuracy)

precision = metrics.precision_score(actual, predicted)
print(precision)

sensitivity_recall = metrics.recall_score(actual, predicted)
print(sensitivity_recall)

specificity = metrics.recall_score(actual, predicted, pos_label=0)
print(specificity)

fscore = metrics.f1_score(actual, predicted)
print(fscore)
