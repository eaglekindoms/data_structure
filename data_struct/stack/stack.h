//
// Created by eagle on 2021/5/28.
//
#ifndef DATA_STRUCTURE_SQ_STACK_H
#define DATA_STRUCTURE_SQ_STACK_H

#include "error_code.h"
#include "boolean.h"

typedef int T;

typedef struct Stack_T *Stack;

// 栈初始化
Stack initStack();

// 获取栈长度
int getLength(Stack s);

// 压栈
void pushStack(Stack s, T data);

// 出栈
T popStack(Stack s);

// 获取栈顶元素
T getTop(Stack s);

// 清空栈
void clearStack(Stack s);

// 销毁栈
void destroy(Stack s);

// 栈判空
int isEmpty(Stack s);

// 遍历打印栈
void printStack(Stack s);

#endif //DATA_STRUCTURE_SQ_STACK_H
