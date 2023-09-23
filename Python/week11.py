# # from selenium import webdriver

# # def launch():
# #     browser=webdriver.Chrome("/Users/mihir/Downloads/chromedriver_win32\chromedriver.exe")
# #     browser.get("https://www.google.com")
# #     # search = browser.find_element_by_id("APjFqb")
# #     # search.send("how to pass nptel")
# #     box=browser.find_element_by_link_text('Google Search')
# #     box.click()
# #     while(True):
# #         pass

# # driver=launch()

# # from datetime import datetime as dt

# # print(dt.now())

# # import pytz

# # # tz=pytz.all_timezones
# # # print(tz)

# # tz=pytz.timezone('Asia/Kolkata')
# # tz1=pytz.timezone('Singapore')
# # print(dt.now(tz))
# # print(dt.now(tz1))

# # tz=pytz.all_timezones
# # print(len(tz))

# # import calendar

# # print(calendar.weekday(2023,3,18))

# from datetime import datetime as dt
# import pytz

# tz = pytz.all_timezones

# # for i in range(len(tz)):
# #     current_zone = tz[i]
# #     curr_time_zone_obj = pytz.timezone(current_zone)
# #     print("Current time zone is -> ", current_zone,
# #           " and the Time is : ", dt.now(curr_time_zone_obj))


import calendar


# print(calendar.month(2023,3))
# print(calendar.calendar(2023))
# print(calendar.prcal(2023))


# import time

# print(time.time())
# print(calendar.leapdays(2023,2025))
# print(time.gmtime(0))
# print(time.ctime(2223489812))

# import random
# arr=["ankur","shruti","parul","sandhya"]

# print(random.sample(arr,3))

# s=input().split('#')
# s.sort()
# s.reverse()
# s='#'.join(s)
# print(s)


print(calendar.leapdays(2000,2005))