import requests
def zhihuLogin(phoneNum,password):
    url = "https://www.zhihu.com/signin"
    headers = {
        'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.103 Safari/537.36',
        "HOST": "www.zhihu.com",
        "Referer": "https://www.zhihu.com",
        'Connection': 'keep-alive'
    }
    data = {
        
        "username":phoneNum,
        "password": password
    }
    session = requests.session()
    re1 = session.post(url,data = data,headers = headers)
    print(re1.status_code)
    url2 ="https://www.zhihu.com/draft?type=answer"
    res = session.get(url2)
    print(res.text)



phoneNum = '18683971417'
password = 'lgq081158'
zhihuLogin(phoneNum,password)