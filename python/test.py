def t(n):
    if n == 1:
        return 1
    else:
        return n*t(n-1)


for i in range(6,2,-1):
    print(i)

