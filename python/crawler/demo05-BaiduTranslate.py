# 百度翻译, 从英语到汉语
import urllib.request
import urllib.parse
import json
import requests
from pprint import pprint

def fanyi(word):
	post_url = 'https://fanyi.baidu.com/sug'
	from_data = {'kw':word,}
	from_data = urllib.parse.urlencode(from_data).encode()
	hearders = {'User-Agent' :
	'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.103 Safari/537.36'}
	req = urllib.request.Request(post_url,headers = hearders)
	res = urllib.request.urlopen(post_url,data = from_data)
	j =  res.read().decode('utf-8')
	result = json.loads(j)
	for item in result['data']:
		for i in item:
			print(item[i])

# fanyi('baby')

def translate(word):
	post_url = 'https://fanyi.baidu.com/sug'
	from_data = {'kw':word}
	
	hearders = {'User-Agent' :
	'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.103 Safari/537.36'
	}
	r = requests.post(post_url,headers = hearders, data = from_data)
	if r.status_code == 200:
		for item in r.json()['data']:
		# for k,v in r.json().items():
		# 	print(k+" : "+v)
			print(item['k']+' : '+item['v'])

translate('baby')