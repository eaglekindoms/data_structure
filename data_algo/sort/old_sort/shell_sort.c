//
// Created by eagle on 2021/6/28.
// 希尔排序
//

#include "sort.h"

void sort(int arr[], int len) {
    int gap, i, j;
    int temp;
    // >> 右移 相当于 /2   例：10110 >> 1 = 1011  22/2 = 11
    for (gap = len >> 1; gap > 0; gap = gap >> 1)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
}