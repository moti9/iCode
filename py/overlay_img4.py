import cv2
import requests
import numpy as np
import os

def fetch_image(url):
    try:
        response = requests.get(url)
        response.raise_for_status()
        img_array = np.frombuffer(response.content, np.uint8)
        return cv2.imdecode(img_array, cv2.IMREAD_UNCHANGED)
    except requests.RequestException as e:
        print(f"Error fetching image from {url}: {e}")
        return None

def resize_image_with_aspect_ratio(image, max_size):
    height, width = image.shape[:2]
    max_height, max_width = max_size

    scale = min(max_width / width, max_height / height)    

    new_width = int(width * scale)
    new_height = int(height * scale)
    
    resized_image = cv2.resize(image, (new_width, new_height), interpolation=cv2.INTER_AREA)
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

src_dir = "./img"
dst_dir = "./genimg"
logo_dir = "./logoimg"

# map_img_path = "./img/map2.png"
org_logo_path = f"{logo_dir}/logo2.png"
otter_logo_path = f"{logo_dir}/logo.jpeg"

# map_img = cv2.imread(map_img_path)
org_logo = cv2.imread(org_logo_path)
otter_logo = cv2.imread(otter_logo_path)

imgs = os.listdir(f"{src_dir}")

for img in imgs:
    try:
        map_img_path = f"{src_dir}/{img}"
        map_img = cv2.imread(map_img_path)

        org_max_size = (48, 140)  
        otter_max_size = (100, 250)

        resized_org_logo = resize_image_with_aspect_ratio(org_logo, org_max_size)
        resized_otter_logo = resize_image_with_aspect_ratio(otter_logo, otter_max_size)

        org_logo_height, org_logo_width = resized_org_logo.shape[:2]
        otter_logo_height, otter_logo_width = resized_otter_logo.shape[:2]
        map_height, map_width = map_img.shape[:2]

        # Top right for org_logo
        org_y_offset = 3
        org_x_offset = map_width - org_logo_width - 8
        # Bottom left for otter_logo
        otter_y_offset = map_height - otter_logo_height - 2
        otter_x_offset = 50

        map_img = overlay_images(map_img, resized_org_logo, org_x_offset, org_y_offset)
        map_img = overlay_images(map_img, resized_otter_logo, otter_x_offset, otter_y_offset)
        cv2.imwrite(f"{dst_dir}/{img}", map_img)
        # cv2.imshow("Map with Logos", map_img)
        # cv2.waitKey(0)
        # cv2.destroyAllWindows()
    except:
        print(f"Failed to process the image - {map_img_path}")



# for i in range(1, 20):
#     try:
#         map_img_path = f"./img/map{i}.png"
#         map_img = cv2.imread(map_img_path)
#         print(i)
#         print(map_img.shape)
#         print(otter_logo.shape)
#         print(org_logo.shape)

#         org_max_size = (48, 140)  
#         otter_max_size = (100, 250)

#         resized_org_logo = resize_image_with_aspect_ratio(org_logo, org_max_size)
#         resized_otter_logo = resize_image_with_aspect_ratio(otter_logo, otter_max_size)

#         org_logo_height, org_logo_width = resized_org_logo.shape[:2]
#         otter_logo_height, otter_logo_width = resized_otter_logo.shape[:2]
#         map_height, map_width = map_img.shape[:2]

#         # Top right for org_logo
#         org_y_offset = 3
#         org_x_offset = map_width - org_logo_width - 8
#         # Bottom left for otter_logo
#         otter_y_offset = map_height - otter_logo_height - 2
#         otter_x_offset = 50

#         map_img = overlay_images(map_img, resized_org_logo, org_x_offset, org_y_offset)
#         map_img = overlay_images(map_img, resized_otter_logo, otter_x_offset, otter_y_offset)
#         cv2.imwrite(f"./genimg/map{i}.png", map_img)
#         # cv2.imshow("Map with Logos", map_img)
#         # cv2.waitKey(0)
#         # cv2.destroyAllWindows()
#     except:
#         print(f"Failed to process the image - {map_img_path}")
