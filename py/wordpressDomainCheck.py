import re
import requests

# Check version
def check_wordpress_version(url):
    try:
        response = requests.get(url)

        html_content = response.text
        pattern = r'(?<meta name="generator" content="WordPress )\d+\.\d+(\.\d+)?'

        match = re.search(pattern, html_content)

        if match:
            print(match.group(0))
        else:
            print("Unknown")
    except:
        print("Unknown")


# Check for wordpress
def is_using_wordpress(url):
    response = requests.get(f"{url}wp-admin/")
    if response.status_code == 200:
        print("Yes")
        return True
    else:
        wordpress_pattern = r"wp-(?:content|includes)"
        if re.search(wordpress_pattern, response.text):
            print("Yes")
            return True
        else:
            print("No")
            return False


if __name__ == "__main__":
    domain = input("Enter a domain: ")
    url = f"http://{domain}/"
    wordpress = is_using_wordpress(url)

    if wordpress:
        check_wordpress_version(url)
