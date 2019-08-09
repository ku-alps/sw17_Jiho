# -*- coding: utf-8 -*-
import scrapy
from scrapy.selector import Selector

# import logging

from selenium import webdriver
from selenium.webdriver.support import expected_conditions as EC 
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By
import time

# logger = logging.getLogger('Mylogger')

class TestSpider(scrapy.Spider):
    name = 'test4'
    allowed_domains = ['blog.scrapinghub.com', 'naver.com']

    # 멀티 도메인
    start_urls = ['http://blog.scrapinghub.com/', 'https://naver.com']

    # scrapy 사용 시 자동으로 사용자가 설정한 내용을 반영(settings.py)
    custom_settings = {
        'DOWNLOAD_DELAY' : 3,
        'COOKIES_EMABLED' : True
    }
   
    # parse()가 없을 경우, 자동적으로 start_request() 메소드가 실행됨
    def start_requests(self):
        # 각 Request마다 처리함수를 지정
        # 각각 blog.scrapinghub.com의 기사 제목과, 네이버 스쿨잼 부분 게시물 제목 추출
        yield scrapy.Request('http://blog.scrapinghub.com/', self.parse_scrpinghub_title, dont_filter = True)
        yield scrapy.Request('https://naver.com', self.parse_naver_theme_title, dont_filter = True)


    def parse_scrpinghub_title(self, response):
        yield {
                'sitemap' : response.url,
                'titlelist' : response.xpath('//div[@class="post-header"]/h2/a/text()').extract()
        }
        
    def parse_naver_theme_title(self, response):
        yield scrapy.Request(response.url, self.parse_title)

    
    def parse_title(self, response):
        browser = webdriver.Chrome("Input your chrome webdriver path")
        browser.implicitly_wait(2)
        browser.set_window_size(1920, 1080)

        browser.get(response.url)

        selector = Selector(text = browser.page_source)
        time.sleep(2)
        
        WebDriverWait(browser, 3).until(EC.presence_of_element_located((By.CSS_SELECTOR, 'a[data-clk="tct.menu"] > span.ac_bicon'))).click()
        time.sleep(2)
        WebDriverWait(browser, 3).until(EC.presence_of_element_located((By.CSS_SELECTOR, '#PM_ID_themeEditItemList > li[data-clk="tca.scl"]'))).click()
        time.sleep(2)

        del selector
        selector = Selector(text = browser.page_source)
        
        yield {
            'sitemap' : response.url,
            'titlelist' : selector.css('ul.themecast_list > li.tl_default > a > span.td_tw > span::text').extract()
        }
