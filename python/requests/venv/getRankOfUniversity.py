import requests
from bs4 import BeautifulSoup
import bs4
import re

def getHTML(url):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "Error !"

def htmlToList(html):
    ulist = []
    soup = BeautifulSoup(html,'html.parser')
    for tr in soup.find('tbody').children:
        if isinstance(tr,bs4.element.Tag):
            tds = tr('td')
            ulist.append([tds[0].string, tds[1].string,tds[2].string])
    return ulist

def printList(list):
    tplp = "{0:^10}{1:{3}^20}{2:^10}"
    print(tplp.format("排名","大学名","所在地",chr(12288)))
    for s in list:
        print(tplp.format(s[0],s[1],s[2],chr(12288)))



if __name__ == '__main__':
    url = 'http://www.zuihaodaxue.com/zuihaodaxuepaiming2019.html'
    html = getHTML(url)
    ulist = htmlToList(html)
    printList(ulist)
