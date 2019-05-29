 # 贪心策略: 先满足贪婪因子小的孩子
def Biscuit_allocation():
    k = 0
    s = list(map(int, input("input s: ").split()))
    f = list(map(int, input("input f: ").split()))
    s = sorted(s)
    f = sorted(f)
    while len(s) and s[0]<f[-1]:
        for j in f:
            if j >= s[0]:
                f.remove(j)
                s.remove(s[0])
                k += 1
                break
    return k

print(Biscuit_allocation())



