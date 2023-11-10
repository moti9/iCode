import cv2
import numpy as np
from matplotlib import pyplot as plt

# Define a function to cartoonify an image
def cartoonify(image):

    # Convert the image to grayscale
    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Apply a bilateral filter to smooth the image
    smoothed_image = cv2.bilateralFilter(gray_image, 9, 75, 75)

    # Apply adaptive thresholding to identify the edges in the image
    edges_image = cv2.adaptiveThreshold(smoothed_image, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY_INV, 11, 2)

    # Combine the edges image with the smoothed image to get the cartoonified image
    cartoonified_image = cv2.bitwise_or(smoothed_image, edges_image)

    return cartoonified_image

# Capture an image from the webcam
cap = cv2.VideoCapture(0)

# Check if the webcam is opened successfully
if not cap.isOpened():
    raise Exception("Webcam not opened successfully")

# Read an image from the webcam
ret, frame = cap.read()

# Check if the image is captured successfully
if not ret:
    raise Exception("Image not captured successfully")

# Cartoonify the image
cartoonified_image = cartoonify(frame)

# Display the cartoonified image
plt.imshow(cartoonified_image, cmap='gray')
plt.title('Cartoonified Image')
plt.show()

# Release the webcam
cap.release()
