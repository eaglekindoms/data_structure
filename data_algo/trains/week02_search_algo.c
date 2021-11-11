//
// Created by eagle on 2021/11/10.
// 查找算法
//

#include "stdio.h"

int order_search(int arr[], int len, int val);

int binary_search(int arr[], int len, int val);

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int val = 2;
    int v = order_search(arr, 10, val);
    int v1 = binary_search(arr, 10, val);
    printf("order: %d, binary: %d", v, v1);
}

int order_search(int arr[], int len, int val) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] == val) return i;
    }
    return -1;
}

int binary_rec(int arr[], int l, int r, int val) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == val) return mid;
        if (arr[mid] > val) return binary_rec(arr, l, mid - 1, val);
        return binary_rec(arr, mid + 1, r, val);
    }
    return -1;
}

int binary_search(int arr[], int len, int val) {
    return binary_rec(arr, 0, len - 1, val);
}