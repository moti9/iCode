import cv2 as cv
import numpy as np

# cap = cv.VideoCapture(0)

# while True:
#     ret, frame = cap.read()
#     cv.imshow("window", frame)

#     if cv.waitKey(1) & 0xFF == ord("x"):
#         cv.imwrite("UserImage.png", frame)
#         break

# cv.destroyAllWindows()


img = cv.imread("st1.png")

# height, width, channels = img.shape
# print(height, width, channels)
# cv.imshow("window", img)
# cv.waitKey(2000)

# print(type(img))

# print(len(img))

# cropped = img[642:771, 12:177]
# height, width, channels = cropped.shape
# print(height, width, channels)
# height, width, channels = cropped.shape
# print(height, width)

# pixel_matrix = np.zeros((height, width, channels), dtype=np.uint8)

# for y in range(height):
#     for x in range(width):
#         blue, green, red = cropped[y, x]
#         pixel_matrix[y, x] = [blue, green, red]

# with open("pixel_matrix.txt", "w") as f:
#     for row in pixel_matrix:
#         for pixel in row:
#             f.write(f"{pixel.tolist()},")


cropped = img[680:720, 12:177]
gray = cv.cvtColor(cropped, cv.COLOR_RGB2GRAY)
height, width = gray.shape
# print(height, width)

pixel_matrix = np.zeros((height, width), dtype=np.uint8)

for y in range(height):
    for x in range(width):
        gray_value = gray[y, x]
        # pixel_matrix[y, x] = gray_value
        # Format the value with three digits
        formatted_value = f"{gray_value:03}"

        # Set the formatted values in the pixel_matrix
        pixel_matrix[y, x] = formatted_value


with open("pixel_matrix2.txt", "w") as f:
    for row in pixel_matrix:
        # f.write(f"{row.tolist()}\n")
        f.write("-".join(row.astype(str)) + "\n")

# with open("pixelValue.txt", "w") as file:
#     # file.write()
#     pass

while True:
    cv.imshow("window", gray)
    if cv.waitKey(1) & 0xFF == ord("x"):
        break
cv.destroyAllWindows()
