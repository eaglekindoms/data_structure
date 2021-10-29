#include "utils.h"

/*
 * 冒泡排序(尾插法)
 * 思路：遍历n轮，每轮遍历n-i个元素，每次将最大/最小元素排到数组最后面
 * 时间复杂度：n^2
 */
void bubble_sort(int *arr, int len) {
//    遍历数组
    for (int i = len - 1; i > 0; --i) {
//        将前n-i个元素中最大元素排到数组末尾
        for (int j = 0; j < i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    print_arr(arr, len, "bubble sort");
}