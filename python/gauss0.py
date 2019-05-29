import numpy as np 


# 一、 Gauss 列主元消去法
def gauss(n,a,b):
    x = np.zeros((n + 1, 1))
    for k in range(1,n):
        a_pk = max(abs(a[k:,k]))
        p = list(a[:,k]).index(a_pk)
        if(a_pk == 0):
            return -1
        if(p != k ):
            a[p],a[k] = np.copy(a[k]),np.copy(a[p])
            b[p],b[k] = np.copy(b[k]),np.copy(b[p])
        for i in range(k+1,n+1):
            m = a[i,k]/a[k,k]
            for j in range(k+1,n+1):
                a[i,j] -=   a[k,j] * m
            b[i,0] -= b[k,0] * m

    if(a[n,n] == 0):
         return -1

    x[n,0] = b[n,0]/a[n,n]
    for k in range(n-1,0,-1):
        s = 0
        for j in range(k+1,n+1):
            s += a[k,j] * x[j,0]
        x[k,0] = (b[k,0] - s)/a[k,k]
    return x[1:,:]


# 二、显式相对 Gauss 列主元消去法
def ob_gauss(n,a,b):
    x = np.zeros((n + 1, 1))
    for k in range(1,n):
        for i in range(k,n+1):
            s = max(abs(a[i,k:]))
            if(s == 0):
                return -1
            b[i,0] /= s
            for j in range(k,n+1):
                a[i,j] /= s

        a_pk = max(abs(a[k:,k]))
        p = list(abs(a[:,k])).index(a_pk)
        if(a_pk == 0):
            return -1
        if(p != k ):
            a[p],a[k] = np.copy(a[k]),np.copy(a[p])
            b[p],b[k] = np.copy(b[k]),np.copy(b[p])
        for i in range(k+1,n+1):
            m = a[i,k]/a[k,k]
            for j in range(k+1,n+1):
                a[i,j] -=   a[k,j] * m
            b[i,0] -= b[k,0] * m
    if(a[n,n] == 0):
         return -1

    x[n,0] = b[n,0]/a[n,n]
    for k in range(n-1,0,-1):
        s = 0
        for j in range(k+1,n+1):
            s += a[k,j] * x[j,0]
        x[k,0] = (b[k,0] - s)/a[k,k]
    return x[1:,:]


# 三、 隐式相对 Gauss 列主元消去法
def pp_gauss(n,a,b):
    x = np.zeros((n + 1, 1))
    for k in range(1,n):
        for i in range(k,n+1):
            s = max(abs(a[k:,k]))
            if(s==0):
                return -1
            p = list(a[k:,k]).index(s) + k
            if(p != k ):
                a[p],a[k] = np.copy(a[k]),np.copy(a[p])
                b[p],b[k] = np.copy(b[k]),np.copy(b[p])
        for i in range(k+1,n+1):
            m = a[i,k]/a[k,k]
            for j in range(k+1,n+1):
                a[i,j] -=   a[k,j] * m
            b[i,0] -= b[k,0] * m

    if(a[n,n] == 0):
         return -1

    x[n,0] = b[n,0]/a[n,n]
    for k in range(n-1,0,-1):
        s = 0
        for j in range(k+1,n+1):
            s += a[k,j] * x[j,0]
        x[k,0] = (b[k,0] - s)/a[k,k]
    return x[1:,:]




def main():
    n = int(input("input n:\t")) 
    a = np.zeros((n+1,n+1))
    b = np.zeros((n+1,1))
    x = np.zeros((n+1,1))

    for i in range(1,n+1):
        b[i] = input("\nb["+ str(i) +"]:\t")

    for i in range(1,n+1):
        for j in range(1,n+1):
            a[i][j] = input("\na["+str(i)+"]["+str(j)+"]:\t")

    choose = int(input("\nChoose model: 1.gauss 2.pp_gauss 3. ob_gauss\n"))
    print("\nx = ")
    if choose ==1:
        print(gauss(n,a,b))
    elif choose == 2:
        print(pp_gauss(n,a,b))
    else:
        print(ob_gauss(n,a,b))

if __name__ == '__main__':
    main()