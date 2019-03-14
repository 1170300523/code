/*
*author: liguoqing 1170300523
*time  : 2018-12-15
*function: two sort:pop sort and quick sort
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exchange(int *x,int *y)
{
    int temp = *x;
     *x = *y;
     *y = temp;
}
void pop_sort(int arr[],int size)
{
    for(int i=0;i<size -1;i++)
        for(int j=size-1;j>i;j--)
            if(arr[i] > arr[j])
                exchange(&arr[i],&arr[j]);
}

////return a mid value,used in fast_sort
int partition(int arr[],int begin,int end)
{   int i = begin -1, j ;

    for(j =begin;j<end;j++)
        if(arr[j] < arr[end])
            exchange(&arr[++i],&arr[j]);

    exchange(&arr[++i],&arr[end]);

    return i;

}
void fast_sort(int arr[],int begin, int end)
{
    if(begin < end)
    {
        int mid = partition(arr,begin,end);
        fast_sort(arr,begin,mid -1);
        fast_sort(arr,mid+1,end);
    }
}
int main()
{   int size =10000;      //choose a size you like
    int i,arr[size],b[size];
    for( i=0;i<size;i++)arr[i] = rand();
    for( i=0;i<size;i++)b[i] = arr[i];
    for(size =10;size<=100000;size*=10)
    {
    time_t s,t,begin,end;

    s = clock();
    pop_sort(arr,size);
    t = clock();


    for( i=0;i<size;i++)arr[i] = b[i];

    begin = clock();
    fast_sort(arr,0,size);
    end = clock();

    printf("规模:%d\n快速: %ld,冒泡: %ld\n\n",size,end - begin ,t - s);}

    return 0;
}
