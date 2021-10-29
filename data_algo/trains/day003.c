//
// Created by eagle on 2021/10/27.
// 文件树
//
#include "stdio.h"
#include "io.h"

int main() {

    struct _finddata_t fileDir;

    char *dir = "../..";
    long lfDir;

    if ((lfDir = _findfirst(dir, &fileDir)) == -1l)
        printf("No file is found\n");
    else {
        printf("file list:\n");
        do {
            printf("%s\n", fileDir.name);
        } while (_findnext(lfDir, &fileDir) == 0);
    }
    _findclose(lfDir);
}