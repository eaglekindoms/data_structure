#include "utils.h"
/*
 * 希尔排序 (非稳定，插入排序的改进版本)
 * 算法思路：
 *     先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，
 *     待整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序
 *     即因为插入排序每次只能将数据移动一位，所以自定义增量
 * 实现思路：
 *     1.设置增量gap，并逐步缩小增量
 *     2.从第gap个元素，逐个对其所在组进行直接插入排序操作
 * 时间复杂度：nlog2n
 */
void shell_sort(int *arr, int len) {
    // 设定gap分量，并递减
    for (int gap = len / 2; gap > 0; gap = gap / 2) {
        // 从第gap元素遍历数组，进行插入排序，排序比较间隔为gap
        for (int i = gap; i < len; ++i) {
            int j = i;
            while (j - gap >= 0 && arr[j] < arr[j - gap]) {
                swap(&arr[j], &arr[j - gap]);
                j -= gap;
            }
        }
    }
    print_arr(arr, len, "shell sort");
}