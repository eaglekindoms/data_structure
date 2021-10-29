//
// Created by eagle on 2021/6/28.
// 排序公共方法头文件
//


#include "stdlib.h"
#include "stdio.h"

#ifndef DATA_STRUCTURE_UTILS_H
#define DATA_STRUCTURE_UTILS_H

/*
 * 交换变量值(必须使用变量的指针才能改变其内容)
 */
inline
void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

/*
 * 拷贝数组内容
 */
inline
void copy_arr(const int *src, int **dst, int len) {
    *dst = (int *) malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i) {
        *(*dst + i) = *(src + i);
    }
}

/*
 * 打印数组
 */
inline
void print_arr(int *arr, int len, char *func_name) {
    printf("\n %s \n", func_name);
    for (int i = 0; i < len; ++i) {
        printf(" %d", arr[i]);
    }
}

#endif //DATA_STRUCTURE_UTILS_H
