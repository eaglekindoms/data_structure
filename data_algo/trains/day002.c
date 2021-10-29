//
// Created by eagle on 2021/10/25.
//
#include "stdio.h"

char *create_phone_number(char phnum[16], const unsigned char nums[10])
{
    for (int i=0, j=0; i<14; i++) {
        switch (i) {
            case 0: phnum[i] = '('; break;
            case 4: phnum[i] = ')'; break;
            case 5: phnum[i] = ' '; break;
            case 9: phnum[i] = '-'; break;
            default: phnum[i] = nums[j++]+'0';
        }
    }
    phnum[15]='\0';
    return phnum;
}
size_t countBits(unsigned value)
{
    size_t count = 0;
    for (; value; value >>= 1) if ( value & 1 ) count++;
    return count;
}
int main(){
    char p[16];
    char n[10]={1,2,3,4,5,6,7,8,9,0};
    char *s=create_phone_number(p,n);
    printf("|%s|",s);
    printf("\n|%zu|", countBits(678));
};