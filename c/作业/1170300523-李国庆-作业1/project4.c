//����Ŀ����10��ѧԺ,5��������Ŀ,5��Ů����Ŀ,������Ŀȡǰ5,Ů����Ŀȡǰ3;
/*
��������:
q w e r t y u i o p
a s d f g h j k l z
0 0 0 0 0 7 3 2 1 5
0 0 0 0 0 7 3 2 1 5
0 0 0 0 0 7 3 2 1 5
7 3 2 1 5 0 0 0 0 0
3 1 2 0 0 0 5 7 0 0
1 2 3 0 0 0 0 0 0 0
1 2 3 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 2 3
0 0 0 0 1 2 3 0 0 0
0 1 0 2 0 3 0 0 0 0
*/
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 5
#define W 5
struct school
{
    char sch_name[20];
    int score[2] ;
    int flag;
};
struct project
{
    char pro_name[20];
    int pschool[10];
};
int i,j,temp_int;
char temp_char[20];



void input_info(struct school a[],struct project b[])
{
    printf("\n��������10��ѧУ������\t:");
    for(i = 0; i<10; i++)
    {

        scanf("%s",&a[i].sch_name);
        a[i].flag = i;
    }
    printf("\n��������10����Ŀ������\t");
    for(i = 0; i<10; i++)
    {

        scanf("%s",&b[i].pro_name);
    }
    for(i = 0; i<5; i++)
    {
        printf("\n���������%d����Ŀ��10����Ļ���,��Ϊ������Ŀǰ����Ϊ7,5,3,2,1\t",i+1);
        for(j = 0; j<10; j++)
        {

            scanf("%d",&b[i].pschool[j]);
            if(b[i].pschool[j]<0||b[i].pschool[j]>7)
            {
                printf("\n���벻�������ݷ�Χ!!!����������!!\n");
                j--;
            }
        }
    }
    for(i = 5; i<10; i++)
    {
        printf("\n���������%d����Ŀ��10����Ļ���, ��ΪŮ����Ŀ,ǰ����Ϊ5,3,2\t",i+1);
        for(j = 0; j<10; j++)
        {
            scanf("%d",&b[i].pschool[j]);
            if(b[i].pschool<0||b[i].pschool[j]>3)
            {
                printf("\n���벻�������ݷ�Χ!!!����������!!\n");
                j--;
            }
        }
    }

}

void sum_school(struct school a[],struct project b[])
{
    for(i =0; i<10; i++)
    {
        a[i].score[0] = 0;
        a[i].score[1] = 0;
        for(j=0; j<5; j++)
        {
            a[i].score[0] += b[j].pschool[i];
        }
        for(j=5; j<10; j++)
        {
            a[i].score[1] += b[j].pschool[i];
        }

    }
}
void print_info(struct school a[],struct project b[])
{
    printf("\n\n\n-----------------��ѧԺ�ܷ�����--------------\n\n\n");
    printf("ѧԺ\t");
    for(i =0; i<10; i++)
        printf("ѧԺ%s\t",a[i].sch_name);
    printf("\n����:\t");

    for(i =0; i<10; i++)
        printf("%d\t",a[i].score[0]);
    printf("\nŮ��:\t");
    for(i =0; i<10; i++)
        printf("%d\t",a[i].score[1]);
    printf("\n�ܷ�:\t");
    for(i =0; i<10; i++)
        printf("%d\t",a[i].score[0]+a[i].score[1]);

}

void school_sort(struct school a[],struct project b[])
{
    printf("\n\n������Ŀ:\n");
    for(i=0; i<9; i++)
        for(j = i+1; j<10; j++)
        {
            if(a[i].score[0]<a[j].score[0])
            {
                temp_int = a[i].flag;
                a[i].flag = a[j].flag;
                a[j].flag = temp_int;
            }
        }
    for(i=0; i<10; i++)
        printf("%sѧԺ,���Ϊ%d,�����ܷ���Ϊ%d,����Ϊ%d\n",a[i].sch_name,i+1,a[i].score[0],a[i].flag+1);
    printf("\n\nŮ����Ŀ:\n");
    for(i=0; i<9; i++)
        for(j = i+1; j<10; j++)
        {
            if(a[i].score[1]<a[j].score[1])
            {
                temp_int = a[i].flag;
                a[i].flag = a[j].flag;
                a[j].flag = temp_int;
            }
        }
    for(i=0; i<10; i++)
        printf("%sѧԺ,���Ϊ%d,Ů���ܷ���Ϊ%d,����Ϊ%d\n",a[i].sch_name,i+1,a[i].score[1],a[i].flag+1);
    printf("\n\n�ܷ�����:\n");
    for(i=0; i<9; i++)
        for(j = i+1; j<10; j++)
        {
            if(a[i].score[0]+a[i].score[1] <a[j].score[0]+a[j].score[1])
            {
                temp_int = a[i].flag;
                a[i].flag = a[j].flag;
                a[j].flag = temp_int;
            }
        }
    for(i=0; i<10; i++)
        printf("%sѧԺ,���Ϊ%d,�ܷ�Ϊ%d,����Ϊ%d\n",a[i].sch_name,i+1,a[i].score[0]+a[i].score[1],a[i].flag+1);
}
void my_search(struct school a[],struct project b[])
{
    printf("\n\n\t1.��ѯѧԺ\n\t2.��ѯ��Ŀ\n");
    scanf("%d",&i);
    if(i==1)
    {
        printf("\n\t������ѧԺ���:\t");
        scanf("%d",&j);
        printf("��%dѧԺ10����Ŀ�ĳɼ�����:\n",j);
        for(i =0; i<10; i++)
            printf("%d\t",b[i].pschool[j]);
    }
    else
    {
        printf("\n\t��������Ŀ���:\t");
        scanf("%d",&j);
        printf("��%d��Ŀ10��ѧԺ�ĳɼ�����:\n",j);
        for(i =0; i<10; i++)
            printf("%d\t",b[j].pschool[i]);
    }

}

void file_op(struct school a[],struct project b[])
{

    FILE *fp;

    if(!(fp = fopen("school.txt","w")))

    {

        printf("����ʧ��");

        exit(0);

    }


    printf("�����ɹ�!\n");

    fprintf(fp,"\t��ѧԺ�������Ŀ�ɼ�\t\n");
    fprintf(fp,"\n��Ŀ��ϸ���,�ɼ�\n");

    for(i=0; i<10; i++)

    {
        fprintf(fp,"��%d����Ŀ:\t",i);
        for(j=0; j<10; j++)
            fprintf(fp,"%d\t",b[i].pschool[j]);
        fprintf(fp,"\n");

    }

    fprintf(fp,"����:\t");
    for(i =0; i<10; i++)
        fprintf(fp,"%d\t",a[i].score[0]);
    fprintf(fp,"\nŮ��:\t");
    for(i =0; i<10; i++)
        fprintf(fp,"%d\t",a[i].score[1]);
    fprintf(fp,"\n�ܷ�:\t");
    for(i =0; i<10; i++)
        fprintf(fp,"%d\t",a[i].score[0]+a[i].score[1]);
    fclose(fp);


}
void menu(struct school a[],struct project b[])
{
    int ch = 1;
    while(ch)
    {
        printf("����������1,�˳�������0");
        printf("\n\t\t\t\t\t\t--�����ɼ�����ϵͳ--\n\n\n");
        printf("\t1.������Ϣ\n");
        printf("\t2.ͳ���ܷ�\n");
        printf("\t3.�ɼ���������\n");
        printf("\t4.����\n");
        printf("\t5.д���ļ�(������1,2������ʹ�øù���)\n");
        printf("\t6.�˳�\n");
        printf("\t----->������ִ�в���:\t");
        scanf("%d",&ch);
        switch(ch)
        {

        case 1:
            input_info(a,b);
            break;
        case 2:
            sum_school(a,b);
            print_info(a,b);
            break;
        case 3:
            school_sort(a,b);
            break;
        case 4:
            my_search(a,b);
            break;
        case 5:
            file_op(a,b);
            break;
        case 6:
            exit(0);
        default:
            printf("�������!");
            break;
        }
        printf("\n����������1,�˳�������0:\t\n");
        scanf("%d",&j);
        if(!j)
            exit(0);

    }

}
int main()
{

    struct school a[10];
    struct  project b[10];
    menu(a,b);
    return 0;
}

