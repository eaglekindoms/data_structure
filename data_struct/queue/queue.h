//
// Created by eagle on 2021/6/1.
//

#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#include "stdio.h"
#include "stdlib.h"
#include "error_code.h"

typedef int T;

typedef struct Queue_T *Queue;

// 初始化指定大小的队列
Queue initQueueWithSize(int size);

// 初始化队列
Queue initQueue();

// 队尾插入元素
void enQueue(Queue queue, T data);

// 队头移除元素
T deQueue(Queue queue);

//获取队头元素
T peekFont(Queue queue);

// 清空队列
void clearQueue(Queue queue);

//队列判空
int isEmpty(Queue queue);

//获取队列长度
int getLength(Queue queue);

// 遍历打印队列
void printQueue(Queue queue);

#endif //DATA_STRUCTURE_QUEUE_H
