//
// Created by eagle on 2021/6/25.
//
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include <sys/time.h>

// 构建next数组
int next[100] = {0};

void build_next(char *pattern);

// 匹配子串
void kmp(char *str, char *pattern);

int mate(char *B, char *A);

int main() {
    FILE *fp = NULL;
    char str[65500];

    char *path = "D:\\code\\study_c_algo\\data_structure\\data_algo\\test_files\\test_string.txt";
    fp = fopen(path, "r");
    if (!fp) exit(-101);
    fgets(str, 65500, (FILE *) fp);
    char *pattern = "Ricans were ";
    struct timeval t1;
    gettimeofday(&t1, NULL);
    printf("\ns1:%ld,%ld\n", t1.tv_sec, t1.tv_usec);
    kmp(str, pattern);
    gettimeofday(&t1, NULL);
    printf("\ns2:%ld,%ld\n", t1.tv_sec, t1.tv_usec);
    mate(str, pattern);
    gettimeofday(&t1, NULL);
    printf("\ns3:%ld,%ld\n", t1.tv_sec, t1.tv_usec);
    return 0;
}

void build_next(char *pattern) {
    int now = 0;
    int i = 1;
    int len = strlen(pattern);
    while (i < len) {
        if (pattern[i] == pattern[now]) {
            now++;
            next[i] = now;
            i++;
        } else if (now != 0) {
            now = next[now - 1];
        } else {
            i++;
            next[i] = now;
        }
    }
}

void kmp(char *str, char *pattern) {
    int tar = 0;
    int pos = 0;
    build_next(pattern);
    while (tar < strlen(str)) {
        if (str[tar] == pattern[pos]) {
            tar++;
            pos++;
        } else if (pos != 0) {
            pos = next[pos - 1];
        } else {
            tar++;
        }
        if (pos == strlen(pattern)) {
            printf("kmp: %d ", tar - pos + 1);
            pos = next[pos - 1];
        }
    }
}

//串普通模式匹配算法的实现函数，其中 str是伪主串，pattern是伪子串
int mate(char *str, char *pattern) {
    int i = 0, j = 0;
    while (i < strlen(str)) {
        if (str[i] == pattern[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
        if (j == strlen(pattern)) {
            printf("bf: %d ", i - j + 1);
            j = 0;
        }
    }
    return 0;
}