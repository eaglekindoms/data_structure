#include "utils.h"
/*
 * 快速排序(原地排序)
 * 算法思路：
 *     通过一趟排序将要排序的数据分割成独立的两部分，
 *     其中一部分的所有数据都比另外一部分的所有数据都要小，
 *     然后再按此方法对这两部分数据分别进行快速排序，
 *     整个排序过程可以递归进行，以此达到整个数据变成有序序列
 * 实现思路：分治法，递归实现
 * 时间复杂度：nlog2n
 */
// 递归排序
void quick_sort_recursive(int *arr, int left, int right);
void quickSort(int arr[], int left, int right);
// 对数组分组，并返回基准值索引位
int partition(int *arr, int left, int right);

void quick_sort(int *arr, int len) {
    quick_sort_recursive(arr, 0, len - 1);
    print_arr(arr, len, "quick sort");
}

void quick_sort_recursive(int *arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quick_sort_recursive(arr, left, pivot - 1);
        quick_sort_recursive(arr, pivot + 1, right);
    }
}

int partition(int *arr, int left, int right) {
    // 取左端元素为基准
    int pivot = arr[left];
    // 基于基准和左右边界分组，分组后基准值比左端元素都大
    // (然后再递归对其左，右端分组)
    while (left < right) {
        //找到小于基准值的右端元素索引
        while (left < right && arr[right] >= pivot) {
            right--;
        }
        // 替换基准值所在位置的值为找到的小右端元素
        if (left < right) arr[left] = arr[right];
        // 找到大于基准值的左端元素索引
        while (left < right && arr[left] <= pivot) {
            left++;
        }
        // 替换小右端元素索引的值为找到的左端元素值
        if (left < right) arr[right] = arr[left];
    }
    // 将left指向位置替为基准值，返回基准值索引
    arr[left] = pivot;
    return left;
}

void quickSort(int nums[], int left, int right) {
    if (left >= right) {
        return;
    }
    int i = left - 1, j = right + 1;
    int x = nums[left];
    while (i < j) {
        while (nums[++i] < x);
        while (nums[--j] > x);
        if (i < j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
    quickSort(nums, left, j);
    quickSort(nums, j + 1, right);
}