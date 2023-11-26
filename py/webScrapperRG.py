import requests
from bs4 import BeautifulSoup
import csv


# Function to scrape data from a given URL
def scrape_blog_data(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, "html.parser")

    # Initialize lists to store data
    blog_titles = []
    blog_dates = []
    blog_image_urls = []
    blog_likes_count = []

    # Extract data from the page
    posts = soup.find_all(
        "div", class_="blog-post"
    )  # Adjust the class based on the actual HTML structure

    for post in posts:
        # Extract blog title
        title = post.find("h2").text.strip()
        blog_titles.append(title)

        # Extract blog date
        date = post.find("span", class_="publish-date").text.strip()
        blog_dates.append(date)

        # Extract blog image URL (adjust based on the actual HTML structure)
        image_url = post.find("img")["src"]
        blog_image_urls.append(image_url)

        # Extract blog likes count (adjust based on the actual HTML structure)
        likes_count = post.find("span", class_="likes-count").text.strip()
        blog_likes_count.append(likes_count)

    # Organize data into a dictionary
    blog_data = {
        "Title": blog_titles,
        "Date": blog_dates,
        "Image URL": blog_image_urls,
        "Likes Count": blog_likes_count,
    }

    return blog_data


# Function to save data to CSV
def save_to_csv(data, filename="blog_data.csv"):
    with open(filename, "w", newline="", encoding="utf-8") as csvfile:
        fieldnames = ["Title", "Date", "Image URL", "Likes Count"]
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

        # Write header
        writer.writeheader()

        # Write data rows
        for i in range(len(data["Title"])):
            writer.writerow(
                {
                    "Title": data["Title"][i],
                    "Date": data["Date"][i],
                    "Image URL": data["Image URL"][i],
                    "Likes Count": data["Likes Count"][i],
                }
            )


# URL of the target website
url = "https://rategain.com/blog"

# Scrape data
blog_data = scrape_blog_data(url)

# Save data to CSV
save_to_csv(blog_data)
