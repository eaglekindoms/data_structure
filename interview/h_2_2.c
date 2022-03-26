//
// Created by eagle on 2022/3/26.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// 学生结构体，记录学生名和姓名重复次数
typedef struct {
    char name[20];
    int num;
} Student;

// 搜索表，如果姓名重复则计数器加一，不重复则新加入
void checkList(Student *list, char name[], int *len);

int main() {
    int n;
    scanf("%d", &n);
    while (n != 0) {
        Student *list = (Student *) malloc(n * sizeof(Student));
        int i, len = 0;
        for (i = 0; i < 2 * n - 1; ++i) {
            char name[20];
            scanf("%s", name);
            checkList(list, name, &len);
        }
        for (i = 0; i < len; i++) {
            if (list[i].num % 2 == 1) {
                printf("%s\n", list[i].name);
            }
        }
        free(list);
        scanf("%d", &n);
    }
    return 0;
}

void checkList(Student *list, char name[], int *len) {
    int i;
    for (i = 0; i < *len; i++) {
        if (strcmp(list[i].name, name) == 0) {
            list[i].num++;
            return;
        }
    }
    strcpy(list[*len].name, name);
    list[*len].num = 1;
    *len = *len + 1;
}