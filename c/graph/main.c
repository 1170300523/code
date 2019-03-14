/*
author:     1170300523  liguoqing
data  :     2018-12-3
function:   graph's creat and search
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100

//struct of adjacency matrix node
typedef struct graph_node
{
    int flag;//connected ?
    int visit;

} vertex;

//struct of adjacency list node
typedef struct node
{
    int vertex;//which vertix connected
    int visit;
    struct node *next;

} list;

//store input info
void input_info(int m,int n,int info[][2])
{
    int i,j;
    printf("input the number of vertex and edge:\n");
    scanf("%d %d",&m,&n);
    while(n--)
    {
        printf("input in and out \n");
        scanf("%d %d",&i,&j);
        info[n][0] = i;
        info[n][1] = j;
    }
}

void read_file(int *m,int *n,int info[][2])
{
    FILE *fp;
    //fp =fopen("info.txt","r");
    fp =fopen("info2.txt","r");
    if(!fp)
    {
        printf("open failed!\n");
        return ;
    }
    fscanf(fp,"%d %d",m,n);
    int k = *n;
    while(k--)
        fscanf(fp,"%d %d",&info[k][0],&info[k][1]);


}
//use adjacency matrix to creat graph
void creat_graph_matrix(int m,int n,vertex g[][MAX_VERTEX],int info[][2])
{
    int i,j;
    //init matrix
    for( i = 0; i < m; i++)
        for( j = 0; j < m; j++)
        {
            g[i][j].flag = 0;
            g[i][j].visit = 0;
        }

    //input info
    while(n--)
    {
        i = info[n][0];
        j = info[n][1];
        g[i-1][j-1].flag = 1;
        g[j-1][i-1].flag = 1;
    }

    //print info of adjacency matrix
    printf("\nadjacency matrix is:\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%d  ",g[i][j].flag );
        printf("\n");
    }

}

//use adjacency list to creat graph
void creat_graph_list(int m,int n,list  l[],int info[][2])
{

    int i,j;

    for(i=0; i<m; i++)
    {
        l[i].vertex = i+1;
        l[i].visit = 0;
        l[i].next = NULL;
    }

    list *temp =NULL,*p = NULL;
//input info
    while(n--)
    {
        i = info[n][0];
        j = info[n][1];
        temp = (list *)malloc(sizeof(list));
        temp->next = l[i - 1].next;
        l[i - 1].next = temp;
        temp->vertex = j;

        temp = (list *)malloc(sizeof(list));
        temp->next = l[j - 1].next;
        l[j - 1].next = temp;
        temp->vertex = i;

    }

//print info of adjacency list
    printf("\n\nadjacency list is:\n");
    for(i=0; i<m; i++)
    {
        for(p = &l[i]; p; p = p->next)
            printf("%d->",p->vertex );
        printf("\n");
    }

}

//convert  adjacency matrix to adjacency list
void matrix_to_list(list l[],vertex g[][MAX_VERTEX],int m)
{
    list *temp;

    int i,j;
    for(i=0;i< m;i++)
        for(j=0;j<m;j++)
        if(g[i][j].flag)
    {
        temp = (list *)malloc(sizeof(list));
        temp->next = l[i].next;
        l[i].next = temp;
        temp->vertex = j;
    }
}

//convert  adjacency list to adjacency matrix
void list_to_matrix(list l[],vertex g[][MAX_VERTEX],int m)
{
    list *p;
    int i,j;
    //init matrix
    for( i = 0; i < m; i++)
        for( j = 0; j < m; j++)
            g[i][j].flag = 0;

    for(i=0; i<m; i++)
    {
        for(p = &l[i]; p; p=p->next)
        {
            if(i !=p->vertex-1)
                g[i][p->vertex-1].flag = 1;
            if(i !=p->vertex-1)
                g[p->vertex-1][i].flag = 1;
        }
    }

    //print info of adjacency matrix
    printf("\nadjacency matrix is:\n\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%d  ",g[i][j].flag );
        printf("\n");
    }
}

void DFS_rec_matrix(vertex g[][MAX_VERTEX],int m,int i)
{
    //int j;
    printf("%d->",i + 1);
    for(int j = 0; j<m; j++)
        g[j][i].visit = 1;//mask i  has been visited
    for(int j = 0; j<m; j++)
    {
        if(g[i][j].flag && !g[i][j].visit)
            DFS_rec_matrix(g,m,j);
    }
}


void DFS_matrix(vertex g[][MAX_VERTEX],int m,int i)
{
    int j = 0,stack[MAX_VERTEX],top =-1;
    stack[++top] = i;
    for(j=0; top != -1; top--,j--)
        while(j<m)//j<m means before the end of cycle,we have found next number.
        {
            i = stack[top];
            if(!g[0][i].visit)
                printf("%d->",i + 1);
            for(j=0; j<m; j++)
                g[j][i].visit =1;
            for(j=0; j<m; j++)
                if(g[i][j].flag && g[i][j].visit == 0)
                {
                    stack[++top] = j;
                    break;//find the first  one and break
                }
        }


}

void BFS_matrix(vertex g[][MAX_VERTEX],int m,int i)
{
    int j,queue[100] = {0},front = 0,rear = 0;
    queue[++rear] = i ;
    while(rear != front)
    {
        i = queue[++front] ;
        if(!g[0][i].visit)
            printf("%d->",i + 1);
        for(j=0; j<m; j++)
            g[j][i].visit = 1;
        for(j=0; j<m; j++)
            if(g[i][j].flag && g[i][j].visit == 0)
                queue[++rear] = j ;
    }
}




void DFS_rec_list(list l[], int i)
{
    list *p = &l[i];
    if(!l[i].visit)printf("%d->",l[i].vertex);
    l[i].visit = 1;//mask i  has been visited
    for( p = p->next; p ; p = p->next)
    {
        i = p->vertex -1;
        if(!l[i].visit)DFS_rec_list(l,i);
    }

}


void DFS_list(list l[], int i)
{
    list  *p= &l[i];
    int stack[100],top = -1;
    stack[++top] = i;
    while(top != -1 )
    {
        for(; p&&!p->visit; p = &l[stack[top]])
        {
            printf("%d->",p->vertex);//print
            p->visit = 1;//mark
            for(p = p->next;p&&l[p->vertex -1].visit; p = p->next);
            if(p)stack[++top] = p->vertex - 1;
//            for(p = p->next; p; p = p->next)
//                if(!l[p->vertex - 1].visit)
//                {
//                    stack[++top] = p->vertex - 1;
//                    break;//find the first one haven't been visit
//                }
        }

        if(top--)for(p = &l[stack[top]];p&&l[p->vertex -1].visit; p = p->next);//top ==0 means top-- == -1,it's over
        if(p)p = &l[p->vertex -1];

    }
}

//
void BFS_list(list l[], int i)
{
    int j,queue[100] = {0},front = 0,rear = 0;
    queue[++rear] = i ;
    while(rear != front)
    {
        if(!l[queue[++front]].visit)
            printf("%d->",queue[front] + 1);
        l[queue[front]].visit = 1;
        list *p = &l[queue[front]];
        for(p=p->next; p; p=p->next)
            if(!l[p->vertex -1].visit)
                queue[++rear] = p->vertex -1;
    }
}

void init_list(list l[],int m)
{
    while(m--)
        l[m].visit = 0;
    printf("\n\n");
}
void init_matrix(vertex g[][MAX_VERTEX],int m)
{
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++)
            g[i][j].visit =0;
    printf("\n\n");

}
void graph()
{
    int m,n,j;//m is vertex ,n is edge,i j used in cycle
    int info[MAX_VERTEX][2];
    read_file(&m,&n,info);
    //input_info(&m,&n,info);

    list  l[m];
    vertex g[MAX_VERTEX][MAX_VERTEX];

    creat_graph_matrix(m,n,g,info);
    creat_graph_list(m,n,l,info);
    for(int i=1; i<=3; i++)
    {
        init_matrix(g,m);
        if(i==1)
            {printf("DFS_rec_matrix:\n");for(j=0;j<m && !g[0][j].visit;j++)printf("\n"),DFS_rec_matrix(g,m,j);}
        if(i==2)
           {
               printf("DFS_matrix:\n");for(j=0;j<m && !g[0][j].visit;j++)printf("\n"),DFS_matrix(g,m,j);
           }
        if(i==3)
            {printf("BFS_matrix:\n");for(j=0;j<m && !g[0][j].visit;j++)printf("\n"),BFS_matrix(g,m,j);}
    }
    for(int i=1; i<=3; i++)
    {
        init_list(l,m);
        if(i==1)
            {printf("DFS_rec_list:\n");for(j=0;j<m && !l[j].visit;j++)printf("\n"),DFS_rec_list(l,j);}
        if(i==2)
            {printf("DFS_list:\n");for(j=0;j<m && !l[j].visit;j++)printf("\n"),DFS_list(l,j);}
        if(i==3)
            {printf("BFS_list:\n");for(j=0;j<m && !l[j].visit;j++)printf("\n"),BFS_list(l,j);}
    }
}
int main()
{

    graph();
    return 0;
}


