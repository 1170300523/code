def candy_allocation(ratings):
        s = 0
        n = len(ratings)
        s += n
        tmp = [0] * n
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                tmp[i] = tmp[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                tmp[i] = max(tmp[i], tmp[i + 1] + 1)
        s += sum(tmp)
        return s




