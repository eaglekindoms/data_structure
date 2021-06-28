//
// Created by eagle on 2021/6/28.
// 冒泡排序
//

#include "sort.h"
#include "utils.h"

void sort(int arr[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        // 每轮排序将最大元素转移到数组最后面
        for (int j = 0; j < len - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}