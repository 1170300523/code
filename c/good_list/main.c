#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct  goods
{
    char name[20];
    char brand[20];
    float price;
    int   number;
    struct goods *next;
} goods;
int i,j,list_len;
void swap(goods *a,goods *b)
{
    char temp[20];

    strcpy(temp,a->brand);
    strcpy(a->brand,b->brand);
    strcpy(b->brand,temp);
    strcpy(temp,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,temp);

    float ex;
    ex = a->number;
    a->number = b->number;
    b->number = ex;

    ex = a->price;
    a->price = b->price;
    b->price = ex;
}
void sort_goods(goods *head)
{

    goods *p = head;
    goods  *px = p->next;

    for(; p->next!= NULL; p = p->next)
    {
        for(px = p->next; px !=NULL; px = px->next)
        {
            if(p->price > px->price)
                swap(p,px);
        }

    }
}

int  info_print(struct goods *head)
{
    if(head ==NULL)
    {
        printf("���ļ�");
        return(0);
    }
    sort_goods(head);
    goods *p = head;
    printf("\n�ҵ���\tƷ��\t�۸�\t����\n\n");
    do
    {
        printf("%s\t%s\t%.2f\t%d\t\n",p->name,p->brand,p->price,p->number );
        p = p->next;
    }
    while( p != NULL);
    return 0;
}

struct goods  *read_file(struct goods *head)
{
    FILE *fp;
    if(head ==NULL)
        head = (goods *)malloc(sizeof(goods));
    goods *p = head,*pnew = NULL;
    p->next =NULL;


    fp = fopen("goods_list.txt","r+");
    if(!fp)
    {
        printf("��ȡʧ��!!");s
        return 0;
    }
    fscanf(fp,"%d",&list_len);

    for(i=0; i<list_len; i++)
    {
        fscanf(fp,"%s",&p->name);
        fscanf(fp,"%s",&p->brand);
        fscanf(fp,"%f",&p->price);
        fscanf(fp,"%d",&p->number);
        if(i<list_len-1)
        {
            p->next = (goods *)malloc(sizeof(goods));
            p = p->next;
            p->next = NULL;
        }
    }
    info_print(head);

    fclose(fp);
    return head;
}


struct goods *add_goods(struct goods *head)
{

    struct goods *p = NULL,*pr =head;

    p = (struct goods *)malloc(sizeof(struct goods));
    if(p)
        printf("succeed!\n");
    if(head ==NULL)
    {
        printf("head is null\n");
        head = p;
    }
    else
    {
        while(pr->next != NULL)
        {
            pr = pr->next;
        }
        pr->next = p;

    }
    p->next = NULL;
    printf("��������������,Ʒ��,�۸�,����(�Կո���Ϊ���:\n");
    if(head ==NULL)
    {
        printf("!!!!!head is null\n");

    }
    scanf("%s %s %f %d",p->name,p->brand,&p->price,&p->number);
    return head;
}



void file_print(struct goods *head)
{
    sort_goods(head);
    FILE *fp;
    goods *p = head;
    fp = fopen("goods_list.txt","w");
    if(!fp)
    {
        printf("��ӡʧ��\n");
        exit(0);
    }
    printf("��ӡ�ɹ�!!\n");
    for(list_len =0; p != NULL; p = p->next,list_len ++);
    fprintf(fp,"%d\n",list_len++);
    for(list_len =0,p=head; p != NULL; p = p->next,list_len ++)
    {
        fprintf(fp,"%s\t%s\t%.2f\t%d\t\n",p->name,p->brand,p->price,p->number);

    }
    fclose(fp);
}
void menu(goods *head)
{
    int ch = 1;
    while(ch)
    {

        printf("\n\n\n\t\t\t\t\t\t--�ҵ��Ʒ����ϵͳ--\n\n\n");
        printf("\t1.����(���Ӳ�Ʒ��Ϣ)\n");
        printf("\t2.���(ɾ����Ʒ��Ϣ)\n");
        printf("\t3.��ʾ���в�Ʒ\n");
        printf("\t4.������Ʒ\n");
        printf("\t5.Ӫҵ��ʼ(���ļ�)\n");
        printf("\t6.Ӫҵ����(д�ļ�)\n");
        printf("\t7.�˳�\n");
        printf("\t----->������ִ�в���:\t");
        scanf("%d",&ch);
        switch(ch)
        {

        case 1:
            head = add_goods(head);
            break;
        case 2:
            del_goods(head);
            break;
        case 3:
            info_print(head);
            break;
        case 4:
            search_goods(head);
            break;
        case 5:
            head = read_file(head);
            break;
        case 6:
            file_print(head);
            break;

        case 7:
            exit(0);
        default:
            printf("�������!");
            break;
        }

        getchar();
    }

}
int search_goods(goods *head)
{
    goods *p = head;
    char str_in[20];
    printf("��������Ʒ����:\t");
    scanf("%s",&str_in);
    printf("%s\t%s",p->name,str_in);
    for(; p != NULL; p =p->next)
    {
        if(!strcmp(str_in,p->name))
        {
            printf("\n�ҵ���\tƷ��\t�۸�\t����\n\n");
            printf("%s\t%s\t%.2f\t%d\t\n",p->name,p->brand,p->price,p->number );
            return 0;
        }
    }
    printf("û���ҵ���ز�Ʒ!\n");
    return 0;
}

int  del_goods(goods *head)
{
    goods *p = head,*temp = NULL;
    char str_in[20];
    printf("��������Ʒ����:\t");
    scanf("%s",&str_in);
    for(; p->next != NULL; p =p->next)
    {
        if(!strcmp(str_in,p->next->name))
        {
            temp = p->next;
            p->next = p->next->next;
            free(temp);
            printf("�Ѿ�ɾ��\n");
            return 0;
        }
    }
    printf("ɾ��ʧ��,û���ҵ���ز�Ʒ!\n");
    return 0;
}




int main()
{

    goods *head = NULL;
    menu(head);
    return 0;
}
/*
q w 8 2
e r 4 5
d u 1 9
f g 5 6
q u 3 9
j i 0 8
i t 6 3
i u 77 0
i i 8 6
t t 1   1
*/
