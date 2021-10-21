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

extern struct __QUEUE_API__ {
    // 初始化指定大小的队列
    Queue (*initWithSize)(int size);

    // 初始化队列
    Queue (*init)();

    // 队尾插入元素
    void (*insert)(Queue queue, T data);

    // 队头移除元素
    T (*remove)(Queue queue);

    //获取队头元素
    T (*front)(Queue queue);

    // 清空队列
    void (*clear)(Queue queue);

    //队列判空
    int (*isEmpty)(Queue queue);

    //获取队列长度
    int (*getLength)(Queue queue);

    // 遍历打印队列
    void (*print)(Queue queue);
} MyQueue;

#endif //DATA_STRUCTURE_QUEUE_H
