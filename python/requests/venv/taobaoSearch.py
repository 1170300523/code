import requests
import re

def getHTML(url):
    try:
        kv = {'user-agent': 'mozilla/5.0'}
        r = requests.get(url,headers = kv)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        print("geth error")
        return ""

def parsePage(goodsList,html):
    print(html)
    try:
        plt = re.findall(r'"view_price":"[\d.]*"', html)
        tlt = re.findall(r'"raw_title":".*?"', html)
        print(len(plt))
        print(len(tlt))
        for i in range(len(plt)):
            price = eval(plt[i].split(':')[1])
            title = tlt[i].split(':')[1]
            goodsList.append([price,title])
    except:
        print("error at parsePage")
    return goodsList

def printGoodList(alist):
    tplp = '{:^4}\t{:^8}\t{:^16}'
    print(tplp.format("序号","价格","名称"))
    count = 0
    for g in goodsList:
        count += 1
        print(tplp.format(count,g[0],g[1]))


if __name__ == '__main__':
    goods = '书包'
    deep = 2
    start_url = 'https://s.taobao.com/search?q=' + goods
    goodsList = []
    for i in range(deep):
        try:
            url = start_url + '&s=' +str(44*i)

            html = getHTML(url)
            parsePage(goodsList,html)
        except:
            print("get error!")
            continue
    printGoodList(goodsList)

