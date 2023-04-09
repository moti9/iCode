import requests
import io
# fp=open("test.html",'w')
with open('test.html','w',encoding="utf-8") as fp:
    fp.write(requests.get("https://www.google.com").text)


# print(requests.get("https://www.google.com").text)