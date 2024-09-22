from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options
import time
import os


def run_selenium_scripts():

    download_dir = os.path.join(os.getcwd(), "downloads")

    if not os.path.exists(download_dir):
        os.makedirs(download_dir)

    chrome_options = Options()
    chrome_options.add_argument("--headless")
    chrome_options.add_argument("--no-sandbox")
    chrome_options.add_argument("--disable-dev-shm-usage")
    
    driver = webdriver.Chrome(options=chrome_options)

    driver.execute_cdp_cmd("Page.setDownloadBehavior", {
        "behavior": "allow",
        "downloadPath": download_dir
    })

    try:
        driver.get("https://dev.ottermap.com/")        
        driver.set_window_size(1440, 1000)
        driver.find_element(By.ID, "outlined-required").send_keys("moti@ottermap.com")
        driver.find_element(By.CSS_SELECTOR, '[type="password"]').send_keys("motiky")
        driver.find_element(By.CSS_SELECTOR, ".login-btn").click()

        time.sleep(10)

        # links = ["https://app.ottermap.com/order/addcdc56-d2c5-44a1-b7fe-cf09b65250cd?view_id=null"]
        links = ["https://dev.ottermap.com/order/63f72408-57c9-4918-9e81-eb123f76c3a0?view_id=599"]
        
        for link in links:
            try:
                driver.get(link)
                time.sleep(5)
                # driver.find_element(By.CSS_SELECTOR, ".download-modal-open-button").click()
                download_icon = driver.find_element(By.CSS_SELECTOR, 'svg[data-testid="DownloadIcon"]')
                download_icon.click()
                time.sleep(3)
                driver.find_element(By.XPATH, "//*[contains(text(), 'Download PNG with Measurements')]").click()
                time.sleep(5)
            except Exception as e:
                print(f"Error occurred for link {link}: {e}")
                continue

        print("Done this is working")

    finally:
        print("Now going to shutdown")
        time.sleep(5)
        driver.quit()


run_selenium_scripts()