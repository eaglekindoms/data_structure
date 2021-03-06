//
// Created by eagle on 2021/5/28.
//
#include "stack.h"
#include <memory.h>

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 10

struct Stack_T {
    T *top;
    T *base;
    int capacity;
    int length;
};

Stack initStack() {
    Stack stack = (Stack) malloc(sizeof(Stack));
    stack->base = (T *) malloc(STACK_INIT_SIZE * sizeof(T));
    memset(stack->base, 0, STACK_INIT_SIZE * sizeof(T));
    if (!stack->base) exit(ERROR_MALLOC_FAILED);
    stack->top = stack->base;
    stack->capacity = STACK_INIT_SIZE;
    stack->length = 0;
    return stack;
}

int getLength(Stack s) {
    return s->length;
}

void pushStack(Stack s, T data) {
    if (s->top - s->base >= s->capacity) {
        s->base = (T *) realloc(s->base, (s->capacity + STACK_INCREMENT) * sizeof(T));
        if (!s->base) exit(ERROR_MALLOC_FAILED);
        s->top = s->base + s->capacity;
        s->capacity += STACK_INCREMENT;
    }
    *(s->top) = data;
    s->top++;
    s->length++;
}

T popStack(Stack s) {
    if (s->top == s->base) exit(ERROR_NULL_PTR);
    s->length--;
    T data = *(--s->top);
    printf("popStack: %d \n", data);
    return data;
}

T getTop(Stack s) {
    if (s->top == s->base) exit(ERROR_NULL_PTR);
    return *(s->top - 1);
}

void clearStack(Stack s) {
    s->length = 0;
    s->top = s->base;
}

void destroy(Stack s) {
    free(s->base);
    s->top = NULL;
    s->base = NULL;
    s->capacity = 0;
    s->length = 0;
    s = NULL;
    printf("the stack is destroyed\n");
}

int isEmpty(Stack s) {
    if (s->length == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void printStack(Stack s) {
    if (isEmpty(s) == TRUE) {
        printf("the sequence stack is empty!\n");
        return;
    }
    printf("\nstack's elements: \n");
    T *p = s->top;
    while (p > s->base) {
        p--;
        printf("%d ", *p);
    }
    printf("\ntraverse done!\n");
}