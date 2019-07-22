import os
import re

import requests

from bs4 import BeautifulSoup

def getHTML(url):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "Error !"


def getHTMLHead(url):
    try:
        r = requests.head(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "Error !"

def seach(url,kv):
    try:
        r = requests.get(url,params=kv)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "Error !"

def baidu(target):
    url = "http://www.baidu.com/s"
    kv = {'wd':target}
    try:
        r = requests.get(url,params=kv)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "Error !"


def getPicture(url, savePath):
    path = savePath + url.split('/')[-1]
    try:
        if not os.path.exists(savePath):
            os.mkdir(savePath)
        if not  os.path.exists(path):
            r = requests.get(url)
            r.raise_for_status()
            with open(path,'wb') as f:
                f.write(r.content)
                f.close()
                print("getPic Succeed!")
        else:
            print("have exist")
    except:
        return "Error !"

def findIP(ip):
    url = 'http://m.ip138.com/ip.asp?ip='+ip
    r = requests.get(url)
    s = re.search('"result">(.*?)</p>',r.text[-500:])
    if s:
        return s.group(1)
    return 'failed'

def getDX():
    url = 'http://www.zuihaodaxue.com/zuihaodaxuepaiming2019.html'
    r = getHTML(url)
    soup = BeautifulSoup(r.text,'html.parser')


if __name__ == '__main__':
    url = "http://www.baidu.com/s"
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        soup = BeautifulSoup(r.text,'html.parser')
        print(soup.prettify())
    except:
        print("error!")


