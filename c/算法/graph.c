
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
    fp =fopen("info.txt","r");
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
    printf("\nadjacency list is:\n");
    for(i=0; i<m; i++)
    {
        for(p = &l[i]; p; p = p->next)
            printf("%d->",p->vertex );
        printf("\n");
    }

}

//convert  adjacency matrix to adjacency list
void matrix_to_list(int no[][2],list l[])
{


}

//convert  adjacency list to adjacency matrix
void list_to_matrix(list l[],int m)
{
    list *p;
    vertex g[m][m];
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
    printf("\nadjacency matrix is:\n");
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
    printf("%d -> ",i + 1);
    for(int j = 0; j<m; j++)
    {
        g[j][i].visit = 1;//mask i  has been visited
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
                    break;
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
        printf("%d->",i + 1);
        for(j=0; j<m; j++)
        {
            g[j][i].visit = 1;
            if(g[i][j].flag && g[i][j].visit == 0)
                queue[++rear] = j ;
        }
    }
}




void DFS_rec_list(list l[], int i)
{
    list *p = &l[i];
    if(!l[i].visit)
        printf("%d -> ",l[i].vertex);
    l[i].visit = 1;//mask i  has been visited
    for( p = p->next; p ; p = p->next)
    {
        i = p->vertex -1;
        if(!l[i].visit)
            DFS_rec_list(l,i);
    }

}

//void DFS_list(list l[], int i)
//{
//    list  *queue[MAX_VERTEX],*p= &l[i];
//    int top = -1,j,t =0;
//    queue[++top] = &l[i];
//
//    while(top != -1 )
//    {
//       while(!p->visit)
//       {j= queue[top]->vertex -1;
//        p = &l[j];
//        printf("%d->",p->vertex);
//        l[j].visit = 1;
//
//        for(p = p->next;p;p = p->next)
//            if(!l[p->vertex - 1].visit) queue[++top] = p;
//        j= queue[top]->vertex -1;
//        p = &l[j];
//       }
//       --top;
//       if(top != -1){j= queue[top]->vertex -1;
//
//        p = &l[j];}
//    }
//
//}


void DFS_list(list l[], int i)
{
    list  *p= &l[i];
    int stack[100],top = -1;
    stack[++top] = i;
    for(stack[++top] = i; top != -1 ; --top)
    {
        for(p = &l[stack[top]]; !p->visit; p = &l[stack[top]])
        {
            printf("%d->",p->vertex);
            l[stack[top]].visit = 1;
            for(p = p->next; p; p = p->next)if(!l[p->vertex - 1].visit)stack[++top] = p->vertex - 1;
        }
    }
}

//
void BFS_list(list l[], int i)
{
    int j,queue[100] = {0},front = 0,rear = 0;
    queue[++rear] = i ;
    while(rear != front)
    {
        printf("%d->",queue[++front] + 1);
        l[queue[front]].visit = 1;
        list *p = &l[queue[front]];
        for(p=p->next; p; p=p->next)
            if(!l[p->vertex -1].visit)
                queue[++rear] = p->vertex -1;
    }
}

int main()
{
    int m,n;//m is vertex ,n is edge,i j used in cycle
    int info[MAX_VERTEX][2];
    read_file(&m,&n,info);
    //input_info(&m,&n,info);

    list  l[m];
    vertex g[MAX_VERTEX][MAX_VERTEX];
    printf("%d %d--",m,n);


    //input_info(info,&m,&n);
    creat_graph_matrix(m,n,g,info);
    creat_graph_list(m,n,l,info);
    //list_to_matrix(l,m);
    //matrix_to_list(g,l);
    //DFS_rec_matrix(g,m,0);
    //DFS_matrix(g,m,0);
    //BFS_matrix(g,m,0);
    //DFS_rec_list(l,0);
    DFS_list(l,0);
    //BFS_list(l,0);

    return 0;
}

/*
test data:
4 3
4 2
4 3
1 4
*/
