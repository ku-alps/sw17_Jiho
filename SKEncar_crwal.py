from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC 
from bs4 import BeautifulSoup
import sqlite3
import time

# 주의사항 : beautifulsoup은 xpath를 지원하지 않는다.
# 개선사항 : DB 기본키 설정

# 웹 드라이버 설정
browser = webdriver.Chrome('./webdriver/chrome/chromedriver.exe')
browser.set_window_size(1920, 1080)
browser.implicitly_wait(2)

# 제조사, 모델명, 연식 선택 
browser.get('http://www.encar.com/index.do')
WebDriverWait(browser, 2).until(EC.presence_of_element_located((By.CSS_SELECTOR, 'a.link_sub > span.ir_index'))).click()
time.sleep(0.5)
WebDriverWait(browser, 2).until(EC.presence_of_element_located((By.CSS_SELECTOR, 'ul.list_search > li:nth-child(2) > a.link_item'))).click()
time.sleep(0.5)

WebDriverWait(browser, 2).until(EC.presence_of_element_located((By.CSS_SELECTOR, 'strong#series > a.link_sub > span:nth-child(2)'))).click()
time.sleep(0.5)
WebDriverWait(browser, 2).until(EC.presence_of_element_located((By.XPATH, '//*[@id="seriesItemList"]/li[2]/a'))).click()
time.sleep(0.5)

WebDriverWait(browser, 2).until(EC.presence_of_element_located((By.XPATH, '//*[@id="md"]/a/span[2]'))).click()
time.sleep(0.5)
WebDriverWait(browser, 2).until(EC.presence_of_element_located((By.XPATH, '//*[@id="mdlItemList"]/li[2]/a'))).click()
WebDriverWait(browser, 2).until(EC.presence_of_element_located((By.XPATH, '//*[@id="indexSch1"]/div[1]/a/span'))).click()
time.sleep(0.5)

# DB 커넥션
conn = sqlite3.connect('./Database/SKEncar_carInfo2.db', isolation_level = None)

# 커서 바인딩
cursor = conn.cursor()

with conn:
    # 테이블 생성
    sql = "CREATE TABLE IF NOT EXISTS car_info(page INTEGER, name TEXT, year TEXT, kilo TEXT, fuel TEXT, location TEXT, price TEXT)"
    cursor.execute(sql)

    # 크롤링 마지막 페이지 탐색
    soup = BeautifulSoup(browser.page_source, 'html.parser')
    crwal_last_page = 1
    
    while (soup.select_one('div.part.page > span.next') != None):
        WebDriverWait(browser, 2).until(EC.presence_of_element_located((By.CSS_SELECTOR,'div.part.page > span.next'))).click()
        time.sleep(2)
        del soup
        soup = BeautifulSoup(browser.page_source, 'html.parser')

    crwal_last_page = int(soup.select_one('div.part.page > span:nth-last-of-type(2) > a').string)

    # 시작 페이지부터 마지막 페이지까지 사진우대 부분 이름, 연식, 키로수, 연료, 가격 정보 추출
    crawl_cur_page = 1
    browser.get('http://www.encar.com/dc/dc_carsearchlist.do?carType=kor#!%7B%22action%22%3A%22(And.Hidden.N._.(C.CarType.Y._.(C.Manufacturer.%EC%A0%9C%EB%84%A4%EC%8B%9C%EC%8A%A4._.(C.ModelGroup.EQ900._.Model.EQ900.))))%22%2C%22toggle%22%3A%7B%7D%2C%22layer%22%3A%22%22%2C%22sort%22%3A%22ModifiedDate%22%2C%22page%22%3A1%2C%22limit%22%3A20%7D')
    
    while crawl_cur_page <= crwal_last_page:
        soup = BeautifulSoup(browser.page_source, 'html.parser')
        
        # 데이터 추출(사진우대 부분)
        element_list = soup.select('#sr_photo > li')
       
        for i, element in enumerate(element_list):
            name = element.select_one('span.cls > strong').string + element.select_one('span.cls > em').string + element.select_one('span.dtl > strong').string + element.select_one('span.dtl > em').string
            year = element.find('span', class_='yer').string
            kilo = element.find('span', class_='km').string
            fuel = element.find('span', class_='ipt').string
            location = element.find('span', class_='lo').string
            price = element.select_one('span.val > span.prc > strong').string
            
            # DB 저장
            cursor.execute("INSERT INTO car_info(page, name, year, kilo, fuel, location, price) VALUES(?,?,?,?,?,?,?)", (crawl_cur_page, name, year, kilo, fuel, location, price))

        # 기존 soup 객체 삭제
        del soup

        # 페이지 이동
        remainder = crawl_cur_page % 10
        if remainder != 0:
            if not (crawl_cur_page >= 1) and (crawl_cur_page <= 10):
                WebDriverWait(browser, 2.5).until(EC.presence_of_element_located((By.CSS_SELECTOR, 'div.part.page > span:nth-child({}) > a'.format(remainder + 2)))).click()
            else:
                WebDriverWait(browser, 2.5).until(EC.presence_of_element_located((By.CSS_SELECTOR, 'div.part.page > span:nth-child({}) > a'.format(remainder + 1)))).click()
        else:
            WebDriverWait(browser, 2.5).until(EC.presence_of_element_located((By.CSS_SELECTOR, 'div.part.page > span.next'))).click()
        
        crawl_cur_page += 1
        
        # 시스템 대기
        time.sleep(2)

browser.close()
