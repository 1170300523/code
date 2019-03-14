#include <stdio.h>
#include <string.h>
#define CHAR_NUM  92
#define MAX_TEXT 10000


typedef  struct h_tree_node
{
    double  weight;//权值
    int     parent;//父节点结点
    int     left_son;//左子树,为数组下标
    int     right_son;//右子树
} htree;

typedef struct tx
{
    char c;
    float p;
    char code[51];
} tx;
//找到最小的两个结点,找过的就略过
void find_min_2(htree a[],int n,int *j,int *k)
{
    int i;
    for(i = 0; i<n; i++)
        if(a[i].parent == -1)
            *j = i;
    for(i = 0; i<n; i++)
        if(a[i].parent == -1 && i != *j)
            *k = i;
    for( i =0; i <n; i++)
        if(a[i].parent ==-1 &&  a[i].weight<a[*j].weight && i != *k )
            *j = i;
    for(i=0; i<n; i++)
        if(a[i].parent ==-1  && i != *j && a[i].weight<a[*k].weight)
            *k = i;
}


//创建哈夫曼树,输入一个结构体数组
void creat_htree(htree a[],tx b[],int n )
{
    int j=0,k = 1,i ;//i为循环计数变量,j,k为权值最小两个结点的下标
    for( i= 0; i < 2*n -1; i++ ) //初始化
    {
        a[i].parent = -1;
        a[i].left_son = -1;
        a[i].right_son = -1;
    }

    for(i = 0; i<n; i++) //输入权值
    {
        a[i].weight =  b[i].p;
    }

    for(i = n; i<2*n -1; i++) //合成huffman树
    {
        find_min_2(a,i,&j,&k);
        a[j].parent = i;
        a[k].parent = i;
        a[i].left_son = j;
        a[i].right_son =k;
        a[i].weight = a[j].weight + a[k].weight;
    }

    printf("\n\t\t是否打印每个字符出现概率?(1/0):\n\t\t");
    scanf("%d",&j);
    if(j)
    for(i = 0; i< n; i+=2)
        printf("%c: %.4f\t%c: %.4f\n",b[i].c,a[i].weight,b[i+1].c,a[i+1].weight );
}
//读文件统计各个字符出现次数
void read_file(char text[],tx b[])
{
    int line =0,i,j,text_num =0;
    b[CHAR_NUM -1].c = '\n';
    for(i = 0; i<CHAR_NUM-1; i++)
    {
        b[i].c = ' '+i;
        b[i].p = 0;
    }
    FILE *fp = fopen("test.txt","r");
    while(fgets(text,100,fp))
    {
        for(i = 0; i<200; i++)
            for(j = 0; j<CHAR_NUM; j++)
                if(text[i] == b[j].c)
                {
                    b[j].p ++;
                }

    }
    fclose(fp);
    //将次数转化为概率
    for(i = 0; i<CHAR_NUM; i++)
        text_num +=b[i].p;
    for(i = 0; i<CHAR_NUM; i++)
        b[i].p /= text_num;
}

//哈夫曼编码
void huffman_encoding(htree a[],tx b[])
{
    int parent,child,i,start,j,k;
    char c[51];
    for(i=0; i<CHAR_NUM; i++)
    {
        start =50 ;
        c[start] = '\0';
        child = i;
        while(a[child].parent >= 0 )
        {
            parent = a[child].parent;
            c[--start] = (a[parent].left_son == child )?'0':'1';
            child = parent;
        }
        for(j = 0; j<start; j++)
            c[j] = ' ';
        for(j=0; c[j]==' '; j++);
        for(k =0; j<51; k++,j++)
            c[k] =c[j];
        strcpy(b[i].code,c);
    }
    //打印出每个字符对应编码
    printf("\n\t\t是否打印每个字符对应编码?(1/0):\n\t\t");
    scanf("%d",&j);
    if(j)
    for(i = 0; i<CHAR_NUM; i+=2)
        printf("%c : %-30s \t%c : %s\n",b[i].c,b[i].code,b[i+1].c,b[i+1].code);
}

//打印编码,还未压缩
void print_code(char text[],tx b[])
{
    int i,j;
    FILE *fp = fopen("test.txt","r");
    //清理huffman_code文档
    FILE *fp_remove = fopen("huff_code.txt","w");
    fclose(fp_remove);
    FILE *fp_huff = fopen("huff_code.txt","a");

    while(fgets(text,80,fp))
    {
        for(j=0; text[j]; j++)
            for(i =0; i<CHAR_NUM; i++)
                if(text[j]==b[i].c)
                    fprintf(fp_huff,"%s",b[i].code);
    }
    fclose(fp);
    fclose(fp_huff);
}

//压缩huffman编码
void compress_huffcode()
{
    int i,ch =0,t =5;
    char c1[8];
    FILE *fp_huff = fopen("huff_code.txt","r");
    FILE *fp_compress = fopen("compressed.txt","w");
    fclose(fp_compress);
    fp_compress = fopen("compressed.txt","a");
printf("\n\n以下是压缩过内容:\n\n:");
    while(fgets(c1,8,fp_huff))
    {
        for(i = 0,ch =0; i<7; i++)
            ch += (c1[i] - 48)<<(6-i);
        printf("%c ",ch);
        fprintf(fp_compress,"%c",ch);
    }
    fclose(fp_huff);
    fclose(fp_compress);
}

void decompress(tx b[])
{
    //FILE *fp_compress = fopen("compressed.txt","r");
    FILE *fp_huff = fopen("huff_code.txt","r");
    FILE *fp_decpr = fopen("decompressed.txt","w");fclose(fp_decpr);
    fp_decpr = fopen("decompressed.txt","a");
    char str[100000];
    fgets(str,100000,fp_huff);
    int start = 0,end,tail,i=0,j;
    while(str[i++]);
    tail =i;
   //printf("%d\n",tail);
    //printf("%s",str);
    printf("\n\n以下是解码内容:\n\n:");
    while(end < tail)
    {
        //printf("%d\n",end);
        char match[20] = " ";
        for(i=start,j=0; i<end; i++,j++)
            match[j] = str[i];


        for(i = 0; i<CHAR_NUM; i++)
        {
            //strlen(b[i].code) == strlen(match) &&
            if( strcmp(match,b[i].code)==0)
            {
                printf("%c",b[i].c);
                fprintf(fp_decpr,"%c",b[i].c);
                start += strlen(b[i].code) ;
                end =start;
                break;
            }
        }
        end ++;
    }

    fclose(fp_huff);
    fclose(fp_decpr);


}
void mune()
{
    char text[MAX_TEXT];//文本
    tx b[CHAR_NUM];//字符,结构体,包括名称,出现概率,哈夫曼编码
    //int text_num = 0;
    htree a[CHAR_NUM*2 -1];//哈夫曼结点数组,用于前期排序和中期编码


    //建立huffman树

    //进行huffman编码

    printf("\t\t1.读文件,统计各个字出现概率\n\t\t2.显示哈夫曼压缩编码\n\t\t3.压缩\n\t\t4.解压\n\t\t按q退出\n\t\t:");

    int ch;
    scanf("%d",&ch);
    while(ch != 0)
    {
        getchar();
    printf("\t\t1.读文件,统计各个字出现概率\n\t\t2.显示哈夫曼压缩编码\n\t\t3.压缩\n\t\t4.解压\n\t\t按q退出\n\t\t:");
         printf("\n%d\n",ch);
        switch(ch)
        {
      //getchar();
        case 1://读文件,统计各个字出现概率
            read_file(text,b);
            creat_htree(a,b,CHAR_NUM);
            break;
        case 2:
            huffman_encoding(a,b);
            //打印出huffman编码文件,还未压缩
            print_code(a,b);
            //将huffman编码文件进行压缩

            break;
        case 3:
            compress_huffcode();
            break;
        case 4:
            printf("ghjkhjk\n\n");
             decompress(b);//解码
            break;
        default:
            printf("input wrong");
            break;
        }
        getchar();
         printf("\t\t1.读文件,统计各个字出现概率\n\t\t2.显示哈夫曼压缩编码\n\t\t3.压缩\n\t\t4.解压\n\t\t按q退出\n\t\t:");
        scanf("%d",&ch);
    }

}
int main()
{


    char text[MAX_TEXT];//文本
    tx b[CHAR_NUM];//字符,结构体,包括名称,出现概率,哈夫曼编码
    //int text_num = 0;
    htree a[CHAR_NUM*2 -1];//哈夫曼结点数组,用于前期排序和中期编码


//    建立huffman树
//
//    进行huffman编码


            read_file(text,b);
            creat_htree(a,b,CHAR_NUM);
            huffman_encoding(a,b);
            //打印出huffman编码文件,还未压缩
            print_code(a,b);
            //将huffman编码文件进行压缩
            compress_huffcode();
             decompress(b);//解码



    return 0;
}
