import cv2
import requests
import numpy as np

def fetch_image(url):
    try:
        response = requests.get(url)
        response.raise_for_status()
        img_array = np.frombuffer(response.content, np.uint8)
        return cv2.imdecode(img_array, cv2.IMREAD_UNCHANGED)
    except requests.RequestException as e:
        print(f"Error fetching image from {url}")
        return None

def resize_image_with_aspect_ratio(image, max_size):
    height, width = image.shape[:2]
    max_height, max_width = max_size

    scale = min(max_width / width, max_height / height)    

    new_width = int(width * scale)
    new_height = int(height * scale)
    
    resized_image = cv2.resize(image, (new_width, new_height), interpolation = cv2.INTER_AREA)
    return resized_image

logo_url = "https://images.crunchbase.com/image/upload/c_pad,f_auto,q_auto:eco,dpr_1/z3fcqr3qfwvkl5ohh8sp"
map_url = "https://dev-otter.s3.us-west-004.backblazeb2.com/misc/None/162146/131 Sitara Lane, Saint Johns, FL, USA.png"

logo_img = fetch_image(logo_url)
map_img = fetch_image(map_url)

if logo_img is not None and map_img is not None:

    max_size = (100, 250)
    resized_logo_img = resize_image_with_aspect_ratio(logo_img, max_size)

    logo_height, logo_width = resized_logo_img.shape[:2]
    map_height, map_width = map_img.shape[:2]

    if logo_height > map_height or logo_width > map_width:
        print("Logo is larger than map in at least one dimension. Resizing logo...")
        scale = min(map_height / logo_height, map_width / logo_width)
        resized_logo_img = cv2.resize(resized_logo_img, (int(logo_width * scale), int(logo_height * scale)))
        logo_height, logo_width = resized_logo_img.shape[:2]

    y_offset = 0
    x_offset = map_width - logo_width
    map_img[y_offset:y_offset + logo_height, x_offset:x_offset + logo_width] = resized_logo_img

    cv2.imshow("Map with Logo", map_img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
else:
    print("Failed to fetch one or both images.")
