from selenium import webdriver
from selenium.webdriver.chrome.options import Options


chrome_option = Options()
chrome_option.add_experimental_option("detach", True)


driver = webdriver.Chrome(options=chrome_option)


driver.get("https://rategain.com/blog")

driver.quit()
