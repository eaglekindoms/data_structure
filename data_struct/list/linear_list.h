/*
 * 线性表（逻辑结构，表元素直接一对一的相邻关系）
 * 定义：具有相同数据类型的n个元素的有限序列，n=0时为空表
 * 特点：
 *     1.元素有限，元素有逻辑上的顺序性，元素有先后次序
 *     2.每个元素都是单个元素，每个元素占有相同的大小空间
 * 基本操作(API)：
 *     initList(&L); // 初始化表，构造空表
 *     length(L); // 返回表长
 *     locateElem(L, e); // 按值查找
 *     getElem(L, i); // 按位查找
 *     listInsert(&L, i, e); // 在指定位置插入指定元素
 *     listDelete(&L, i, &e); // 插入指定位置元素并返回
 *     printList(L); // 打印表，按先后顺序输出表中所有元素
 *     emptyList(L); // 判断表是否为空
 *     destroyList(&L); // 销毁表，释放表内存空间
 */
#ifndef DATA_STRUCTURE_LINEAR_LIST_H
#define DATA_STRUCTURE_LINEAR_LIST_H

#include <stdio.h>
#include <stdlib.h>
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