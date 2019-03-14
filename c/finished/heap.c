#include <stdio.h>
#define MAX_SIZE 200

typedef struct 
{   
    int task;
    int weight;
}element_type;

typedef struct 
{
    element_type ele[MAX_SIZE];
    int num;
}heap;

heap initial_heap(heap h)
{    int i;
    h.num = 0;
    for(i =0;i< MAX_SIZE;i++)
      {  h.ele[i].task = -1;
        h.ele[i].weight = -1;
    }
    return h;
}

void insert_heap(heap *h,int task,int weight)
{
    int i;
    if(h->num < MAX_SIZE -1)//尾插法,不断上朔
    {   
        i  = h->num +1;
        h->num ++;
        while(i != 1 &&  h->ele[i/2].weight < weight)
        {
            h->ele[i].weight = h->ele[i/2].weight;
            h->ele[i].task  = h->ele[i/2].task;
            i = i/2;
        }
        h->ele[i].weight = weight;
        h->ele[i].task = task;
    }
}

int  delet_heap(heap *h)
{
    int parent =1,child =2,ele,temp_weight,temp_task;
    if(h->num)
    {
        ele = h->ele[1].weight;
        temp_task = h->ele[h->num].task;
        temp_weight = h->ele[h->num --].weight;
        while(child <= h->num)
        {
            if(child<h->num && h->ele[child].weight < h->ele[child + 1].weight) child++;
            if(temp_weight >= h->ele[child].weight)break;
            h->ele[parent].weight =h->ele[child].weight;
            h->ele[parent].task  = h->ele[child].task;
            parent = child;
            child *= 2;     
        }
        h->ele[parent].weight = temp_weight;
        h->ele[parent].task = temp_task;
        return ele;
    }
    else return -1;
}

int read_dat(heap *h)
{
    FILE *fp;
    fp = fopen("task.dat","r");
    int task,weight,n = 0;
   
     while(fscanf(fp,"%d %d",&task,&weight) == 2)
    {insert_heap(h,task,weight );
        n++;
    }
    fclose(fp);
return n;
}
int main()
{   heap h;
    int i,n;
    h = initial_heap(h);
    n =  read_dat(&h); 
    printf("The order of task:\n\n");
    for( i =1;i<=n;i++)
    {
        printf("task: %d   weight: %d\n",h.ele[1].task ,h.ele[1].weight);
        delet_heap(&h);
    } 
        
    return 0;
}