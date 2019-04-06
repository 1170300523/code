def gray(n):
    s = ["0", "1"]
    for i in range(n-1):
        a = [(item + "0") for item in s]
        b = [(item + "1") for item in s]
        s = a + b[::-1]
    return [int(item, 2) for item in s]


print(gray(int(input("input n:"))))
