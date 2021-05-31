//
// Created by eagle on 2021/5/28.
//

#include "stack.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct SNode {
    T data;
    struct SNode *next;
} Node;


struct Stack_T {
    int length;
    Node *head;
};

Stack init() {
    Stack stack = (Stack) malloc(sizeof(Stack));
    stack->head = NULL;
    stack->length = 0;
    return stack;
}

int size(Stack s) {
    return s->length;
}

void push(Stack s, T data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = s->head;
    s->head = node;
    s->length++;
}

T pop(Stack s) {
    if (isEmpty(s) == TRUE) {
        printf("the stack is empty!\n");
        exit(ERROR_NULL_PTR);
    }
    Node *node = s->head;
    T data = node->data;
    s->head = node->next;
    s->length--;
    free(node);
    printf("pop: %d \n", data);
    return data;
}

T top(Stack s) {
    if (isEmpty(s) == TRUE) {
        printf("the stack is empty!\n");
        exit(ERROR_NULL_PTR);
    }
    T data = s->head->data;
    printf("top: %d \n", data);
    return data;
}

void clear(Stack s) {
    Node *node = s->head;
    while (node != NULL) {
        s->head = node->next;
        free(node);
        node = s->head;
    }
    s->length = 0;
}

void destroy(Stack s) {
    s->length = 0;
    s->head = NULL;
    s = NULL;
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
        printf("the link stack is empty!\n");
        return;
    }
    printf("\nstack's elements: \n");
    Node *temp = s->head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\ntraverse done!\n");
}