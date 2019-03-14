# coding: utf-8
# 项目: 一个库,用于高校数据分析,包含一些方便的函数
# 作者: 李国庆
# 时间: 2018/1/23

import pandas as pd

data = pd.read_excel('test.xlsx', sheet_name='2017年原始数据')

k = data.校友会境外
print(len(k))

   
