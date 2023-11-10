import requests
from bs4 import BeautifulSoup
from textblob import TextBlob

# Define the YouTube video URL from which you want to scrape comments
youtube_url = (
    "https://www.youtube.com/watch?v=rVOka3ZqmxQ&ab_channel=CodingforAll%7CNewtonSchool"
)


# Function to scrape YouTube comments
def scrape_youtube_comments(url):
    comments = []
    response = requests.get(url)
    soup = BeautifulSoup(response.text, "html.parser")

    for comment in soup.find_all(
        "yt-formatted-string", class_="style-scope ytd-comment-renderer"
    ):
        comments.append(comment.text)

    return comments


# Function to analyze sentiment of comments
def analyze_sentiment(comments):
    results = {"positive": 0, "neutral": 0, "negative": 0}

    for comment in comments:
        analysis = TextBlob(comment)
        polarity = analysis.sentiment.polarity

        if polarity > 0:
            results["positive"] += 1
        elif polarity == 0:
            results["neutral"] += 1
        else:
            results["negative"] += 1

    return results


def main():
    comments = scrape_youtube_comments(youtube_url)
    total_comments = len(comments)

    if total_comments > 0:
        sentiment_results = analyze_sentiment(comments)
        print(f"Total comments: {total_comments}")
        print(
            f"Positive comments: {sentiment_results['positive']} ({sentiment_results['positive']/total_comments*100:.2f}%)"
        )
        print(
            f"Negative comments: {sentiment_results['negative']} ({sentiment_results['negative']/total_comments*100:.2f}%)"
        )
        print(
            f"Neutral comments: {sentiment_results['neutral']} ({sentiment_results['neutral']/total_comments*100:.2f}%)"
        )
    else:
        print("No comments found.")


if __name__ == "__main__":
    main()


# def main():
#     comments = scrape_youtube_comments(youtube_url)
#     sentiment_results = analyze_sentiment(comments)

#     total_comments = len(comments)

#     print(f"Total comments: {total_comments}")
#     print(
#         f"Positive comments: {sentiment_results['positive']} ({sentiment_results['positive']/total_comments*100:.2f}%)"
#     )
#     print(
#         f"Neutral comments: {sentiment_results['neutral']} ({sentiment_results['neutral']/total_comments*100:.2f}%)"
#     )
#     print(
#         f"Negative comments: {sentiment_results['negative']} ({sentiment_results['negative']/total_comments*100:.2f}%)"
#     )


# if __name__ == "__main__":
#     main()


# from bs4 import BeautifulSoup
# from urllib.request import urlopen

# url = (
#     "https://www.youtube.com/watch?v=rVOka3ZqmxQ&ab_channel=CodingforAll%7CNewtonSchool"
# )

# page = urlopen(url)
# html = page.read().decode("utf-8")

# soup = BeautifulSoup(html, "html.parser")

# with open("webscr.html", "w") as fl:
#     fl.write(soup.prettify())
