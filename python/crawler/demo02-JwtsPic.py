# 输入学号,和cookie,获取教务处头像
import requests
import os

def getPic(num):
	head ={'Cookie':'_ga=GA1.3.2028697334.1564554501; DSLaunchURL=2F64616E612F686F6D652F696E6465785F6D6F62696C655F7765626B69742E636769; DSID=f3e7ca2b88da65001e454e132b8544b7; DSFirstAccess=1564928257; DSLastAccess=1564928300',
	'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.103 Safari/537.36'} # 输入你的cookie
	url = "http://jwts.hit.edu.cn/xswhxx/showPhoto?xh="+str(num)
	r = requests.get(url,headers = head)
	with open(str(num)+'.jpg','wb') as f:
		f.write(r.content)

		
getPic(1170300524)