#include "utils.h"
/*
 * 选择排序(头插法)
 * 算法思路：首先在未排序序列中找到最小、元素，存放到排序序列的起始位置，
 *        然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
 * 实现思路：遍历n轮，每轮遍历n-i个元素，记录最小元素索引min，交换i与min的值
 * 时间复杂度：n^2
 */
void selection_sort(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (i != min) {
            swap(&arr[i], &arr[min]);
        }
    }
    print_arr(arr, len, "selection sort");
}