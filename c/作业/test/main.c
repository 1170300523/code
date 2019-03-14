#include <stdio.h>
#include <stdlib.h>

int main()
{
 char rbx[6] = {'q','w','e','r','t','y'};
 char rsp[6];
 int rax = 0;
do {
                    *(int8_t *)(rsp + rax ) = *(int8_t *)( 0x555555556790+ (*(int8_t *)(rbx + rax) & 0xff & 0xf)) & 0xff;
                    rax = rax + 0x1;
            } while (rax != 0x6);
    printf("%c",rsp[0]);
    return 0;
}
