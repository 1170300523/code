# 输入学号, 获取教务处头像
import requests
import os

def getPic(num):
	head ={'Cookie':''}
	url = "http://jwts.hit.edu.cn/xswhxx/showPhoto?xh="+str(num)
	r = requests.get(url,headers = head)
	with open('m4/'+str(num)+'.jpg','wb') as f:
		f.write(r.content)

getPic()