#include <stdio.h>
#include <stdlib.h>

int go_ok(int fwsv)
{
    return (fwsv - 0x0111)*(fwsv - 0x0110)*(fwsv - 0x0011)*(fwsv - 0x1000)*(fwsv - 0x1001)*(fwsv - 0x1100);
}

void find_a_way(int fwsv)
{

    int stack[1000] ,top =-1,before_go =-1,after_go = -2;
    int f,w ,s ,v,f_w,f_s,f_v,f_f;
    stack[++top] = 0000;
    printf("start!-->\t");
    while(top != -1)
    {
        while(fwsv!=0x1111 && (before_go != after_go ))
        {
            before_go = stack[top];
            f = fwsv >>3*sizeof(int);
            w = fwsv %(16*16*16) >>2*sizeof(int);
            s = fwsv %(16*16)>>1*sizeof(int);
            v = fwsv % 2;
            f_w = fwsv ^0x1100;
            f_s = fwsv ^0x1010;
            f_v = fwsv ^0x1001;
            f_f = fwsv ^0x1000;

            if((f == w)&&(before_go != 0x1100)&&go_ok(f_w))stack[++top] = 0x1100;
            if((f == s)&&(before_go != 0x1010)&&go_ok(f_s))stack[++top] = 0x1010;
            if((f == v)&&(before_go != 0x1001)&&go_ok(f_v))stack[++top] = 0x1001;
            if((before_go != 0x1000)&&go_ok(f_f))stack[++top] = 0x1000;

            after_go = stack[top];
            fwsv ^= stack[top];
            printf("\t%d %d %d %d \n",f,w,s,v);
                switch(stack[top])
            {
                case 0x1000:printf("famer go alone-->");break;
                case 0x1100:printf("famer and wolf-->");break;
                case 0x1010:printf("famer and sheep-->");break;
                case 0x1001:printf("famer and vegetable-->");break;
            }
        }

        if(fwsv==0x1111){
                 printf("\t1 1 1 1 \n--> end!");return;}
        top--;
    }
    printf("no way!");
}

int main()
{
    find_a_way(0x0000);
    return 0;
}
