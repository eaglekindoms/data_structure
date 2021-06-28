//
// Created by eagle on 2021/6/28.
//

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "sort.h"

// 生成随机数组
void rand_arr(int arr[], int len);

int main() {
    int len = 111;
    int arr[len];
    rand_arr(arr, len);
    sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}

void rand_arr(int arr[], int len) {
    // 设置种子
    srand((unsigned) time(NULL));
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % 1000;
    }
}