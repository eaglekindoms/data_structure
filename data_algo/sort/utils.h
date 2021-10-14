//
// Created by eagle on 2021/6/28.
// 排序公共方法头文件
//

#ifndef DATA_STRUCTURE_UTILS_H
#define DATA_STRUCTURE_UTILS_H

#include "stdlib.h"

/*
 * 交换变量值(必须使用变量的指针才能改变其内容)
 */
void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

/*
 * 拷贝数组内容
 */
void copy_arr(const int *a, int **b, int len) {
    *b = (int *) malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i) {
        *(*b + i) = *(a + i);
    }
}

#endif //DATA_STRUCTURE_UTILS_H
