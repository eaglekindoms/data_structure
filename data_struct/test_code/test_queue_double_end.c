//
// Created by eagle on 2021/6/16.
//

#include "../queue/double_end_queue.c"

int main() {
    Queue queue = initQueue();
    printf("\n --- EN QUEUE --- \n");
    enQueueR(queue, 2);
    enQueueR(queue, 4);
    enQueueL(queue, 6);
    enQueueL(queue, 7);
    enQueueL(queue, 8);
    enQueueR(queue, 120);
    enQueueL(queue, 71);
    enQueueL(queue, 82);
    enQueueR(queue, 110);
    printQueue(queue);
    printf("\n --- PEEK QUEUE FONT --- \n");
    printf("the font element of queue: %d\n", peekFontL(queue));
    printf("\n --- DE QUEUE --- \n");
    deQueueL(queue);
    deQueueL(queue);
    deQueueR(queue);
    printQueue(queue);
    printf("\n --- PEEK QUEUE FONT --- \n");
    printf("the font element of queue: %d\n", peekFontR(queue));
    printf("\n --- QUEUE SIZE --- \n");
    printf("the size of queue: %d\n", getLength(queue));
    printf("\n --- CLEAR QUEUE --- \n");
    clearQueue(queue);
    printQueue(queue);
    printf("\n --- EN QUEUE --- \n");
    enQueueL(queue, 101);
    printQueue(queue);
    return 0;
}