#include <stdio.h>
#include <stdlib.h>

void exchange(int *x,int *y)
{
    int temend = *x;
    *x =*y;
    *y = temend;
}

void tf_sort(int arr[],int size)
{
        int begin = 0,end = size -1,i=0;
        while((begin != end) && (i != end))
        {
            while(arr[begin] ==0){begin++;i++;}
            while(arr[end] == 2)end--;
            while(arr[begin] ==2){exchange(&arr[begin],&arr[end]);end = end-1;}
            while(arr[end] == 0){exchange(&arr[begin],&arr[end]);begin = begin + 1;i++;}
            while(arr[end] ==1 &&arr[begin] ==1 && end != begin && i != end)
                {

                    if(arr[i]==0)exchange(&arr[begin],&arr[i]);
                    else if(arr[i] ==2 )exchange(&arr[end],&arr[i]);
                    else i++;
                }
        }
        for(i =0;i<size;i++)printf("%d ",arr[i]);

}
int main()
{
    int arr[100] = {0};
    int i;
    for(i=0;i<100;i++)arr[i] = rand()%3;
    tf_sort(arr,100);
    return 0;
}
