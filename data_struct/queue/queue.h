//
// Created by eagle on 2021/6/1.
//

#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#include "error_code.h"

typedef int T;

typedef struct Queue_T *Queue;

// 初始化队列
Queue initQueue();

// 队尾插入元素
void insert(Queue s, T data);

// 队头移除元素
T remove(Queue s);

//获取队头元素
T peekFont(Queue s);

// 清空队列
void clearQueue(Queue s);

//队列判空
int isEmpty(Queue s);

//获取队列长度
int getLength(Queue s);

// 遍历打印队列
void printQueue(Queue s);

#endif //DATA_STRUCTURE_QUEUE_H
