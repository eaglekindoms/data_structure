//
// Created by eagle on 2021/6/21.
//

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "memory.h"
#include "error_code.h"
#include "boolean.h"

#define DEFAULT_HEAP_SIZE 50

typedef int T;

// 堆结构体定义
typedef struct {
    T *arr;  // 数据储存数组
    int length; // 数据个数
    int capacity; // 数组容量
} *Heap;

// 堆初始化
Heap initHeap() {
    Heap heap = (Heap) malloc(sizeof(Heap));
    heap->arr = (T *) malloc(DEFAULT_HEAP_SIZE * sizeof(T));
    if (!heap->arr)
        exit(ERROR_MALLOC_FAILED);
    memset(heap->arr, 0, DEFAULT_HEAP_SIZE * sizeof(T));
    heap->length = 0;
    heap->capacity = DEFAULT_HEAP_SIZE;
    return heap;
}

// 交换数组两个元素
void swap(T *arr, int a, int b) {
    T temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// 插入数据
void insert(Heap heap, T data) {
    if (heap->length >= heap->capacity) {
        heap->arr = (T *) realloc(heap->arr, (heap->capacity + DEFAULT_HEAP_SIZE) * sizeof(T));
        if (!heap->arr)
            exit(ERROR_MALLOC_FAILED);
        heap->capacity += DEFAULT_HEAP_SIZE;
    }
    heap->length++;
    heap->arr[heap->length] = data;
    int i = heap->length;
    while (i / 2 > 0 &&
           heap->arr[i] > heap->arr[i / 2]) {
        // 自下往上堆化
        swap(heap->arr, i, i / 2); // swap()函数作用：交换下标为i和i/2的两个元素
        i = i / 2;
    }
}

// 堆化
void heapify(T *a, int n, int i) {
    // 自上往下堆化
    while (TRUE) {
        int maxPos = i;
        if (i * 2 <= n && a[i] < a[i * 2])
            maxPos = i * 2;
        if (i * 2 + 1 <= n && a[maxPos] < a[i * 2 + 1])
            maxPos = i * 2 + 1;
        if (maxPos == i)
            break;
        swap(a, i, maxPos);
        i = maxPos;
    }
}

// 建堆
void buildHeap(Heap heap, T a[], int size) {
    heap->arr = a;
    heap->length = size;
    for (int i = heap->length / 2; i >= 1; --i) {
        heapify(heap->arr, heap->length, i);
    }
}

char *space(int len) {
    char *new_space = (char *) malloc(4 * len * sizeof(char));
    memset(new_space, ' ', 4 * len * sizeof(char));
    return new_space;
}

int mod_(int i) {
    if (i % 2 >= 2) return mod_(i % 2);
    return i % 2;
}

//打印堆
void printHeap(Heap heap) {
//    int height = (int) log2(heap->length);
    for (int i = 0; i < heap->length; ++i) {
//        char *spac = space(height-(int) log2(i+1));
//        if (mod_(i+1)>0)printf(" \n");
        printf("%d ", heap->arr[i]);
    }
}
// 20,9,27,2,12,22,38,1,4,0,13,00,30,0,0,0,3,5,0,0,0,0,29,31,0,0