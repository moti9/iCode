from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException
import pandas as pd
import time


def scrape_blog_data(driver):
    # Collect data (replace these with actual scraping logic)
    titles = driver.find_elements_by_class_name("blog-title")
    dates = driver.find_elements_by_class_name("blog-date")
    image_urls = driver.find_elements_by_class_name("blog-image")
    likes = driver.find_elements_by_class_name("blog-likes")

    data = {
        "Title": [title.text for title in titles],
        "Date": [date.text for date in dates],
        "Image URL": [image.get_attribute("src") for image in image_urls],
        "Likes": [like.text for like in likes],
    }

    return data


def clean_data(df):
    # Add data cleaning logic if needed
    # ...

    return df


def save_to_csv(df, filename="blog_data.csv"):
    df.to_csv(filename, index=False)
    print(f"Data saved to {filename}")


def navigate_to_next_page(driver):
    try:
        # Replace 'next_page_selector' with the actual selector for the next page button
        next_page_button = driver.find_element_by_css_selector("next_page_selector")
        next_page_button.click()
        time.sleep(2)  # Add a short delay to allow the new page to load
        return True
    except NoSuchElementException:
        return False


def main():
    # Replace 'path/to/chromedriver' with the actual path to your ChromeDriver executable
    driver = webdriver.Chrome()

    try:
        # Open the blog website
        driver.get("https://example-blog.com")

        all_data = []

        while True:
            # Scrape data from the current page
            data = scrape_blog_data(driver)
            all_data.append(data)

            # Check if there's a next page
            if not navigate_to_next_page(driver):
                break

        # Combine data from all pages into a single DataFrame
        df = pd.DataFrame(
            {
                key: [
                    item for sublist in [d[key] for d in all_data] for item in sublist
                ]
                for key in all_data[0]
            }
        )

        # Clean data if needed
        df = clean_data(df)

        # Save data to CSV
        save_to_csv(df)

    except Exception as e:
        print(f"An error occurred: {e}")

    finally:
        # Close the browser window
        driver.quit()


if __name__ == "__main__":
    main()
