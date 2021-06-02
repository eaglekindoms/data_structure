#include "queue.h"

int test_queue()
{
    Queue queue = initQueue();
    printf("\n --- EN QUEUE --- \n");
    enQueue(queue, 2);
    enQueue(queue, 4);
    enQueue(queue, 6);
    enQueue(queue, 7);
    enQueue(queue, 8);
    enQueue(queue, 10);
    printQueue(queue);
    printf("\n --- PEEK QUEUE FONT --- \n");
    printf("the font element of queue: %d\n", peekFont(queue));
    printf("\n --- DE QUEUE --- \n");
    deQueue(queue);
    printQueue(queue);
    printf("\n --- PEEK QUEUE FONT --- \n");
    printf("the font element of queue: %d\n", peekFont(queue));
    printf("\n --- QUEUE SIZE --- \n");
    printf("the size of queue: %d\n", getLength(queue));
    printf("\n --- CLEAR QUEUE --- \n");
    clearQueue(queue);
    printQueue(queue);
    printf("\n --- EN QUEUE --- \n");
    enQueue(queue, 101);
    printQueue(queue);
    return 0;
}