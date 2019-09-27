import  numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

x = np.linspace(1,10,100)
y = 5.1*np.cos(x)


# 多项式拟合, 输入 x, y, 阶数m
def polyfit(x,y,m):
	f = np.polyfit(x,y,5)
	t = np.polyval(f,x)
	plt.scatter(x,y,c = 'y')
	plt.plot(x,t,'r')
	plt.show()




def func(x,a,b):
	return a*np.sin(x) + b

# 给出特定模型func,输入下x,y得到相关参数
def spec_fit(x,y):
	p1,p2 = curve_fit(func,x,y) # p1是一个参数向量, 包含要求的所有参数
	[a,b] = p1
	t = func(x,a,b) 
	plt.plot(x,t)
	plt.show()



print(x.shape)
print(np.arange(5).shape)

