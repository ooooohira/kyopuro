from selenium import webdriver
from selenium.webdriver.common.by import By
import time
import pandas as pd
import os
import csv
input_file = r"./event.csv"#変換先のcsvファイル
f = open(input_file, "a")


browser = webdriver.Chrome(executable_path = os.environ['DRIVE_PATH'])
browser.implicitly_wait(3)


#20秒以内に好きなところに手動でダウンロード先を変更する
url_login = "https://medical.nikkeibp.co.jp/inc/all/gakkai/calendar/fukuoka.html"
browser.get(url_login)
time.sleep(20)
print("ダウンロードを開始します")


#ログイン処理
browser.get("https://www.geospatial.jp/ckan/user/login")
time.sleep(3)
browser_form=browser.find_element(By.XPATH, '//*[@id="field-login"]')
browser_form.send_keys(os.environ['ID'])
browser_form=browser.find_element(By.XPATH, '//*[@id="field-password"]')
browser_form.send_keys(os.environ['PASSWORD'])
browser_form=browser.find_element(By.XPATH, '//*[@id="content"]/div/div/section/div/form/div[4]/button')
time.sleep(3)
browser_form.click()


#クリックしてダウンロードまで
for i in range(1, 2071):

    #各市のページに移動する
    browser.get("https://www.geospatial.jp/ckan/dataset/houmusyouchizu-2022-1-" + str(i))
    time.sleep(3)

    #詳細ボタン
    browser_form=browser.find_element(By.XPATH, '//*[@id="dataset-resources"]/ul/li[2]/div/a/span')
    time.sleep(3)
    browser_form.click()

    #ダウンロードボタン
    browser_form=browser.find_element(By.XPATH, '//*[@id="dataset-resources"]/ul/li[2]/div/ul/li[2]/a')
    time.sleep(3)
    browser_form.click()

    #規約同意ボタン
    browser_form=browser.find_element(By.XPATH, '//*[@id="content"]/div/section/div/div[3]/ul/li/a[1]')
    time.sleep(3)
    browser_form.click()
#ダウンロード完了