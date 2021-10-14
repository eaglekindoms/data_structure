//
// Created by eagle on 2021/10/11.
// 复习排序算法
//
#include "stdio.h"
#include "stdlib.h"
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

int main() {
    int arr[] = {2, 3, 8, 5, 6, 1, 0, 1, -12, -9, 5};
    int len = sizeof(arr) / sizeof(int);
    int *arr1, *arr2, *arr3, *arr4, *arr5;
    copy_arr(arr, &arr1, len);
    copy_arr(arr, &arr2, len);
    copy_arr(arr, &arr3, len);
    copy_arr(arr, &arr4, len);
    copy_arr(arr, &arr5, len);
    // 六种排序算法
    bubble_sort(arr, len);
    selection_sort(arr1, len);
    insertion_sort(arr2, len);
    shell_sort(arr3, len);
    merge_sort(arr4, len);
    quick_sort(arr5, len);
}

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
    printf("\n bubble sort \n");
    for (int i = 0; i < len; ++i) {
        printf(" %d", arr[i]);
    }
}

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
    printf("\n selection sort \n");
    for (int i = 0; i < len; ++i) {
        printf(" %d", arr[i]);
    }
}

/*
 * 插入排序
 * 算法思路：通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入
 * 实现思路：
 *     1.从数组的第二个数据开始往前比较，即一开始用第二个数和他前面的一个比较，
 *      如果符合条件（比前面的大或者小，自定义），则让他们交换位置。
 *     2.然后再用第三个数和第二个比较，符合则交换(否则结束此轮遍历)。然后索引减一，重复此步骤
 *       此处是继续往前比较，
 *      比如有 5个数8，15，20，45, 17,17比45小，需要交换，但是17也比20小，也要交换，
 *      当不需 要和15交换以后，说明也不需要和15前面的数据比较了，肯定不需要交换，因为前 面的数据都是有序的。
 * 时间复杂度：n^2
 */
void insertion_sort(int *arr, int len) {
    for (int i = 1; i < len; ++i) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(&arr[j - 1], &arr[j]);
            j--;
        }
    }
    printf("\n insertion sort \n");
    for (int i = 0; i < len; ++i) {
        printf(" %d", arr[i]);
    }
}

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
    printf("\n shell sort \n");
    for (int i = 0; i < len; ++i) {
        printf(" %d", arr[i]);
    }
}

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
    printf("\n merge sort \n");
    for (int i = 0; i < len; ++i) {
        printf(" %d", arr[i]);
    }
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

// 对数组分组，并返回基准值索引位
int partition(int *arr, int left, int right);

void quick_sort(int *arr, int len) {
    quick_sort_recursive(arr, 0, len - 1);
    printf("\n quick sort \n");
    for (int i = 0; i < len; ++i) {
        printf(" %d", arr[i]);
    }
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