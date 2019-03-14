#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],i;
    int maxn = 0;
    int minn = 0;
    for(i=0; i<100; i++)
    {
        a[i] = rand();
    }
    for(i=0; i<99; i++)
    {
        if(a[maxn]<a[i])
            maxn  = i;

        if(a[minn]>a[i])
            minn = i;
    }
    printf("max = %d\ti =%d\n",a[maxn],maxn);
    printf("min  = %d\ti =%d\n",a[minn],minn);

    return 0;
}

