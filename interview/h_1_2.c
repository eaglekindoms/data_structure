//
// Created by eagle on 2022/3/23.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {
    int w1l[] = {1, 2, 7, 8, 13, 14, 19, 20, 25, 26, 31, 32, 37, 38};
    int w1r[] = {0, 4, 5, 10, 11, 16, 17, 22, 23, 28, 29, 34, 35, 40};

    int w2l[] = {0, 3, 6, 11, 13, 14, 16, 21, 24, 29, 31, 32, 34, 39};
    int w2r[] = {2, 4, 5, 7, 12, 15, 20, 22, 23, 25, 30, 33, 38, 40};


    int w3l[] = {5, 7, 9, 11, 13, 14, 16, 18, 20, 22, 33, 35, 37, 39};
    int w3r[] = {0, 6, 8, 10, 12, 15, 17, 19, 21, 32, 34, 36, 38, 40};

    int w4l[] = {0, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39};
    int w4r[] = {14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40};

    char str[4];
    int verify[8][14] ;
    memset(verify,0,sizeof (verify));
    while (gets(str)) {
        if (str[0] == '\0') break;
//        printf("%s",&str);
    }
}