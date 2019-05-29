import numpy as np
import time
m = 3
n = 3
max_deep = 10


# 将输入的列表转为二维数组
def list2arr(l, m, n):
    l = np.asarray(l)
    l = l.reshape((m, n))
    return l


# 检查错误位置的个数
def check(a, b):
    dif = 0
    for i in range(m):
        for j in range(n):
            if a[i][j] != b[i][j]:
                dif += 1
    return dif


def move(a,flag, s):  # flag 为选定节点的上一步操作, 避免上下循环一直在栈中
    x, y = find_point(a)
    a0 = a
    origin = check(a,b)
    m1, m2, m3, m4 = [origin]*4
    # now = 1
    a1, a2, a3, a4 = [a]*4
    aa = []
    if x > 0 and flag != 2 : # 向上移动
        a[x][y], a[x-1][y] = a[x-1][y], a[x][y]
        aa.append([a,1,check(a,b)])
    if x < m -1 and flag != 1: # 向下移动
        a = a0
        a[x][y], a[x+1][y] = a[x+1][y], a[x][y]
        aa.append([a,2,check(a,b)])
    if y > 0 and flag != 4: # 向左移动
        a = a0
        a[x][y], a[x][y-1] = a[x][y-1], a[x][y]
        aa.append([a,3,check(a,b)])
    if y < n-1 and flag != 3: # 向右移动
        a = a0
        a[x][y], a[x][y+1] = a[x][y+1], a[x][y]
        aa.append([a,4,check(a,b)])

    return aa





# 找到可移动点的坐标
def find_point(a):
    for i in range(m):
        for j in range(n):
            if a[i][j] == 0:
                return i,j
    return -1,-1



# 深度优先搜索
def DFS(a,b):
    s = [[a,0]]
    while s != []:
        k = s.pop(-1)
        deep = 0
        if check(k[0], b) == 0:
            print("DFS succeed")
            return 1
        else:
            aa = move(k[0], k[1], s)
            for i in aa:
                mm = [j[2] for j in aa]
                index = mm.index(max(mm))
                s.append(aa[index])
                # mm.pop(index)
                # aa.pop(index)
    print("DFS failed")

# 广度优先搜索
def BFS(a,b): # TODO
    s = [[a, 0]]
    while s != []:
        k = s.pop(0)
        if check(k[0], b) == 0:
            print("BFS succeed")
            return 1
        else:
            aa = move(k[0], k[1], s)
            for i in aa:
                mm = [j[2] for j in aa]
                index = mm.index(min(mm))
                s.append(aa[index])
                mm.pop(index)
                aa.pop(index)
    print("BFS failed")

# 爬山法
def Hill_Climbing(a,b): # todo
    s = [[a, 0]]
    while s != []:
        k = s.pop()
        if check(k[0], b) == 0:
            print("hill succeed")
            return 1
        else:
            aa = move(k[0], k[1], s)
            mm = [j[2] for j in aa]
            index = mm.index(max(mm))
            s.append(aa[index])
    print("hill failed")


# 最佳优先方法搜索
def  Best_First(a,b):
    s = [[a, 0]]
    while s != []:
        k = s.pop()
        if check(k[0], b) == 0:
            print("best-first succeed")
            return 1
        else:
            aa = move(k[0], k[1], s)
            mm = [j[2] for j in aa]
            index = mm.index(max(mm))
            s.append(aa[index])

    print("best-first failed")



if __name__ == '__main__':
    a = [2, 3, 0, 1, 8, 5, 7, 4 ,6]
    b = [1, 2, 3, 8, 0, 4, 7, 6, 5]
    a = list2arr(a, 3, 3)
    b = list2arr(b, 3, 3)

    td = time.clock()
    DFS(a,b)

    tb  = time.clock()
    BFS(a,b)

    th = time.clock()
    Hill_Climbing(a,b)

    tf = time.clock()
    Best_First(a,b)
    te = time.clock()

    print("DFS: " + str((tb - td)*1000)+"ms")
    print("BFS: " + str((th - tb)*1000)+"ms")
    print("HILL: " + str((tf - th)*1000)+"ms")
    print("BEST-FIRST: " + str((te - tf)*1000)+"ms")


