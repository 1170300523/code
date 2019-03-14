#include <stdio.h>
#include <string.h>

void get_next(char *p,int next[])
{
    int len = strlen(p);
    int j = 0, k = -1;
    next[0] = -1;

    while(j < len -1)
        {   //printf("%c--%c\n",p[j], p[k] );
    if(k == -1||p[j] == p[k] )
        next[++j] = ++k;
    else
        k = next[k];
}
}

void my_kmp(char *t , char *p,int next[])
{
    int i = 0,j = 0,len_t = strlen(t),len_p = strlen(p);
    while(i < len_t && j < len_p)
    {  //if(j != -1) printf("%c-->%c\n",t[i] , p[j]  );
      if(j ==-1 || t[i] == p[j])
      {
        i++;
        j++;
      }
    else
        j = next[j];
    //printf("-->%d",j );
}

if(j == len_p)
    printf("pos is : %d\n", i -j); 
else 
    printf("no\n");
}

int main()
{   char a[100],b[100],*t = a,*p = b;
    scanf("%s",t);
    scanf("%s",p);
    int len_p = strlen(p),next[len_p];
    get_next(p,next);
    my_kmp(t,p,next);
    int i =0;
    for(;i<len_p;i++)
        printf("\n%d\t",next[i] );
    return 0;
}

