import  re
import requests
from bs4 import BeautifulSoup
import traceback

def getHTML(url):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "Error !"

def getStockList(url):
    return ''

def getStockInfo(lst,stockURL,fpath):
    return ''

if __name__ == '__main__':
    stock_list_url = 'http://quote.eastmoney.com/center/gridlist.html#hs_a_board'
    stock_info_url = ''
    output_file = 'c://test/baiduStock.txt'
    lst = []
    lst = getStockList(stock_list_url)
    getStockInfo(lst,stock_info_url,output_file)


