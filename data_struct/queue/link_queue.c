#include "queue.h"

typedef struct QNode
{
    T data;
    struct QNode *next;
} Node;

struct Queue_T
{
    Node *head;
    Node *tail;
    int length;
};

// 初始化队列
Queue initQueue()
{
    Queue queue = (Queue)malloc(sizeof(Queue));
    queue->head = (Node *)malloc(sizeof(Node));
    queue->tail = queue->head;
    queue->head->next = NULL;
    queue->length = 0;
    return queue;
}

// 队尾插入元素
void enQueue(Queue queue, T data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    queue->tail->next = node;
    queue->tail = node;
    // q->tail相当于temp值
    // 第一次后每个tail都等于上一个的node，然后这一步会给上一个node的next指针赋地址值。
    /* 即要满足的条件：
       head = '1', tail = 'n', tail.next  = 'n+1'(当n+1不存在时=null)
       注意！！！要先给tail.next赋值后再更新tail不然tail.next会始终为null
       当n=1时head和tail重合所以不需要给head.next赋值
    */
    queue->length++;
}

// 队头移除元素
T deQueue(Queue queue)
{
    if (queue->head == queue->tail)
        exit(ERROR_NULL_PTR);
    Node *node = queue->head->next;
    T data = node->data;
    queue->head->next = node->next;
    queue->length--;
    if (queue->tail == node)
        queue->tail = queue->head; //delete over
    free(node);
    return data;
}

//获取队头元素
T peekFont(Queue queue)
{
    if (queue->head == queue->tail)
        exit(ERROR_NULL_PTR);
    T data = queue->head->next->data;
    return data;
}

// 清空队列
void clearQueue(Queue queue)
{
    Node *node = queue->head->next;
    while (node != NULL)
    {
        queue->head->next = node->next;
        free(node);
        node = queue->head->next;
    }
    queue->length = 0;
    queue->tail = queue->head;
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
    printf("\n--- Print LINK Queue ---\n");
    Node *curr = queue->head->next;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n--- Print Done ---\n");
}

// API
struct __QUEUE_API__ MyQueue = {
    .init = initQueue,
    .insert = enQueue,
    .remove = deQueue,
    .front = peekFont,
    .clear = clearQueue,
    .isEmpty = isEmpty,
    .getLength = getLength,
    .print = printQueue,
};