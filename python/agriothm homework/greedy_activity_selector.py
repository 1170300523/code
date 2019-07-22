# f = input().split(" ")
# s = input().split(" ")


def greedy_activity_selector(s, f):
    A = {1}
    i = 0
    for j in range(1,len(s)):
        if s[j] > f[i]:
            A.add(j+1)
            i = j
    return A


# get a list
s = list(map(int, input("input s: ").split()))
f = list(map(int, input("input f: ").split()))

print(greedy_activity_selector(s, f))


