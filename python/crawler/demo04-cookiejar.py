# 登录

from urllib import request
from http.cookiejar import CookieJar

cookiejar = CookieJar()
handler = request.HTTPCookieProcessor(cookiejar)
opener  = request.build_opener(handler)

header = {
	'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.103 Safari/537.36'
}

data ={
	
}