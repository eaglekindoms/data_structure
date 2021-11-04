#include "utils.h"

/*
 * 基数排序
 * 算法思路：
 * 实现思路：
 * 时间复杂度：O(n*k)
 */
// 基数
#define BASE 10

int largest(int a[], int n) {
    int large = a[0], i;
    for (i = 1; i < n; i++) {
        if (large < a[i])
            large = a[i];
    }
    return large;
}

#define bucket_max_capacity 10

void radix_sort(int *arr, int len) {
    // bucket为二维数组即十个桶数组，桶容量为bucket_max_capacity
    int bucket[10][bucket_max_capacity];
    // bucket_count记录每个桶存放元素个数, 总共十个桶
    int bucket_count[10];
    int i, j, k, remainder, NOP = 0, divisor = 1, large, pass;

    large = largest(arr, len);
    while (large > 0) {
        // 记录最大值的位数
        NOP++;
        large /= 10;
    }
    // NOP记录最大值位数，决定需要几次桶排序
    for (pass = 0; pass < NOP; pass++) {
        // 重置桶计数器
        for (i = 0; i < 10; i++) {
            bucket_count[i] = 0;
        }
        // 依次对数组元素降位取余（正是这步决定了这是一个稳定算法）
        for (i = 0; i < len; i++) {
            // 余数大小决定存在哪个桶
            // "bucket_count"记录每个桶存放元素个数,个数不应超过桶最大容量
            remainder = (arr[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = arr[i];
            bucket_count[remainder] += 1;
        }
        i = 0;
        // 取出桶内元素，替换原数组元素
        for (k = 0; k < 10; k++) {
            for (j = 0; j < bucket_count[k]; j++) {
                arr[i] = bucket[k][j];
                i++;
            }
        }
        // 除数以10倍增
        divisor *= 10;
//        printf("\n bucket: \n");
//        for (i = 0; i < len; i++) printf("%d ", arr[i]);
    }
    print_arr(arr, len, "radix sort");
}