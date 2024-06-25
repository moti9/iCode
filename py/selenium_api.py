from selenium import webdriver

driver = webdriver.Chrome()

driver.get("https://dev.ottermap.com/")

driver.quit()