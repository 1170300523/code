# request 库入门
import requests
import re


def getHTML(url):
	try:
		r = requests.get(url)
		r.raise_for_status()
		r.encoding = r.apparent_encoding
		return r.text
	except:
		raise "Error !"

def getHTMLHead(url):
	try:
		r = requests.head(url)
		r.raise_for_status()
		r.encoding = r.apparent_encoding
		return r.text
	except:
		raise "Error !"

def getPic(num):
	head ={
	'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.103 Safari/537.36'}
	url = "http://jwts.hit.edu.cn/xswhxx/showPhoto?xh="+str(num)
	r = requests.get(url,headers = head)
	with open(str(num)+'.jpg','wb') as f:
		f.write(r.content)

if __name__ == '__main__':
	start = 1170300500
	for i in range(30):
		getPic(start+i)
	