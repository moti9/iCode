# import cv2
# import numpy as np

# img = np.zeros((512, 512, 3))


# def draw(event, x, y, flags, params):
#     pass


# cv2.namedWindow("window")
# cv2.setMouseCallback("window", draw)

# while True:
#     cv2.imshow("window", img)

#     if cv2.waitKey(1) & 0xFF == ord("s"):
#         break
# cv2.destroyAllWindows()


import numpy as np
import cv2 as cv


# # mouse callback function
# def draw_circle(event, x, y, flags, param):
#     if event == cv.EVENT_LBUTTONDBLCLK:
#         cv.circle(img, (x, y), 100, (255, 0, 0), -1)


# # Create a black image, a window and bind the function to window
# img = np.zeros((512, 512, 3), np.uint8)
# cv.namedWindow("image")
# cv.setMouseCallback("image", draw_circle)
# while 1:
#     cv.imshow("image", img)
#     if cv.waitKey(1) & 0xFF == ord('x'):
#         break
# cv.destroyAllWindows()

cap = cv.VideoCapture(0)
while True:
    ret, frame = cap.read()
    # print(ret)
    gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    cv.imshow("your video", gray)

    if cv.waitKey(1) & 0xFF == ord("x"):
        break

cv.destroyAllWindows()
