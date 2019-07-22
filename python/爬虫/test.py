import urllib.request as request

my_url = 'http://jwts.hit.edu.cn/main'
head ={
	'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.103 Safari/537.36',
	'Cookie':'name=value; name=value; clwz_blc_pst=201330860.20480; JSESSIONID=9DE597848D4CC3DAC1BCF9D6D977492A'
}

r = request.Request(url = my_url, headers = head)
res = request.urlopen(r)
# print(res.read().decode('utf-8'))

with open('hit.html','w',encoding = 'utf-8') as f:
	f.write(res.read().decode('utf-8'))