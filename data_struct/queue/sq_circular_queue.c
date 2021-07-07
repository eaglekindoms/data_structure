//
// Created by eagle on 2021/6/16.
// 顺序队列循环数组实现
//

#include "queue.h"
#include <memory.h>

#define QUEUE_INIT_SIZE 100

struct Queue_T {
    int font;
    int tail;
    T *rawData;
    int length;
    int capacity;
};

// 初始化指定大小的队列
Queue initQueueWithSize(int size) {
    Queue queue = (Queue) malloc(sizeof(Queue));
    queue->rawData = (T *) malloc(size * sizeof(T));
    memset(queue->rawData, 0, size * sizeof(T));
    if (!queue->rawData)
        exit(ERROR_MALLOC_FAILED);
    queue->tail = queue->font = 0;
    queue->length = 0;
    queue->capacity = size;
    return queue;
}

// 初始化队列
Queue initQueue() {
    return initQueueWithSize(QUEUE_INIT_SIZE);
}

// 队尾插入元素
void enQueue(Queue queue, T data) {
    if ((queue->tail + 1) % queue->capacity == queue->font) {
        printf("\n---- full queue ---\n");
        exit(ERROR_FULL_SPACE);
    }
    queue->rawData[queue->tail % queue->capacity] = data;
    queue->tail++;
    queue->length++;
}

// 队头移除元素
T deQueue(Queue queue) {
    if (queue->tail % queue->capacity == queue->font)
        exit(ERROR_NULL_PTR);
    T data = queue->rawData[queue->font];
    queue->font = (queue->font + 1) % queue->capacity;
    queue->length--;
//    printf("DeQueue data: %d \n", data);
    return data;
}

//获取队头元素
T peekFont(Queue queue) {
    if (queue->tail % queue->capacity == queue->font)
        exit(ERROR_NULL_PTR);
    return queue->rawData[queue->font];
}

// 清空队列
void clearQueue(Queue queue) {
    queue->length = 0;
    queue->tail = queue->font;
}

//队列判空
int isEmpty(Queue queue) {
    return queue->length == 0;
}

//获取队列长度
int getLength(Queue queue) {
    return queue->length;
}

// 遍历打印队列
void printQueue(Queue queue) {
    if (isEmpty(queue)) {
        printf("\n--- Empty Queue ---\n");
        return;
    }
    printf("\n--- Print SQ Circular Queue ---\n");
    for (int i = 0; i < queue->length; ++i) {
        printf(" %d", queue->rawData[queue->font + i]);
    }
    printf("\n--- Print Done ---\n");
}

// API
struct __QUEUE_API__ MyQueue = {
        .initWithSize=initQueueWithSize,
        .init = initQueue,
        .insert = enQueue,
        .remove = deQueue,
        .front = peekFont,
        .clear = clearQueue,
        .isEmpty = isEmpty,
        .getLength = getLength,
        .print = printQueue,
};