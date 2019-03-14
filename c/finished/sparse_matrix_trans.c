# include<stdio.h>
#include <stdlib.h>
# include<malloc.h>


typedef struct//定义三元组
{
    int x;  //横坐标
    int y;  //纵坐标
    int v;   //值
}Tri;

//定义稀疏矩阵的顺序存储结构
typedef struct
{
    Tri * data;  //存储三元组空间的基址
    int row;  //矩阵行数
    int col;  //矩阵列数
    int num;  //非0元素个数
}Maxi;

void MaxiPrint(Maxi M);  //矩阵打印
Maxi TransportFast(Maxi M);  //2)快速转置

int main(void)
{
    Maxi M;
    int row, col, num;  //行、列、非0个数
    int i, x, y, v;

    printf("input the  raw and column of matrix ,and number of elements which aren't 0: \n");
    scanf("%d%d%d", &row, &col, &num);

    M.row = row;
    M.col = col;
    M.num = num;
    M.data = (Tri *)malloc(sizeof(Tri) * num);  //开辟三元组存储空间

    //输入矩阵的三元组值
    printf("Notice: the input three tuples are arranged in line and then arranged.!!!!\n");

    for(i = 0; i < num; i++)  //矩阵赋值
    {
        printf("The %dth three tuple values of the input matrix are x, y, v:\n", i+1);
        scanf("%d%d%d", &x, &y, &v);
        M.data[i].x = x;
        M.data[i].y = y;
        M.data[i].v = v;
    }

    MaxiPrint(M);

    //2)快速转置
    Maxi F = TransportFast(M);
    MaxiPrint(F);

    return 0;
}

//打印矩阵M
void MaxiPrint(Maxi M)
{
    int i, j, k;
    int flag;

    for(i = 0; i < M.row; i++)
    {
        for(j = 0; j < M.col; j++)
        {
            flag = 0;  //非0标记

            for(k = 0; k < M.num; k++)
            {
                if(i == M.data[k].x && j == M.data[k].y)
                {
                    printf("%d  ", M.data[k].v);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("0  ");
            }
        }
        printf("\n");
    }

    printf("\n");
}


//2)快速转置
Maxi TransportFast(Maxi M)
{
    int i, q, col;
    Maxi T;
    T.row = M.col;
    T.col = M.row;
    T.num = M.num;
    T.data = (Tri *)malloc(sizeof(Tri) * T.num);

    //记录M中每列中非0元素的个数（即，T中每行元素的个数）
    int * num = (int *)malloc(sizeof(int) * M.col);

    for(i = 0; i < M.col; i++)  //初始化
    {
        num[i] = 0;
    }

    for(i = 0; i < M.num; i++)
    {
        num[M.data[i].y] ++;
    }

    //T中每行元素的的第一个非0元素在T.data的位置
    int * index = (int *)malloc(sizeof(int) * T.row);
    index[0] = 0; //T中第0行元素在T.data中的位置

    for(i = 1; i < T.row; i++)
    {
        index[i] = index[i - 1] + num[i - 1];
        /*这里详细解释: index是指data[]数组的下标;
        第x行第一个元素data数组序号 = (x -1)行的第一个非0元素的data数组序号 + (x -1)的所有非0元素个数*/
    }

    //遍历M,转置矩阵T每行元素，按列的顺序出现
    for(i = 0; i < M.num; i++)
    {
         col = M.data[i].y;  //M.data元素的列号
         q = index[col];

         T.data[q].x = M.data[i].y;
         T.data[q].y = M.data[i].x;
         T.data[q].v = M.data[i].v;

         index[col] ++;
     }

     return T;
 }

 /*
 6 7 8
 1 2 3
 1 3 2
 1 4 2
 2 4 1
 3 1 4
3 5 2
4 4 4
4 5 1
*/
