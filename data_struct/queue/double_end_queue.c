//
// Created by eagle on 2021/6/6.
//

#include "stdio.h"
#include "stdlib.h"
#include "error_code.h"
#include <memory.h>

#define QUEUE_INIT_SIZE 100

typedef int T;
typedef struct Queue_T *Queue;

struct Queue_T {
    int font;
    int tail;
    T *rawData;
    int length;
};

// 初始化队列
Queue initQueue() {
    Queue queue = (Queue) malloc(sizeof(Queue));
    queue->rawData = (T *) malloc(QUEUE_INIT_SIZE * sizeof(T));
    memset(queue->rawData, (int) NULL, QUEUE_INIT_SIZE * sizeof(T));
    if (!queue->rawData)
        exit(ERROR_MALLOC_FAILED);
    queue->tail = queue->font = 0;
    queue->length = 0;
    return queue;
}

// 判断队列是否满了
void isFull(Queue queue) {
    if ((queue->tail + 1) % QUEUE_INIT_SIZE == queue->font) {
        printf("\n---- 队列已满 ---\n");
        exit(ERROR_FULL_SPACE);
    }
}

//队列判空
int isEmpty(Queue queue) {
    return queue->length == 0;
}

// 右端插入元素
void enQueueR(Queue queue, T data) {
    isFull(queue);
    queue->rawData[queue->tail] = data;
    // 顺时针旋转
    queue->tail = (queue->tail + 1) % QUEUE_INIT_SIZE;
    queue->length++;
}

// 左端插入元素
void enQueueL(Queue queue, T data) {
    isFull(queue);
    // 逆时针旋转
    queue->font = (--queue->font + QUEUE_INIT_SIZE) % QUEUE_INIT_SIZE;
    queue->rawData[queue->font] = data;
    queue->length++;
}

// 右端移除元素
T deQueueR(Queue queue) {
    if (isEmpty(queue))
        exit(ERROR_NULL_PTR);
    // 逆时针旋转
    queue->tail = (--queue->tail + QUEUE_INIT_SIZE) % QUEUE_INIT_SIZE;
    T data = queue->rawData[queue->tail];
    queue->rawData[queue->tail] = NULL;
    queue->length--;
    printf("DeQueue data: %d \n", data);
    return data;
}

// 左端移除元素
T deQueueL(Queue queue) {
    T data = queue->rawData[queue->font];
    queue->rawData[queue->font] = NULL;
    // 顺时针旋转
    queue->font = (queue->font + 1) % QUEUE_INIT_SIZE;
    queue->length--;
    printf("DeQueue data: %d \n", data);
    return data;
}

//获取右端头元素
T peekFontR(Queue queue) {
    if (queue->tail % QUEUE_INIT_SIZE == queue->font)
        exit(ERROR_NULL_PTR);
    return queue->rawData[queue->tail];
}

//获取左端头元素
T peekFontL(Queue queue) {
    if (queue->tail % QUEUE_INIT_SIZE == queue->font)
        exit(ERROR_NULL_PTR);
    return queue->rawData[queue->font];
}

// 清空队列
void clearQueue(Queue queue) {
    queue->length = 0;
    queue->tail = queue->font;
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
    printf("\n--- Print SQ Queue ---\n");
    for (int i = 0; i < QUEUE_INIT_SIZE; ++i) {
        if (queue->rawData[i] != NULL) {
            printf(" %d", queue->rawData[i]);
        }
    }
    printf("\n--- Print Done ---\n");
}