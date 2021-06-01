//
// Created by eagle on 2021/5/28.
//
#include "stdio.h"
#include "stack.h"

int testStack() {
    Stack stack = init();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("stack's top: %d\n", top(stack));
    push(stack, 4);
    push(stack, 5);
    printStack(stack);
    pop(stack);
    pop(stack);
    printf("stack's length: %d\n", size(stack));
    pop(stack);
    printStack(stack);
    printf("stack's length: %d\n", size(stack));
    clear(stack);
    printStack(stack);
    destroy(stack);
}