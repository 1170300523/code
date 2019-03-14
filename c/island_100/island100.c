#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define number 100
#define n 100
struct island
{
    int x,y;
    int distance;

};

void Prim(int C[n][n] )
{
    int LOWCOST[n];
    int CLOSEST[n];
    int
    i,j,k;
    int min;
    int min_sum=0;
    for( i=1; i<n; i++ )
    {
        LOWCOST[i] = C[0][i];
        CLOSEST[i] = 0;
    }
    printf("short way is:\n");
    for( i = 1; i < n; i++ )
    {
        min = LOWCOST[i];
        k = i;
        for( j = 1; j < n; j++ )
            if ( LOWCOST[j] < min )
            {
                min = LOWCOST[j] ;
                k=j;
            }

             printf("%d %d\t",k,CLOSEST[k]);
             min_sum += C[k][CLOSEST[k]];
        LOWCOST[k] = 3000 ;
        for ( j = 1; j < n; j++ )
            if ( C[k][j] < LOWCOST[j] && LOWCOST[j] < 3000)
            {
                LOWCOST[j]=C[k][j];
                CLOSEST[j]=k;
            }
    }
    printf("\n\nleast price is is %d\n\n",min_sum *100);
}
int main()
{
    int i,j;
    struct island island[100];
    for(i=0; i<number; i++)
    {
        island[i].x = rand()%1001;
        island[i].y = rand()%1001;
       // printf("%d , %d\n",island[i].x,island[i].y);
    }

    int distance[number][number];
    for(i=0; i<number; i++)
        for(j=0; j<number; j++)
            distance[i][j] = sqrt( pow((island[i].x - island[j].x),2)+ pow((island[i].y - island[j].y),2));

    Prim(distance);

    return 0;
}
