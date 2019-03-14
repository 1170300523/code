#include <stdio.h>
#include <stdlib.h>

typedef  struct polynode
{
    float   coef;
    int     exp;
    struct poly     *next;

} poly;

void file_print(poly *head)
{
    poly *p = head;
    FILE *fp;
    fp = fopen("poly_list.txt","w");
    for(; p!=NULL; p = p->next)
    {
        fprintf(fp,"%f  %d,     ",p->coef,p->exp);
    }
    fclose(fp);
}

void file_read(poly *head)
{
    poly *p = head;
    FILE *fp;
    fp = fopen("poly_list.txt","r");
    while(1)
    {
        fscanf(fp,"%f  %d",&p->coef,&p->exp);
        if(getchar()== '\n')
            break;
        p->next = (poly *)malloc(sizeof(poly));
        p = p->next;
        p->next = NULL;

    }
    fclose(fp);
}

void poly_creat(poly *head)
{
    poly *p = head,*pr =NULL;
    float coef;
    int exp;
    p->next =NULL;
    printf("请输入多项式的每组系数和指数:\n");

    while(1)
    {
        do
        {
            scanf("%f %d",&coef,&exp);
        }
        while(coef == 0);

        p->coef = coef;
        p->exp =exp;
        if(getchar() == '\n')
            break;
        p->next = (poly *)malloc(sizeof(poly));
        p = p->next;
        p->next =NULL;

    }
    poly_sort(head);
    printf(" 多项式为:\n");
    poly_printf(head);


}

void swap(poly *a,poly *b)
{

    float ex_f;
    ex_f = a->coef;
    a->coef = b->coef;
    b->coef = ex_f;

    int ex;
    ex = a->exp;
    a->exp = b->exp;
    b->exp= ex;
}

void poly_printf(poly *head)
{
    if(head->coef == 0)
    {
        printf("no data !!!");
        return 0;
    }
    poly *p = head,*px =NULL;
    for(; p->next != NULL; p = p->next )
    {
        if(p->coef > 0 && p != head)
            printf(" + ");
        printf("%.2f*x^%d  ",p->coef,p->exp);
    }
    if(p->exp)
    {
        if(p->coef > 0)
            printf(" + ");
        printf("%.2f*x^%d \n\n  ",p->coef,p->exp);
    }
    else
    {
        if(p->coef > 0)
            printf(" + ");
        printf("%.2f\n\n ",p->coef,p->exp);
    }
}

void    poly_sort(poly  *head)
{
    if(head ==NULL )
    {
        printf("no data!\n");
        return 0;
    }
    else if(head->next == NULL)
    {
        printf("neednt sort\n");
        return 0;
    }
    poly *p = head;
    poly  *px = p->next,*pr = NULL;


    for(; p->next != NULL; p = p->next)
    {
        for(px = p->next; px != NULL;  px = px->next)
        {
            if(px->coef * px->coef <=0.0001)
                px->exp =0;
            if(p->coef  * p->coef<=0.0001)
                p->exp =0;

            if(p->exp < px->exp)
            {
                swap(p,px);

            }
            else if(p->exp == px->exp  )
            {
                p->coef +=  px->coef;
                px->coef =0;
                px->exp = 0;

            }
        }

    }



    for(p =head, px =p->next; p->next!=NULL; p=p->next)
    {

        if(px->coef == 0)
        {
            p->next = NULL;
            free(px);
            break;
        }
        px = px->next;
    }

}

void    poly_comp(poly *head)
{
    if(head->coef == 0)
    {
        printf("no data!");
        return 0;
    }
    float x;
    int i;
    printf("input:\n");
    scanf("%f",&x);
    poly *p = head;
    float ret,ans = 0;
    while(p != NULL)
    {
        ret = p->coef;
        for(i = 0; i < p->exp; i++)
            ret *= x;
        ans += ret;
        p =p->next;
    }
    printf("计算结果是 %f:\n",ans);
}
void    poly_add(poly *head_1,poly *head_2,poly *head_3)
{
    poly *p1 = head_1,*p2 = head_2,*p3 = head_3;
    while(1)
    {
        if(p1 == NULL && p2 == NULL )
            break;
        else if(p1 == NULL )
        {
            p3->coef = p2->coef;
            p3->exp = p2->exp;
            p2 = p2->next;
        }
        else if(p2 == NULL )
        {
            p3->coef = p1->coef;
            p3->exp = p1->exp;
            p1 = p1->next;
        }
        else
        {
            if(p1->exp > p2->exp)
            {
                p3->coef = p1->coef;
                p3->exp = p1->exp;
                p1 = p1->next;
            }

            else if(p1->exp < p2->exp)
            {
                p3->coef = p2->coef;
                p3->exp = p2->exp;
                p2 = p2->next;
            }

            else
            {
                p3->coef = p1->coef + p2->coef;
                p3->exp = p1->exp;
                p1 = p1->next;
                p2 = p2->next;
            }

//
        }

        if(p1 != NULL || p2!= NULL)
        {
            p3->next = (poly *)malloc(sizeof(poly));
            p3 = p3->next;
            p3->next = NULL;
        }

    }
    printf("\n和:\n");
    poly_sort(head_3);
    poly_printf(head_3);
}
void    poly_sub(poly *head_1,poly *head_2,poly *head_3)
{
    poly *p1 = head_1,*p2 = head_2,*p3 = head_3;
    while(1)
    {
        if(p1 == NULL && p2 == NULL )
            break;
        else if(p1 == NULL )
        {
            p3->coef = -p2->coef;
            p3->exp = p2->exp;
            p2 =p2->next;


        }
        else if(p2 == NULL )
        {
            p3->coef = p1->coef;
            p3->exp = p1->exp;
            p1 = p1->next;


        }
        else
        {
            if(p1->exp > p2->exp)
            {
                p3->coef = p1->coef;
                p3->exp = p1->exp;
                p1 = p1->next;
            }

            else if(p1->exp < p2->exp)
            {
                p3->coef = -p2->coef;
                p3->exp = p2->exp;
                p2 = p2->next;
            }

            else
            {
                p3->coef = p1->coef - p2->coef;
                p3->exp = p1->exp;
                p1 = p1->next;
                p2 = p2->next;
            }


        }
        if(p1 != NULL || p2!= NULL)
        {
            p3->next = (poly *)malloc(sizeof(poly));
            p3 = p3->next;
            p3->next = NULL;
        }
    }
    printf("\n差:\n");
    poly_sort(head_3);
    poly_printf(head_3);
}
void    poly_mult(poly *head_1,poly *head_2,poly *head_3)
{
    poly *p1 = head_1,*p2 = head_2,*p3 = head_3;
    for(; p1 != NULL; p1 = p1->next)
        for(p2 = head_2; p2 != NULL; p2 = p2->next)
        {
            p3->coef = p1->coef * p2->coef;
            p3->exp = p1->exp + p2->exp;
            if(p1->next != NULL || p2->next != NULL)
            {
                p3->next= (poly *)malloc(sizeof(poly));
                p3 = p3->next;
                p3->next =NULL;
            }

        }

    poly_sort(head_3);
    printf("\n积 :\n");
    poly_printf(head_3);
}
void    poly_div(poly *head_1,poly *head_2,poly *head_3)
{
    poly   *p1 = head_1,*p2 = head_2,*pq = head_3;
    if(p1->exp < p2->exp )
    {
        printf("canot div");
        return 0;
    }

    float q =1,n = p1->exp - p2->exp +1;
    while(n> 0 && q != 0)
    {
        p1 = head_1;
        p2 = head_2;
        while(p1->coef * p1->coef <= 0.0001 && p1->next !=NULL)
        {
            p1 = p1->next;
        }
        if(p1->exp < p2->exp)
            break;
        pq->coef = p1->coef / p2->coef;
        pq->exp = p1->exp - p2->exp;

        for(q =0; p1 != NULL && p2 != NULL; p1 = p1->next,p2 = p2->next)
        {
            p1->coef -= p2->coef * pq->coef;
            q +=p1->coef;
        }
        n -- ;
        if(q != 0 && n > 0)
        {
            pq->next = (poly *)malloc(sizeof(poly));
            pq = pq->next;
            pq->next = NULL;
        }

    }
    printf("商:\n");
    poly_sort(head_3);
    poly_printf(head_3);
    printf("余数:\n");
    poly_sort(head_1);
    poly_printf(head_1);

}

int main()
{
    poly head_1,head_2,head_3;
    head_1.coef = 0;
    head_2.coef = 0;
    head_3.coef = 0;
    poly_creat(&head_1);
    //poly_comp(&head_1);
    poly_creat(&head_2);
    //poly_comp(&head_2);


    poly_add(&head_1,&head_2,&head_3);
    poly_sub(&head_1,&head_2,&head_3);
    poly_mult(&head_1,&head_2,&head_3);
    poly_div(&head_1,&head_2,&head_3);


//    file_read(&head_1);
//    file_print(&head_1);

    //poly_comp(&head_1);
    free(&head_1);
    free(&head_2);
    free(&head_3);
    return 0;
}
/*
1 1 4 5 6 3 7 9
5 2 3 1 3 2 6 3
1 3 -3 2 -1 1 -1 0
3 2 -2 1 1 0
*/

