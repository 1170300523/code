def candy_allocation():
    
    s = 1 # s为输出结果
    t = 1 # t为糖果数目
    max_dec = 0  #最大连续向下深度
    for i in  range(len(ratings)-1):
        if ratings[i] < ratings[i+1]:  #上升
            if max_dec > 1:  # 下潜超过1,补偿前面最高
               
                s = s + (max_dec + 1 ) + max_dec*(max_dec + 1)/2 
                t = 2 
            else:
                t += 1
                s = s + t + max_dec * (max_dec + 1) / 2
            max_dec = 0

        else:     # 下降
            max_dec += 1
            t = 1 # 初始化为1,保证下一次上升为最小的2
            if i ==0:
                s = 2

    if t < max_dec + 1: #最后一个需要补偿的最高点
        s += max_dec -1  # t ==1
    s = s + max_dec * (max_dec + 1) / 2
    return s 

candy_allocation()


