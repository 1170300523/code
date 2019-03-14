#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  strnode
{
	char  str[4];
	struct strnode *next;
}strnode;

//函数,输入串,并以链表形式储存
void str_input(strnode *head)
{
	int i = 0,j,len;
	char c[20],*str_in = c;
	strnode *p = head;
	scanf("%s",str_in);
	len = strlen(str_in);
	for(i=0;i<(len+3)/4;i++)
	{
		p->next = (strnode *)malloc(sizeof(strnode));
		p = p->next;
		p->next = NULL;
		//printf("%d,%d,%d\n",len,i,(len+3)/4 );
	}
	for(i = 0,p = head;c[i];i++)
	{	j = i%4;
		if(j || !i)
			p->str[j] = c[i];
		else if(p->next)
		{

			p = p->next;
			p->str[j] = c[i];

		}
	}

	for(p = head ;p;p = p->next)
		printf("%s\n",p->str );
	printf("input the mom_str:\n");
	printf("input the son_str:\n");

}


void my_kmp(strnode *head1,strnode *head2)
{

}

int main( )
{   strnode str1,str2;
	str_input(&str1);
	return 0;
}


