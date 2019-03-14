/*test info

13
0 1 6
0 2 2
1 3 3
1 4 5
1 5 3
3 6 2
4 7 3
5 8 4
2 8 4
8 9 2
7 10 2
8 10 2
9 10 2

*/
#include <stdio.h>
#include <stdlib.h>
#define size 11
int main()
{
    int act[size][size] = {0};
    int i,j,n,d;
    printf("input the number of edge:\n");
    scanf("%d",&n);
    printf("input info:");
    while(n--)
    {
        scanf("%d %d %d",&i,&j,&d);
        act[i][j] = d;
    }
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
            printf("%d  ",act[i][j]);
        printf("\n");
    }

    int early[size]= {0},late[size],max,min;
    for(early[0]=0,i=1; i<size; i++)
    {
        for(j=0,max = 0; j<size; j++)
            if(act[j][i]&&(act[j][i] + early[j] > max))
                max = act[j][i] + early[j];

            early[i] = max;
        printf("%2d %2d\n",i,early[i]);
    }

    for(late[size-1]=early[size -1],i=size -1;i>=0;i--)
    {
        for(min=early[size-1],j=0;j<size;j++)
            if(act[i][j]&&(late[j] - act[i][j] < min))
            min = late[j] - act[i][j];
        late[i] =min;
        printf("%d %d\n",i,late[i]);
    }


    printf("important way is:\n start --> ");
    for(i=1;i<size;i++)
        if(early[i]==late[i])printf("%c -->",'A'+i -1);
        printf("end");




    return 0;
}
