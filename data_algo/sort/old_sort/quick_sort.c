//
// Created by eagle on 2021/6/28.
// 快速排序
//
#include "sort.h"
#include "../utils.h"

void quickSort(int arr[], int low, int high);

int partition(int arr[], int low, int high);

void sort(int arr[], int len) {
    quickSort(arr, 0, len - 1);
}

void quickSort(int arr[], int low, int high) {

    if (low < high) {
        int index = partition(arr, low, high);
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }

}

int partition(int arr[], int low, int high) {

    int pivot = arr[low];
    while (low < high) {
        //移动hight指针
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        //填坑
        if (low < high) arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) {
            low++;
        }
        //填坑
        if (low < high) arr[high] = arr[low];
    }
    //基准数放到合适的位置
    arr[low] = pivot;
    return low;
}