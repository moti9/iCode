import cv2

def hconcat_resize(img_list, interpolation=cv2.INTER_CUBIC): 
    # Take minimum height
    h_min = min(img.shape[0] for img in img_list)
      
    # Image resizing
    im_list_resize = [cv2.resize(img, (int(img.shape[1] * h_min / img.shape[0]), h_min), interpolation=interpolation) for img in img_list]
      
    # Return final image
    return cv2.hconcat(im_list_resize)

# Read images
background = cv2.imread("./img/map_img.png")
front = cv2.imread("./img/panel_img.png")
logo = cv2.imread("./img/logo.jpeg")

# Ensure images are not None
if background is None:
    print("Error: Background image not found.")
if front is None:
    print("Error: Front image not found.")
if logo is None:
    print("Error: Logo image not found.")

# Concatenate images horizontally with resizing
if background is not None and front is not None:
    im_h = hconcat_resize([front, background])

    # Calculate position for the logo
    logo_margin = 10  # Adjust margin as needed
    logo_height, logo_width = logo.shape[:2]
    im_h[logo_margin:logo_margin + logo_height, -logo_width - logo_margin:-logo_margin] = logo

    # Display concatenated image with logo
    cv2.imshow("image", im_h)

    cv2.imwrite("./genimg/final_map.png", im_h)

    cv2.waitKey(0)

    # Closing all open windows
    cv2.destroyAllWindows()
else:
    print("Error: One or more images could not be read.")
