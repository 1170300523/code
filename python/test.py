def t(n):
    if n == 1:
        return 1
    else:
        return n*t(n-1)


print(t(7))
