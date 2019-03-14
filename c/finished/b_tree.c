#include <stdio.h>
#include <stdlib.h>

//结构体:  树结点
typedef struct treenode
{   char data;
    struct treenode *left,*right;
} T;

//结构体: 用于后序非递归遍历中,带一个树节点和一个标志变量
typedef struct t_stack
{   T *p;
    int flag;
} t_stack;

T   *s[100],*p;

//建立一个树,以先序建立,输入一个指针,返回一个指针
T *tree_creat(T *t)
{
    char ch;
    scanf("%ch",&ch);
    getchar();
    if(ch=='^')t = NULL;
    else
    {   t = (T *)malloc(sizeof(T));
        t->data = ch;
        printf("input %c's leftson:\n",t->data);
        t->left = tree_creat(t->left);
        printf("input %c's rightson:\n",t->data);
        t->right = tree_creat(t->right);
    }
    return t;
}

//递归遍历,输入一个指向树根的指针和一个数,n为模式选择,1为先序,2为中序,3为后序
void order(T *tree,int n)
{   if(tree)
    {  n==1? printf("%c -> ",tree->data ):order(tree->left,n);
       n==1?order(tree->left,n):(n==2?printf("%c -> ",tree->data) :order(tree->right,n));
       n==3?printf("%c -> ",tree->data ):order(tree->right,n);
    }
}

//层遍历,输入一个指向树根的指针
void level_order(T *t)
{   if(t);
    {   T   *q[100],*p;
        int front = 0,rear = 0;
        q[++rear] = t;
        while(front!=rear && rear<100)
        {   p = q[++front];
            printf("%c -> ",p->data);
            if(p->left)q[++rear] = p->left;
            if(p->right)q[++rear] = p->right;
        }
    }
}

//n为1:前序非递归 ,n为2:中序非递归
void norder(T *t,int n)
{   int top = -1;
    while(t || top!=-1)
    {   while(t)
        {   if(n==1)printf("%c -> ",t->data );
            s[++top] = t;
            t = t->left;
        }
        if(top!=-1)
        {   t = s[top--];
            if(n ==2)printf("%c -> ",t->data );
            t = t->right;
        }
    }
}

//后序非递归
void pos(T *t)
{   int top =-1;
    t_stack s[100];
    while(t || top != -1)
    {   while(t)
        {   s[++top].p = t;
            s[top].flag = 1;
            t = t->left;
        }
        while(top != -1 && s[top].flag ==2) printf("%c -> ",s[top--].p->data);
        if(top != -1)
        {   s[top].flag = 2;
            t = s[top].p->right;
        }
    }
}

//判断是否为完全二叉树
int complete_tree(T *t)
{   if(t)
    {   int front = 0,rear = 0;
        s[++rear] = t;
        while(front!=rear)
        {   p = s[++front];
            if(p->left)     s[++rear] = p->left;
            if(p->right)    s[++rear] = p->right;
            //若某节点只有右结点而没有左节点,那么树为非完全二叉树
            if(!(p->left)&&p->right) return 0;
            //如果一节点左右结点中有一个缺失,则后一个结点不能有子节点,否则为非完全二叉树
            if((front != rear) && ((!p->left||!p->right)&&(s[front+1]->left||s[front+1]->right)) )  return 0;
        }
       return 1;
    }
    else return 0;
}

int main()
{
    T *t = NULL;
    printf("input root:\n");
    t = tree_creat(t);
    printf("\n\n递归法后序: \t");
    order(t,1);
    printf("\n\n递归法后序: \t");
    order(t,2);
    printf("\n\n递归法后序: \t");
    order(t,3);
    printf("\n\n非递归前序:\t");
    norder(t,1);
    printf("\n\n非递归中序:\t");
    norder(t,2);
    printf("\n\n非递归后序:\t");
    pos(t);
    printf("\n\n递归法层序: \t");
    level_order(t);
    printf("\n\n完全二叉树? \t");
    complete_tree(t) ? printf("是"):printf("否");
    return 0;
}
//测试样例
//m g ^ ^ n ^ ^
//m g k ^ ^ ^ l ^ ^
//m g k ^ ^ t u ^ ^ v ^ ^ l ^ b ^ ^