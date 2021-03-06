//
// Created by eagle on 2021/5/28.
//
#include "stdio.h"
#include "../stack/stack.h"

int main() {
    Stack stack = initStack();
    pushStack(stack, 1);
    pushStack(stack, 2);
    pushStack(stack, 3);
    printf("stack's getTop: %d\n", getTop(stack));
    pushStack(stack, 4);
    pushStack(stack, 5);
    printStack(stack);
    popStack(stack);
    popStack(stack);
    printf("stack's length: %d\n", getLength(stack));
    popStack(stack);
    printStack(stack);
    printf("stack's length: %d\n", getLength(stack));
    clearStack(stack);
    pushStack(stack, 115);
    printStack(stack);
    destroy(stack);
}