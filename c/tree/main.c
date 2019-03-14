#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{   char data;
    struct treenode *left,*right;
} T;

typedef struct t_stack
{   T *p;
    int flag;
} t_stack;

T   *s[100],*p;

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

void order(T *tree,int n)
{   if(tree)
    {  n==1? printf("%c -> ",tree->data ):order(tree->left,n);
       n==1?order(tree->left,n):(n==2?printf("%c -> ",tree->data) :order(tree->right,n));
       n==3?printf("%c -> ",tree->data ):order(tree->right,n);
    }
}

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

int complete_tree(T *t)
{   if(t)
    {   int front = 0,rear = 0;
        s[++rear] = t;
        while(front!=rear)
        {   p = s[++front];
            if(p->left)     s[++rear] = p->left;
            if(p->right)    s[++rear] = p->right;
            if(!(p->left)&&p->right) return 0;
            if((front != rear) && ((!p->left||!p->right)&&(s[front+1]->left||s[front+1]->right)) )  return 0;
        }
       return 1;
    }
     return 0;
}

int main()
{
    T *t = NULL;
    printf("input root:\n");
    t = tree_creat(t);
    printf("\n\n递归法前序: \t");
    order(t,1);
    printf("\n\n递归法中序: \t");
    order(t,2);
    printf("\n\n递归法后序: \t");
    order(t,3);
    printf("\n\n\n非递归前序:\t");
    norder(t,1);
    printf("\n\n非递归中序:\t");
    norder(t,2);
    printf("\n\n非递归后序:\t");
    pos(t);
    printf("\n\n\n非递归层序: \t");
    level_order(t);
    printf("\n\n完全二叉树? \t");
    complete_tree(t) ? printf("是"):printf("否");
    return 0;
}
//m g ^ ^ n ^ ^
//m g k ^ ^ ^ l ^ ^
//m g k ^ ^ t u ^ ^ v ^ ^ l ^ b ^ ^
