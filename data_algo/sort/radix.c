#include "utils.h"

/*
 * 基数排序
 * 算法思路：将整数按位数切割成不同的数字，然后按每个位数分别比较。
 * 实现思路：
 *    1.记录数组元素最高位数n
 *    2.准备10个桶, 和一个记录每个桶元素数量的数组
 *    3.对数组元素按i*10取余
 *      (余数范围为0-9，若考虑负数情况，则可对余数加10，0-9即可表示负数)，
 *      根据余数值存到对应下标的桶中
 * 时间复杂度：O(n*k)
 */
// 基数
int largest(int a[], int n) {
    int large = a[0], i;
    for (i = 1; i < n; i++) {
        if (large < a[i])
            large = a[i];
    }
    return large;
}

// 桶个数
#define bucket_num 20
//桶容量
#define bucket_max_capacity 10

void radix_sort(int *arr, int len) {
    // 为二维数组，0-9对应负数，10-19对应正数
    int bucket[bucket_num][bucket_max_capacity];
    // 记录每个桶存放元素个数
    int bucket_count[bucket_num];
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
        for (i = 0; i < bucket_num; i++) {
            bucket_count[i] = 0;
        }
        // 依次对数组元素降位取余（正是这步决定了这是一个稳定算法）
        for (i = 0; i < len; i++) {
            // 余数大小决定存在哪个桶
            // "bucket_count"记录每个桶存放元素个数,个数不应超过桶最大容量
            remainder = (arr[i] / divisor) % 10 + 10;
            bucket[remainder][bucket_count[remainder]] = arr[i];
            bucket_count[remainder] += 1;
        }
        i = 0;
        // 取出桶内元素，替换原数组元素
        for (k = 0; k < bucket_num; k++) {
            for (j = 0; j < bucket_count[k]; j++) {
                arr[i] = bucket[k][j];
                i++;
            }
        }
        // 除数以10倍增
        divisor *= 10;
    }
    print_arr(arr, len, "radix sort");
}

// 一维桶实现基数排序
void radix_sort2(int *arr, int len) {
    // 为一维数组，0-9对应负数，10-19对应正数
    int bucket[bucket_num];
    int remainder, NOP = 0, divisor = 1, large, pass;
    large = largest(arr, len);
    while (large > 0) {
        // 记录最大值的位数
        NOP++;
        large /= 10;
    }
    // NOP记录最大值位数，决定需要几次桶排序
    for (pass = 0; pass < NOP; pass++) {
        // 记录本身及之前桶元素总数：用于取值时的偏移量
        int bucket_offset[bucket_num] = {0};
        // 依次对数组元素降位取余（正是这步决定了这是一个稳定算法）
        for (int i = 0; i < len; ++i) {
            remainder = (arr[i] / divisor) % 10 + 10;
            bucket_offset[remainder]++;
        }
        // 更新每位计数器为：偏移量+元素数
        for (int i = 1; i < bucket_num; ++i) {
            bucket_offset[i] += bucket_offset[i - 1];
        }
        // 元素进桶
        for (int i = 0; i < len; i++) {
            remainder = (arr[i] / divisor) % 10 + 10;
            bucket[--bucket_offset[remainder]] = arr[i];
        }
        // 取出桶内元素，替换原数组元素
        for (int i = 0; i < len; i++) {
            arr[i] = bucket[i];
        }
        // 除数以10倍增
        divisor *= 10;
    }
    print_arr(arr, len, "radix2 sort");
}