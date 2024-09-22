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

def match_channels(image, target_image):
    if image.shape[2] == target_image.shape[2]:
        return image
    
    if target_image.shape[2] == 3 and image.shape[2] == 4:
        return cv2.cvtColor(image, cv2.COLOR_BGRA2BGR)
    elif target_image.shape[2] == 4 and image.shape[2] == 3:
        return cv2.cvtColor(image, cv2.COLOR_BGR2BGRA)
    return image

def overlay_images(background, overlay, x_offset, y_offset):
    bg_height, bg_width = background.shape[:2]
    ol_height, ol_width = overlay.shape[:2]

    if x_offset + ol_width > bg_width or y_offset + ol_height > bg_height:
        raise ValueError("Overlay image exceeds background dimensions")

    overlay = match_channels(overlay, background)

    if background.shape[2] == 4:
        alpha_mask = overlay[:, :, 3] / 255.0
        alpha_inverse = 1.0 - alpha_mask

        for c in range(0, 3):
            background[y_offset:y_offset+ol_height, x_offset:x_offset+ol_width, c] = (
                alpha_mask * overlay[:, :, c] +
                alpha_inverse * background[y_offset:y_offset+ol_height, x_offset:x_offset+ol_width, c]
            )
    else:
        background[y_offset:y_offset+ol_height, x_offset:x_offset+ol_width] = overlay[:, :, :3]

    return background

# logo_url = "https://images.crunchbase.com/image/upload/c_pad,f_auto,q_auto:eco,dpr_1/z3fcqr3qfwvkl5ohh8sp"
# map_url = "https://dev-otter.s3.us-west-004.backblazeb2.com/misc/None/162146/131 Sitara Lane, Saint Johns, FL, USA.png"


# logo_img = fetch_image(logo_url)
# map_img = fetch_image(map_url)

map_img = cv2.imread("./img/map2.png")
org_logo = cv2.imread("./img/logo2.png")
otter_logo = cv2.imread("./img/logo.jpeg")

if org_logo is not None:
    max_size = (48, 140)
    resized_logo_img = resize_image_with_aspect_ratio(org_logo, max_size)

    logo_height, logo_width = resized_logo_img.shape[:2]
    map_height, map_width = map_img.shape[:2]

    if logo_height > map_height or logo_width > map_width:
        print("Logo is larger than map in at least one dimension. Resizing logo...")
        scale = min(map_height / logo_height, map_width / logo_width)
        resized_logo_img = cv2.resize(resized_logo_img, (int(logo_width * scale), int(logo_height * scale)))
        logo_height, logo_width = resized_logo_img.shape[:2]

    y_offset = 2
    x_offset = map_width - logo_width - 8

    map_img = overlay_images(map_img, resized_logo_img, x_offset, y_offset)

    cv2.imshow("Map with Logo", map_img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
else:
    print("Failed to fetch one or both images.")
