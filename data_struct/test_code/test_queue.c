#include "../queue/queue.h"

int main() {
    Queue queue = MyQueue.init();
    printf("\n --- EN QUEUE --- \n");
    MyQueue.insert(queue, 2);
    MyQueue.insert(queue, 4);
    MyQueue.insert(queue, 6);
    MyQueue.insert(queue, 7);
    MyQueue.insert(queue, 8);
    MyQueue.insert(queue, 10);
    MyQueue.print(queue);
    printf("\n --- PEEK QUEUE FONT --- \n");
    printf("the font element of queue: %d\n", MyQueue.front(queue));
    printf("\n --- DE QUEUE --- \n");
    MyQueue.remove(queue);
    MyQueue.print(queue);
    printf("\n --- PEEK QUEUE FONT --- \n");
    printf("the font element of queue: %d\n", MyQueue.front(queue));
    printf("\n --- QUEUE SIZE --- \n");
    printf("the size of queue: %d\n", MyQueue.getLength(queue));
    printf("\n --- CLEAR QUEUE --- \n");
    MyQueue.clear(queue);
    MyQueue.print(queue);
    printf("\n --- EN QUEUE --- \n");
    MyQueue.insert(queue, 101);
    MyQueue.print(queue);
    return 0;
}