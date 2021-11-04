//
// Created by eagle on 2021/10/11.
// 10/11-10/17
// 复习排序算法
//
#include "../sort/utils.h"

// 冒泡排序
void bubble_sort(int *arr, int len);

// 选择排序
void selection_sort(int *arr, int len);

// 插入排序
void insertion_sort(int *arr, int len);

// 希尔排序
void shell_sort(int *arr, int len);

// 归并排序
void merge_sort(int *arr, int len);

// 快速排序
void quick_sort(int *arr, int len);

// 堆排序
void heap_sort(int *arr, int len);

// 桶排序
void bucket_sort(int *arr, int len);

// 基数排序
void radix_sort(int *arr, int len);

typedef void (*sort)(int *, int);

int main() {
    int arr[] = {2, 3, 8, 5, 6, 1, 0, 1, 12, 9, 5};
    int len = sizeof(arr) / sizeof(int);
    int *array[10];
    sort func[] = {bubble_sort, selection_sort, insertion_sort,
                   shell_sort, merge_sort, quick_sort,
                   heap_sort, bucket_sort, radix_sort};
    int func_num = sizeof(func) / sizeof(func[0]);
    for (int i = 0; i < func_num; ++i) {
        copy_arr(arr, &array[i], len);
        func[i](array[i], len);
    }
}