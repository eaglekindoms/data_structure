//
// Created by eagle on 2021/6/21.
//

#include "../tree/binary_heap.c"

int main() {
    Heap heap = initHeap();
    int arr[] = {20, 9, 27, 2, 12, 22, 38, 1, 4, 0, 13, 00, 30, 0, 0, 0, 3, 5, 0, 0, 0, 0, 29, 31, 0, 0};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        insert(heap, arr[i]);
    }
    printHeap(heap);
    Heap heap1 = initHeap();
    int a[] = {22, 13, 7, 9, 12, 2, 5, 1, 4};
    buildHeap(heap1, a, sizeof(a) / sizeof(a[0]));
    printf("\narr length: %d\n", sizeof(a) / sizeof(a[0]));
    printHeap(heap1);
    return 0;
}