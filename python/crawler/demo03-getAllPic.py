# 获取一系列图片, 并放在相应的文件夹中
import requests
import os
import re
def getonePic(url,rootpath):
	head ={'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.103 Safari/537.36',
			"Referer" : "http://www.mzitu.com/",
			'Host' : 'i.meizitu.net'}
	r = requests.get(url,headers = head)
	if r.status_code == 200:
		path = url.split('/')[-1]
		with open(rootpath+'/'+path,'wb') as f:
			f.write(r.content)
		return True
	return False


def getAllPic(url,path):
	if not os.path.exists(path):
		os.mkdir(path)
	s = re.sub(r"\d\d.jpg",'',url)
	for i in range(10):
		for j in range(1,10):
			new_url = s + str(i)+str(j)+'.jpg'
			if(getonePic(new_url,path) == False):
				return;


url = 'https://i.meizitu.net/2019/06/05b02.jpg'
path = 'newfile'
getAllPic(url,path)
