/*
*作者:	李国庆 1170300523
*项目:	kmp以链表实现
*时间:	2018-11-13
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  strnode
{
	char  str[4];
	struct strnode *next;
}strnode;

//函数,输入串,并以链表形式储存
int str_input(strnode *head)
{
	int i = 0,j,len;
	char c[50],*str_in = c;
	strnode *p = head;
	scanf("%s",str_in);
	len = strlen(str_in);

	for(i=0;i<(len+3)/4;i++)//申请结点
	{
		p->next = (strnode *)malloc(sizeof(strnode));
		p = p->next;
		p->next = NULL;
	}

	for(i = 0,p = head;c[i];i++)//为结点赋值
	{	j = i%4;
		if(j || !i)
			p->str[j] = c[i];
		else if(p->next !=NULL)
		{
		p = p->next;
		p->str[j] = c[i];
		}
	}


return len;
}

void get_next(strnode *son_str,int next[],int len)
{
    int j = 0,i, k = -1,nj,nk;
    strnode *p = son_str,*q = son_str;
    next[0] = -1;

    while(j < len - 1 )
    {	nj = j%4;
    	nk = k%4;
    	for(i=0,p =son_str;(i< j /4) && p->next;i++,p = p->next);//转到p[i]
    	for(i=0,q = son_str;(i < k /4) && q->next;i++,q = q->next);//转到p[j]
        if(k == -1||p->str[nj] == q->str[nk])
           next[++j] = ++k;
        else
            k = next[k];
    }
}


void my_kmp(strnode *mom_str,strnode *son_str,int next[],int len1,int len2)
{
	int i = 0,j = 0,ni,nj,k;
	strnode *p = mom_str ,*q = son_str;

	while(i < len1 && j < len2)
	{
		ni = i%4;
    	nj = j%4;
		for(k = 0,p = mom_str;k < i/4 ;k++)p = p->next;//转到p[i]
    	for(k = 0,q = son_str;k < j/4 ;k++)q = q->next;//转到q[j]
		if(j == -1 || p->str[ni] == q->str[nj])
			{
				i++;
			    j++;
			}
		else
			j = next[j];

	}

if(j == len2)
    printf("\n\npos is : %d\n", i-j);
else
    printf("\n\nno that str\n");
}


int main( )
{
	strnode mom_str,son_str;
	int mom_str_len,son_str_len;

	printf("input the mom_str:\n");
	mom_str_len =  str_input(&mom_str);
	printf("\ninput the son_str:\n");
	son_str_len = str_input(&son_str);


	int next[son_str_len] = {0};
	get_next(&son_str,next,son_str_len);
	my_kmp(&mom_str,&son_str,next,mom_str_len,son_str_len);
	return 0;
}

