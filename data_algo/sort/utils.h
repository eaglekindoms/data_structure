//
// Created by eagle on 2021/6/28.
// 排序公共方法头文件
//

#ifndef DATA_STRUCTURE_UTILS_H
#define DATA_STRUCTURE_UTILS_H

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int min(int x, int y) {
    return x < y ? x : y;
}

#endif //DATA_STRUCTURE_UTILS_H
