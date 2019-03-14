#include <stdio.h>
#include <stdlib.h>
#define NUM 1024
struct bst_node
{
int data;
int position;
struct bst_node *left,*right;
};
void my_binary_search(int arr[],int size,int target)
{   int start = 0,end = size;
    while(start < end )
    {
        if(target < arr[(start + end)/2])
            end = (start + end)/2 - 1;
        else if(target > arr[(start + end)/2])
            start = (start + end)/2 + 1;
        else
        {
            printf("target's postion is %dth",(start + end)/2 + 1 );
            return;
        }
    }
    printf("can find!");

}
int my_binary_search_count(int arr[],int size,int target)
{ int start = 0,end = size,count =1;
    while(start < end )
    {   //count++;
        if(target < arr[(start + end)/2])
            {end = (start + end)/2 - 1;count++;}
        else if(target > arr[(start + end)/2])
            {start = (start + end)/2 + 1;count++;}
        else
            return count;

    }
    return count;
}
/*use proorder traverse to print bst, the number will print as ascending order */
void traversal_sort_bst(struct bst_node *head)
{

    if(head->left)
        traversal_sort_bst(head->left);
    printf("%d\t",head->data);
    if(head->right)
         traversal_sort_bst(head->right);

}
/*inser a number into bst,and it insert at a leaf*/
void insert_bst(struct bst_node *head,int target,int i)
{
    struct bst_node *p = head,*np = NULL;
    np = (struct bst_node *)malloc(sizeof(struct bst_node));
    np->data = target;
    np->left = NULL;
    np->right = NULL;
    np->position = i + 1;

    while (p->left != np && p->right != np)/*stop when np has been arranged*/
    {
        if(target <= p->data)
        {
            if(p->left)
                p = p->left;    /*go on,because still has number to compare with it*/
            else
                p->left = np;   /*at the leaf ,next is NULL ,insert */

        }

        else
        {
            if(p->right)
                p = p->right;   /*go on*/
            else
                p->right = np;  /*at the leaf*/
        }
    }
}
void creat_bst(struct bst_node *head,int num[])
{

    head->data = num[0];   /*init bst root*/
    head->position = 1;
    head->left = NULL;
    head->right = NULL;

    for(int i=1; i<NUM; i++)    /*inser every number in the array to the bst*/
        insert_bst(head,num[i],i);

}
void search_bst(struct bst_node *head,int target)
{
    struct bst_node *p = head;
    while(p)
    {
        if(target < p->data)
        {
            if(p->left)
                p = p->left;
            else
                p = NULL ;    /*we have reach the leaf ,has no way to continue,
                so we don't find,set p to NULL to end the cycle*/
        }
        else if(target > p->data)
        {
            if(p->right)
                p = p->right;
            else
                p = NULL;   /*we have reach the leaf ,has no way to continue,
                so we don't find,set p to NULL to end the cycle*/
        }

        else   /*else means our target has been find his brother! return his brother's ad*/
        {
            printf("\nfind, position is %dth\n",p->position);
            return;
        }
    }
    printf("\ncan't find!\n");
}
int search_bst_count(struct bst_node *head,int target)
{
    struct bst_node *p = head;
    int count = 1;
    while(p)
    {   //count++;
        if(target < p->data)
        {   count++;
            if(p->left)
                p = p->left;
            else
                p = NULL;    /*we have reach the leaf ,has no way to continue,
                so we don't find,set p to NULL to end the cycle*/
        }
        else if(target > p->data)
        {   count ++;
            if(p->right)
                p = p->right;
            else
                p = NULL;   /*we have reach the leaf ,has no way to continue,
                so we don't find,set p to NULL to end the cycle*/
        }

        else   /*else means our target has been find his brother! return his brother's ad*/
        {   count ++;
            return count;
        }
    }
    return count;
}
void delete_bst(struct bst_node *head,int target)
{
    struct bst_node *p = head,*np = NULL;
    while(p)
    {
        if(target < p->data)
        {
            if(p->left)
                p = p->left;
            else
                break;          /*has reached the leaf but still hasn't find,
                                so break the cycle,end*/
        }
        else if(target > p->data)
        {
            if(p->right)
                p = p->right;
            else
                break;          /*has reached the leaf but still hasn't find,
                                so break the cycle,end*/
        }
        else        /*we find ,but how to delete */
        {
            if(!p->left && !p->right)   /*left and right both are NULL,just put it at leaf*/
                p = NULL;

            else if(!p->left)       /*right isn't NULL, let p = p->right to delete p*/
                p = p->right;
            else if(!p->right)      /*left isn't NULL, let p = p->left to delete p*/
                p = p->left;

            else            /*both aren't NULL,use right's small number to replace p*/
            {
                np = p->right;
                while(np->left)np = np->left;

                p->data = np->data;     /*replace target's info*/
                p->position = np->position;
                np = np->right;
            }

            printf("delete finished!");
            return;

        }
    }
    printf("\ncan't find!\n");
}
/*a function to use all function*/
void creat_data()
{
    int i,j,temp,a[NUM],b[NUM],c[NUM];
    int  aver_count = 0;
    struct bst_node head;
    for(i=0; i<NUM; i++)
    {
        a[i] = rand();
        b[i] = a[i];
    }
     for(i=0; i<NUM; i++)/* creat c[],every number in c[] can't find in a[]*/
    {   int flag = 1;
        while(flag)
        {
            c[i] = rand();
            for(j =0;j<NUM;j++)
                if(c[i]==a[j])break;
            if(j==NUM)flag =0;
        }
    }

    /*sort the data in a[],so we can use it in binary search*/
    for(i=0; i<NUM-1; i++)
        for(j=i+1; j<NUM; j++)
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

        while(j)
        { printf("\n1.search_use\n2.search_test\n");
          scanf("%d",&j);
                if(j==2)
{
        for(i=0;i<NUM;i++)
        aver_count += my_binary_search_count(a,NUM,b[i]);
    aver_count /= NUM;
    printf("binary search aver_count is: %d\n",aver_count);
    for(i=0;i<NUM;i++)
        aver_count += my_binary_search_count(a,NUM,c[i]);
    aver_count /= NUM;
    printf("fail:binary search aver_count is: %d\n\n",aver_count);


    creat_bst(&head,b);
    for(i=0;i<NUM;i++)aver_count += search_bst_count(&head,b[i]);
    aver_count /= NUM;
    printf("bst  search aver_count is: %d\n",aver_count);
    for(i=0;i<NUM;i++)aver_count += search_bst_count(&head,c[i]);
    aver_count /= NUM;
    printf("fail:bst  search aver_count is: %d\n\n",aver_count);

    creat_bst(&head,a);
    for(i=0;i<NUM;i++)aver_count += search_bst_count(&head,b[i]);
    aver_count /= NUM;
    printf("bst  search aver_count is: %d\n",aver_count);
    for(i=0;i<NUM;i++)aver_count += search_bst_count(&head,c[i]);
    aver_count /= NUM;
    printf("fail:bst  search aver_count is: %d\n\n",aver_count);

}

    else if(j==1)
    {
        printf("\nbinary search: input a number to find:\n");
    scanf("%d",&j);
    my_binary_search(a,NUM,j);
    creat_bst(&head,b);
    printf("\nbst search: input a number to find:\n");
    scanf("%d",&j);
    search_bst(&head,j);


    printf("do you want to see the  sorted data by bst :(1/0)\n");
    scanf("%d",&j);
    if (j)traversal_sort_bst(&head);

    printf("\nbst search: input a number to delete:\n");
    scanf("%d",&j);
    delete_bst(&head,j);

    }

        }

}
int main()
{
    creat_data();
    return 0;
}
