//输入队伍个数后,自动生成二维0,1数组;比赛成绩有积分决定,积分相同则看两者之间的胜者;
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    int c =0;
    printf("请输入队伍个数\n");
    scanf("%d",&n);
    int a[n][n];
    int b[n] ;
    for(i=0; i<n; i++)
       {
           for(j = 0; j<n; j++)
        {
            a[i][j] =rand()%2;
            printf("%d ",a[i][j]);
        }
        printf("\n");
       }
       for(i=0;i<n;i++)
        {b[i] =0;
        for(j= 0;j<n;j++)
         b[i] += a[i][j];}

         for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            {if(b[j]>b[c])
                c = j;
                else if(a[j][c] &&(b[j]==b[c]))
                    c = j;
                }
        b[c] = -1;
        printf("p%d--->",c+1);
    }
    printf("结束;");
    return 0;
}
