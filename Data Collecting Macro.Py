from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from bs4 import BeautifulSoup
import time as t

driver = webdriver.Chrome("C:\\sungmo\\chromedriver_win32\\chromedriver.exe")
driver.implicitly_wait(10)

driver.get("https://map.naver.com/v5/directions/-/-/-/car?c=14133513.7612005,4511859.5880759,14,0,0,0,dh")

a_buscourse=["1","2","3", "4", “5”]
distance_list=[]
for i, start_point in enumerate(a_buscourse):
   for j, end_point in enumerate(a_buscourse):
      if i==j:
         distance_list.append(0)
      else:
         search_element1=driver.find_element_by_css_selector("#directionStart0")
         search_element1.clear()
         search_element1.send_keys(start_point)
         search_element1.send_keys(Keys.ENTER)
         t.sleep(2)
         search_element2=driver.find_element_by_css_selector("#directionGoal1")
         search_element2.clear()
         search_element2.send_keys(end_point)
         search_element2.send_keys(Keys.ENTER)
         t.sleep(2)
         driver.find_element_by_css_selector("#container > shrinkable-layout > div > directions-layout > directions-result > div.main > div > directions-search > div.btn_box > button.btn.btn_direction.active").click()
         t.sleep(2)
         dom=BeautifulSoup(driver.page_source,"html.parser")
         distancetext=dom.find_all("span",{"class":"summary_text"})
         print(distancetext[0].text)
         distance_list.append(distancetext[0].text)
         t.sleep(2)    
   print(distance_list)
   distance_list = [] 

#container > shrinkable-layout > div > directions-layout > directions-result > div.main > directions-summary-list > directions-hover-scroll > div > div > directions-summary-item-car.item_summary.selected.ng-star-inserted > div.summary_box > span.summary_text > readable-distance
