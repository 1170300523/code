# ML-lab1.py
# author lee3258
# time 2019/9/18

import numpy as np
import math
import matplotlib.pyplot as plt


# 以sin(x)生成数据,附带噪声
def generate_data(data_size,data_range):
	x0 = np.random.random((data_size,1)) * data_range
	x0 = np.sort(x0,0) # 按列排序, 便于画图
	error = np.random.randn(data_size,1) * 0.1
	y = np.sin(x0) + error
	return np.matrix(x0),np.matrix(y)

# 生成范德蒙德行列式
def Vandermonde_x(x0,m):
	x = np.ones((x0.shape[0],1))
	for i in range(1,m):
		x = np.hstack((x,np.power(x0,i)))
	return x

# 最小二乘法解参数
def least_square(x,y):
	print(x.shape)
	print(y.shape)
	w = (x.T * x).I * x.T * y
	print(w)
	return w

# 有正则项的最小二乘法
def least_square_reg(x,y,lamb):
	m = x.shape[1]
	w =(x.T * x + lamb * np.eye(m)).I * x.T * y
	return w




# 测试效果
def test(x0,y,w):
	# 画出给定点的散点图
	plt.scatter(x0.tolist(),y.tolist())
	# 画出结果的模拟曲线
	xw = np.linspace(0,2*math.pi,40)
	yw = np.polyval(w[::-1],xw)
	plt.plot(xw,yw)
	plt.show()




# 梯度函数
def gradient_function(x, y, w):
	m = x.shape[1]
	return  (1.0/m) * x.T * (x * w - y)

# 代价函数
def error_function( x, y, w):
	m = x.shape[1]
	diff = x * w  - y
	return 1.0/(2*m)*(diff * diff.T)

# 梯度下降法
def gradient_descent(x, y,learning_rate):
	m = x.shape[1]
	w = np.zeros((m,1))
	gradient = gradient_function(x,y,w)
	print(gradient)
	while  np.all(np.absolute(gradient) > 1e-5):
		w = w - learning_rate * gradient # 注意此处
		gradient = gradient_function(x,y,w)

	return w



# 共轭梯度法
def conjugate_gradient(x, y):
	Q = (1 / X.shape[1]) * (X.T * X + lambd * np.mat(np.eye(X.shape[1])))
	w = np.mat(np.zeros(x.shape[1])).T
	r = -gradient_function(x, y, w)
	p = r
	for i in range(1, x.shape[1]):
	    a = float((r.T * r) / (p.T * Q * p))
	    r_prev = r
	    W = W + a * p
	    r = r - a * Q * p
	    p = r + float((r.T * r) / (r_prev.T * r_prev)) * p
	return W




# 主函数
def main():
	m = 5
	data_size = 15
	data_range = math.pi * 2
	x0, y = generate_data(data_size,data_range)
	x = Vandermonde_x(x0,m)
	# w = least_square(x,y)
	# w = least_square_reg(x,y,0.1)
	w = gradient_descent(x,y,0.01)
	print(w)
	test(x0,y,w)



if __name__ == '__main__':
		main()

