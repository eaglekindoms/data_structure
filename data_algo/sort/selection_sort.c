//
// Created by eagle on 2021/6/28.
// 选择排序
//

#include "sort.h"
#include "utils.h"

void sort(int arr[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        int min = i;// 记录最小值的索引,默认为0
        // 每轮后最小值在数组第一位，所以每轮查找从i+1开始
        for (int j = i + 1; j < len; ++j) {
            // 获取最小值索引
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&arr[i], &arr[min]);
        }
    }
}