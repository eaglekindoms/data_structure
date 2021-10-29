//
// Created by eagle on 2021/6/28.
// 插入排序
//

#include "sort.h"

void sort(int arr[], int len) {
    int j, temp;
    for (int i = 1; i < len; i++) {
        temp = arr[i];
        //从后往前排序，当arr[i]小于前一个元素时，子排序数组元素后移，
        // 直到大于它为止，此时，arr[j]=arr[j+1],所以令arr[j]=temp(arr[i]的值已被置换);
        for (j = i; j > 0 && arr[j - 1] > temp; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}