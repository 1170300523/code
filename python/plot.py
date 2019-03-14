# -*- coding: utf-8 -*-
"""
Created on Thu Feb  7 17:34:18 2019

@author: lee32
"""

import  matplotlib.pyplot as plt
#import  matplotlib 
import  numpy as np
#
##matplotlib.rcParams['font.family'] = 'SimHei'
#x = np.arange(0,50,0.1)
#y = np.cos(x)
#z = np.sin(x)
#plt.plot(x,y)
#
#
#plt.subplot(2,1,1)
#plt.plot(x,y)
#plt.xlabel('name')
#plt.ylabel('score')
#plt.subplot(2,1,2)
#plt.xlabel('name')
#plt.ylabel('你号')
#plt.plot(x,z,'r:')
#plt.title('为什么',fontproperties = 'SimHei')
#plt.text(10,0.5,'振轩博',fontproperties = 'SimHei')
#plt.annotate('hello',xy = (15,0.5),xytext = (40,0.3),arrowprops = dict(facecolor = 'black',shrink = 0.1,width = 0.2))
#plt.grid(True)
#plt.savefig('plot_picture',dpi = 100)
#plt.show()

###pie
#labels = 'cat','dogs','pig','duck'          #标签
#size = [10,40,20,30]                        #数据
#ex = [0,0.1,0,0]                            #突出部分
#plt.pie(size,explode = ex,labels = labels,autopct = '%1.1f%%',startangle = 90)   
#plt.show()


###hist 直方图
#np.random.seed(0)
#mu,sigma = 100,20
#a = np.random.normal(mu,sigma,size = 100)
#plt.hist(a,20,normed = 1)
#plt.title('hist')
#plt.show()

#散点图
fig,ax = plt.subplots()
ax.plot(np.random.randn(100),np.random.randn(100),'o')
plt.show()


