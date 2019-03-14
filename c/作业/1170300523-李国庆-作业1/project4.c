//此项目中有10个学院,5个男子项目,5个女子项目,男子项目取前5,女子项目取前3;
/*
测试用例:
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
    printf("\n请先输入10个学校的名称\t:");
    for(i = 0; i<10; i++)
    {

        scanf("%s",&a[i].sch_name);
        a[i].flag = i;
    }
    printf("\n请先输入10个项目的名称\t");
    for(i = 0; i<10; i++)
    {

        scanf("%s",&b[i].pro_name);
    }
    for(i = 0; i<5; i++)
    {
        printf("\n请先输入第%d个项目的10个班的积分,此为男子项目前五名为7,5,3,2,1\t",i+1);
        for(j = 0; j<10; j++)
        {

            scanf("%d",&b[i].pschool[j]);
            if(b[i].pschool[j]<0||b[i].pschool[j]>7)
            {
                printf("\n输入不符合数据范围!!!请重新输入!!\n");
                j--;
            }
        }
    }
    for(i = 5; i<10; i++)
    {
        printf("\n请先输入第%d个项目的10个班的积分, 此为女子项目,前三名为5,3,2\t",i+1);
        for(j = 0; j<10; j++)
        {
            scanf("%d",&b[i].pschool[j]);
            if(b[i].pschool<0||b[i].pschool[j]>3)
            {
                printf("\n输入不符合数据范围!!!请重新输入!!\n");
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
    printf("\n\n\n-----------------各学院总分如下--------------\n\n\n");
    printf("学院\t");
    for(i =0; i<10; i++)
        printf("学院%s\t",a[i].sch_name);
    printf("\n男子:\t");

    for(i =0; i<10; i++)
        printf("%d\t",a[i].score[0]);
    printf("\n女子:\t");
    for(i =0; i<10; i++)
        printf("%d\t",a[i].score[1]);
    printf("\n总分:\t");
    for(i =0; i<10; i++)
        printf("%d\t",a[i].score[0]+a[i].score[1]);

}

void school_sort(struct school a[],struct project b[])
{
    printf("\n\n男子项目:\n");
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
        printf("%s学院,编号为%d,男子总分数为%d,排名为%d\n",a[i].sch_name,i+1,a[i].score[0],a[i].flag+1);
    printf("\n\n女子项目:\n");
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
        printf("%s学院,编号为%d,女子总分数为%d,排名为%d\n",a[i].sch_name,i+1,a[i].score[1],a[i].flag+1);
    printf("\n\n总分排名:\n");
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
        printf("%s学院,编号为%d,总分为%d,排名为%d\n",a[i].sch_name,i+1,a[i].score[0]+a[i].score[1],a[i].flag+1);
}
void my_search(struct school a[],struct project b[])
{
    printf("\n\n\t1.查询学院\n\t2.查询项目\n");
    scanf("%d",&i);
    if(i==1)
    {
        printf("\n\t请输入学院编号:\t");
        scanf("%d",&j);
        printf("第%d学院10个项目的成绩如下:\n",j);
        for(i =0; i<10; i++)
            printf("%d\t",b[i].pschool[j]);
    }
    else
    {
        printf("\n\t请输入项目编号:\t");
        scanf("%d",&j);
        printf("第%d项目10个学院的成绩如下:\n",j);
        for(i =0; i<10; i++)
            printf("%d\t",b[j].pschool[i]);
    }

}

void file_op(struct school a[],struct project b[])
{

    FILE *fp;

    if(!(fp = fopen("school.txt","w")))

    {

        printf("创建失败");

        exit(0);

    }


    printf("操作成功!\n");

    fprintf(fp,"\t各学院及其各项目成绩\t\n");
    fprintf(fp,"\n项目详细情况,成绩\n");

    for(i=0; i<10; i++)

    {
        fprintf(fp,"第%d个项目:\t",i);
        for(j=0; j<10; j++)
            fprintf(fp,"%d\t",b[i].pschool[j]);
        fprintf(fp,"\n");

    }

    fprintf(fp,"男子:\t");
    for(i =0; i<10; i++)
        fprintf(fp,"%d\t",a[i].score[0]);
    fprintf(fp,"\n女子:\t");
    for(i =0; i<10; i++)
        fprintf(fp,"%d\t",a[i].score[1]);
    fprintf(fp,"\n总分:\t");
    for(i =0; i<10; i++)
        fprintf(fp,"%d\t",a[i].score[0]+a[i].score[1]);
    fclose(fp);


}
void menu(struct school a[],struct project b[])
{
    int ch = 1;
    while(ch)
    {
        printf("继续请输入1,退出请输入0");
        printf("\n\t\t\t\t\t\t--体育成绩管理系统--\n\n\n");
        printf("\t1.输入信息\n");
        printf("\t2.统计总分\n");
        printf("\t3.成绩排序排序\n");
        printf("\t4.搜索\n");
        printf("\t5.写到文件(请先用1,2功能再使用该功能)\n");
        printf("\t6.退出\n");
        printf("\t----->输入编号执行操作:\t");
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
            printf("输入错误!");
            break;
        }
        printf("\n继续请输入1,退出请输入0:\t\n");
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

