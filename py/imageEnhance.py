import cv2 as cv


def adjust_brightness(image, target_brightness):
    gray_image = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
    current_brightness = gray_image.mean()
    scaling_factor = target_brightness / current_brightness
    adjusted_image = cv.convertScaleAbs(image, alpha=scaling_factor, beta=0)
    return adjusted_image


cap = cv.VideoCapture(0)

while True:
    ret, frame = cap.read()
    cv.imshow("VideoWindow", frame)

    if cv.waitKey(1) & 0xFF == ord("x"):
        target_brightness = 200
        # Adjust the image's brightness
        brightened_image = adjust_brightness(frame, target_brightness)

        cv.imwrite("image.png", brightened_image)
        break

cv.destroyAllWindows()
