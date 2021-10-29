#include "utils.h"
/*
 * 归并排序
 * 算法思路：
 *     利用归并的思想实现的排序方法，该算法
 *     采用经典的分治（divide-and-conquer）策略
 *     （分治法将问题分(divide)成一些小的问题然后递归求解，
 *     而治(conquer)的阶段则将分的阶段得到的各答案"修补"在一起，即分而治之)。
 * 实现思路：递归方法，先分后合
 * 时间复杂度：nlog2n
 */
// 合并
void merge(int *arr, int left, int mid, int right, int *temp);

// 递归
void merge_sort_recursive(int *arr, int left, int right, int *temp);

// 排序(初始化临时数组)
void merge_sort(int *arr, int len) {
    int *temp = (int *) malloc(len * sizeof(int));
    merge_sort_recursive(arr, 0, len - 1, temp);
    free(temp);
    print_arr(arr, len, "merge sort");
}

void merge_sort_recursive(int *arr, int left, int right, int *temp) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort_recursive(arr, left, mid, temp);
        merge_sort_recursive(arr, mid + 1, right, temp);
        merge(arr, left, mid, right, temp);
    }
}

// https://www.cnblogs.com/chengxiao/p/6194356.html
void merge(int *arr, int left, int mid, int right, int *temp) {
    int i = left;//左序列指针
    int j = mid + 1;//右序列指针
    int t = 0;//临时数组指针
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[t++] = arr[i++];
        } else {
            temp[t++] = arr[j++];
        }
    }
    while (i <= mid) {//将左边剩余元素填充进temp中
        temp[t++] = arr[i++];
    }
    while (j <= right) {//将右序列剩余元素填充进temp中
        temp[t++] = arr[j++];
    }
    t = 0;
    //将temp中的元素全部拷贝到原数组中
    while (left <= right) {
        arr[left++] = temp[t++];
    }
}