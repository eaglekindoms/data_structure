//
// Created by eagle on 2021/6/21.
//

#include "../tree/binary_heap.c"

int main() {
    Heap heap = initHeap();
    int arr[] = {1, 2, 3, 4, 5, 7, 9, 12, 13, 22};
    for (int i = 0; i < 10; ++i) {
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