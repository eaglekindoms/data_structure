#include "queue.h"
#include <string.h>

#define QUEUE_INIT_SIZE 100
#define QUEUE_INCREMET 10

struct Queue_T
{
    T *font;
    T *tail;
    int capacity;
    int length;
};

// 初始化队列
Queue initQueue()
{
    Queue queue = (Queue)malloc(sizeof(Queue));
    queue->font = (T *)malloc(QUEUE_INIT_SIZE * sizeof(T));
    memset(queue->font, NULL, QUEUE_INIT_SIZE * sizeof(T));
    if (!queue->font)
        exit(ERROR_MALLOC_FAILED);
    queue->tail = queue->font;
    queue->capacity = QUEUE_INIT_SIZE;
    queue->length = 0;
    return queue;
}

// 队尾插入元素
void enQueue(Queue queue, T data)
{
    if (queue->tail - queue->font >= queue->capacity)
    {
        queue->font = (T *)realloc(queue->font, (queue->capacity + QUEUE_INCREMET) * sizeof(T));
        if (!queue->font)
            exit(ERROR_MALLOC_FAILED);
        queue->tail = queue->font + queue->capacity;
        queue->capacity += QUEUE_INCREMET;
    }
    *(queue->tail) = data;
    queue->tail++;
    queue->length++;
}

// 队头移除元素
T deQueue(Queue queue)
{
    if (queue->tail == queue->font)
        exit(ERROR_NULL_PTR);
    T data = *(queue->font++);
    queue->length--;
    printf("DeQueue data: %d \n", data);
    return data;
}

//获取队头元素
T peekFont(Queue queue)
{
    if (queue->tail == queue->font)
        exit(ERROR_NULL_PTR);
    return *(queue->font);
}

// 清空队列
void clearQueue(Queue queue)
{
    queue->length = 0;
    queue->tail = queue->font;
}

//队列判空
int isEmpty(Queue queue)
{
    return queue->length == 0;
}

//获取队列长度
int getLength(Queue queue)
{
    return queue->length;
}

// 遍历打印队列
void printQueue(Queue queue)
{
    if (isEmpty(queue))
    {
        printf("\n--- Empty Queue ---\n");
        return;
    }
    printf("\n--- Print SQ Queue ---\n");
    T *ptr = queue->font;
    while (ptr < queue->tail)
    {
        printf("%d ", *(ptr));
        ptr++;
    }
    printf("\n--- Print Done ---\n");
}