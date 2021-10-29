#include "utils.h"
/*
 * 堆排序
 * 算法思路：
 *     将待排序序列构造成一个大顶堆，
 *     此时，整个序列的最大值就是堆顶的根节点。
 *     将其与末尾元素进行交换，此时末尾就为最大值。
 *     然后将剩余n-1个元素重新构造成一个堆，这样会得到n个元素的次小值。
 *     如此反复执行，便能得到一个有序序列了
 * 实现思路：
 *     a.将无需序列构建成一个堆，根据升序降序需求选择大顶堆或小顶堆;
 *     b.将堆顶元素与末尾元素交换，将最大元素"沉"到数组末端;
 *     c.重新调整结构，使其满足堆定义，然后继续交换堆顶元素与当前末尾元素，
 *      反复执行调整+交换步骤，直到整个序列有序。
 * 时间复杂度：nlog2n
 */
// 建立大根堆
void build_max_heap(int *arr, int len);

// 调整大根堆
void adjust_heap(int *arr, int i, int len);

// 堆排序
void heap_sort(int *arr, int len) {
    //1.构建大顶堆
    build_max_heap(arr, len);
    //2.调整堆结构+交换堆顶元素与末尾元素
    for (int j = len - 1; j > 0; j--) {
        swap(&arr[0], &arr[j]);//将堆顶元素与末尾元素进行交换
        adjust_heap(arr, 0, j);//重新对堆进行调整
    }
    print_arr(arr, len, "heap sort");
}

void build_max_heap(int *arr, int len) {
    for (int i = len / 2 - 1; i >= 0; i--) {
        //从第一个非叶子结点从下至上，从右至左调整结构
        adjust_heap(arr, i, len);
    }
}

void adjust_heap(int *arr, int i, int len) {
    int temp = arr[i];//先取出当前元素i
    for (int k = i * 2 + 1; k < len; k = k * 2 + 1) {//从i结点的左子结点开始，也就是2i+1处开始
        if (k + 1 < len && arr[k] < arr[k + 1]) {//如果左子结点小于右子结点，k指向右子结点
            k++;
        }
        if (arr[k] > temp) {//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
            arr[i] = arr[k];
            i = k;
        } else {
            break;
        }
    }
    arr[i] = temp;//将temp值放到最终的位置
}