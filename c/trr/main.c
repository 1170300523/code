#include <stdio.h>

#define SIZE 8
#define MAX 2147483647

void creat_loser_tree(int *t, int a[8][4] )
{
    int i;
    for ( i = 0; i < SIZE; i++)t[i] = SIZE;//初始化
    for ( i = SIZE-1; i >= 0; i--) adjust_loser_tree(t,a,i);//调整叶子节点，顺序不能反
}

void adjust_loser_tree(int t[],int a[8][4] ,int i)
{
for(int f = (i + SIZE) / 2;f > 0;f /= 2)
		if (a[i][0] > a[t[f]][0])
        {
			int temp = i;
        i = t[f];//i 保存 胜利者，继续 比较
			t[f] = temp;//有新的败者了.
		}
	t[0] = i;
}

int main()
{
    int a[9][4] = {{10,15,16,MAX},{9,20,38,MAX},{20,20,30,MAX},{6,15,25,MAX},
        {8,15,20,MAX},{9,11,16,MAX},{90,100,110,MAX},{17,18,20,MAX},{-MAX,-MAX,-MAX,-MAX}};
    int t[SIZE +1],i;//t为败者树,它记录失败者id

    creat_loser_tree(t,a);
    while(a[t[0]][0] != MAX)
    {
        printf("%d\n",a[t[0]][0]);
        for(i = 0;i<4;i++)a[t[0]][i] =a[t[0]][i+1];
        adjust_loser_tree(t,a,t[0]);
    }
    return 0;
}
