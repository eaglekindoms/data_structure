#ifndef DATA_STRUCTURE_LINEAR_LIST_H
#define DATA_STRUCTURE_LINEAR_LIST_H

#include "error_code.h"

typedef int T;
typedef struct linear_list *List;

// 初始化线性表
List initList();

// 在指定位置插入元素，长度加一
void insertElem(List list, int index, T data);

// 添加元素
void addElem(List list, T data);

// 替换指定索引的元素
void replaceElem(List list, int index, T data);

// 获取指定索引的元素
T getElem(List list, int index);

// 查找元素，返回索引
int searchElem(List list, T data);

// 删除指定位置的元素
T removeElem(List list, int index);

// 获取线性表长度
int getLength(List list);

// 判断线性表是否为空
int isEmpty(List list);

// 清空线性表
void clearList(List list);

// 打印线性表所有元素
void printList(List list);

//独有方法
void uniqueFun(List list);

#endif