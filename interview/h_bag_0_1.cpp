//
// Created by eagle on 2022/3/23.
//

#include "stdlib.h"
#include "stdio.h"

typedef struct {
    int id;
    char name[30];
    char major[30];
} info;

int main()
{
    FILE *fp = NULL;

    fp = fopen("./test.txt", "w+");
//    fprintf(fp, "This is testing for fprintf...\n");
    info info1[100];
    for (int i = 0; i < 100; ++i) {
        info1[i].id=i;
        info1[i].name[0]='p';
        info1[i].major[0]='p';
    }
    fwrite(info1,sizeof (info),100,fp);
//    fputs("This is testing for fputs...\n", fp);
    fclose(fp);
}