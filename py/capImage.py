import cv2 as cv

cam_port = 0
cam = cv.VideoCapture(cam_port)

result, image = cam.read()

if result:
    # cv.mshow("webCam", image)

    cv.imwrite("webCam.png", image)

    cv.waitKey(0)
    cv.destroyWindow("webCam")

else:
    print("No image detected. Please! try again")
