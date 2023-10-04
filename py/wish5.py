import random
import numpy as np
from PIL import Image, ImageDraw, ImageFont


def create_rocket_animation(filename="rocket_animation.gif"):
    """Creates an animated GIF with a rocket launching and a warm wishes message.

    Args:
        filename: The name of the output GIF file.
    """

    rocket_width = 50
    rocket_height = 100
    rocket_position = [350, 700]
    rocket_velocity = [0, -6]  # Adjust the initial velocity as needed

    # Create a blank canvas with a blue background.
    canvas = Image.new("RGB", (700, 700), (0, 0, 255))  # Blue background

    # Create a list of frames for the animation.
    frames = []

    for i in range(300):
        # Update the rocket's position.
        rocket_position[0] += rocket_velocity[0]
        rocket_position[1] += rocket_velocity[1]

        # Create a new canvas for each frame.
        frame = canvas.copy()

        # Draw the rocket on the canvas.
        draw = ImageDraw.Draw(frame)
        draw.rectangle(
            (
                rocket_position[0] - rocket_width // 2,
                rocket_position[1] - rocket_height,
                rocket_position[0] + rocket_width // 2,
                rocket_position[1],
            ),
            fill=(0, 255, 0),  # Red rocket color
        )

        # Draw a triangle at the top of the rocket.
        triangle_height = 20
        triangle_width = 30
        triangle_x = rocket_position[0]
        triangle_y = rocket_position[1] - rocket_height - triangle_height
        draw.polygon(
            [
                (triangle_x - triangle_width // 2, triangle_y),
                (triangle_x, triangle_y - triangle_height),
                (triangle_x + triangle_width // 2, triangle_y),
            ],
            fill=(0, 255, 0),  # Green triangle color
        )

        # Add a warm wishes message to the frame using a text box.
        warm_wishes = "Congratulations on Your Achievement, Montu! Wishing you a bright and successful future ahead!!....."
        font = ImageFont.load_default()
        font_size = 36
        font_color = (0, 255, 0)  # White font color

        # Define the text box position and size.
        text_box_x = 50
        text_box_y = frame.height - 100
        text_box_width = frame.width - 2 * text_box_x
        text_box_height = 60

        # Create the text box background.
        draw.rectangle(
            (
                (text_box_x, text_box_y),
                (text_box_x + text_box_width, text_box_y + text_box_height),
            ),
            fill=(0, 0, 0),  # Black text box background color
        )

        # Calculate the position to center the text within the text box.
        text_x = text_box_x + 10  # Adjust the x-coordinate as needed
        text_y = text_box_y + 10  # Adjust the y-coordinate as needed

        # Add the text to the frame.
        draw.text(
            (text_x, text_y),
            warm_wishes,
            font=font,
            font_color=font_color,
            font_size=font_size,
            fill=font_color,
            encoding="utf-8",
        )

        # Add the frame to the list of frames.
        frames.append(frame)

    # Create the animated GIF.
    frames[0].save(
        filename, save_all=True, append_images=frames[1:], duration=100
    )  # Adjust duration as needed (milliseconds)


# Example usage:
create_rocket_animation("Montu_g.gif")
