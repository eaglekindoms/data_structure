//
// Created by eagle on 2021/5/28.
//
#ifndef DATA_STRUCTURE_SQ_STACK_H
#define DATA_STRUCTURE_SQ_STACK_H

#include "error_code.h"
#include "boolean.h"

typedef int T;

typedef struct Stack_T *Stack;

Stack init();

int size(Stack s);

void push(Stack s, T data);

T pop(Stack s);

T top(Stack s);

void clear(Stack s);

void destroy(Stack s);

int isEmpty(Stack s);

void printStack(Stack s);

#endif //DATA_STRUCTURE_SQ_STACK_H
