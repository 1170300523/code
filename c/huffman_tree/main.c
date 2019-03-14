#include <stdio.h>

#include <string.h>

#define CHAR_NUM  92

#define MAX_TEXT 10000





typedef  struct h_tree_node

{

    double  weight;//Ȩֵ

    int     parent;//���ڵ���

    int     left_son;//������,Ϊ�����±�

    int     right_son;//������

} htree;



typedef struct tx

{

    char c;

    float p;

    char code[51];

} tx;

//�ҵ���С���������,�ҹ��ľ��Թ�

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





//������������,����һ���ṹ������

void creat_htree(htree a[],tx b[],int n )

{

    int j=0,k = 1,i ;//iΪѭ����������,j,kΪȨֵ��С���������±�

    for( i= 0; i < 2*n -1; i++ ) //��ʼ��

    {

        a[i].parent = -1;

        a[i].left_son = -1;

        a[i].right_son = -1;

    }



    for(i = 0; i<n; i++) //����Ȩֵ

    {

        a[i].weight =  b[i].p;

    }



    for(i = n; i<2*n -1; i++) //�ϳ�huffman��

    {

        find_min_2(a,i,&j,&k);

        a[j].parent = i;

        a[k].parent = i;

        a[i].left_son = j;

        a[i].right_son =k;

        a[i].weight = a[j].weight + a[k].weight;

    }



    printf("\n\t\t�Ƿ��ӡÿ���ַ����ָ���?(1/0):\n\t\t");

    scanf("%d",&j);

    if(j)

        for(i = 0; i< n; i+=2)

            printf("%c: %.4f\t%c: %.4f\n",b[i].c,a[i].weight,b[i+1].c,a[i+1].weight );

}

//���ļ�ͳ�Ƹ����ַ����ִ���

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

    //������ת��Ϊ����

    for(i = 0; i<CHAR_NUM; i++)

        text_num +=b[i].p;

    for(i = 0; i<CHAR_NUM; i++)

        b[i].p /= text_num;

}



//����������

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

    //��ӡ��ÿ���ַ���Ӧ����

    printf("\n\t\t�Ƿ��ӡÿ���ַ���Ӧ����?(1/0):\n\t\t");

    scanf("%d",&j);

    if(j)

        for(i = 0; i<CHAR_NUM; i+=2)

            printf("%c : %-30s \t%c : %s\n",b[i].c,b[i].code,b[i+1].c,b[i+1].code);

}



//��ӡ����,��δѹ��

void print_code(char text[],tx b[])

{

    int i,j;

    FILE *fp = fopen("test.txt","r");

    //����huffman_code�ĵ�

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



//ѹ��huffman����

void compress_huffcode()

{

    int i,ch =0,t =5;

    char c1[8];

    FILE *fp_huff = fopen("huff_code.txt","r");

    FILE *fp_compress = fopen("compressed.txt","w");

    fclose(fp_compress);

    fp_compress = fopen("compressed.txt","a");

    printf("\n\n������ѹ��������:\n\n:");

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

    FILE *fp_huff = fopen("huff_code.txt","r");

    FILE *fp_decpr = fopen("decompressed.txt","w");
    fclose(fp_decpr);

    fp_decpr = fopen("decompressed.txt","a");

    char str[100000];

    fgets(str,100000,fp_huff);

    int start = 0,end,tail,i=0,j;

    while(str[i++]);

    tail =i;


    printf("\n\n�����ǽ�������:\n\n:");

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






int main()

{

    char text[MAX_TEXT];//�ı�

    tx b[CHAR_NUM];//�ַ�,�ṹ��,��������,���ָ���,����������

    //int text_num = 0;

    htree a[CHAR_NUM*2 -1];//�������������,����ǰ����������ڱ���

//    ����huffman��

//

//    ����huffman����

    read_file(text,b);

    creat_htree(a,b,CHAR_NUM);

    huffman_encoding(a,b);

    //��ӡ��huffman�����ļ�,��δѹ��

    print_code(a,b);

    //��huffman�����ļ�����ѹ��

    compress_huffcode();

    decompress(b);//����

    return 0;

}
