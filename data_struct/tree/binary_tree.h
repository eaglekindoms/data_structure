//
// Created by eagle on 2021/6/2.
//

#ifndef DATA_STRUCTURE_BINARY_TREE_H
#define DATA_STRUCTURE_BINARY_TREE_H

#include "stdio.h"
#include "stdlib.h"
#include "error_code.h"

typedef int T;
typedef struct Tree_T *Tree;

// 初始化二叉树
Tree initTree();

// 插入元素
void putElem(Tree tree, T data);

// 移除元素
void removeElem(Tree tree, T data);

// 查找元素
int searchElem(Tree tree, T data);

// 获取树元素总量
int getLength(Tree tree);

// 获取树高
int getHeight(Tree tree);

// 先序遍历
void preOrder(Tree tree);

// 中序遍历
void inOrder(Tree tree);

// 后序遍历
void postOrder(Tree tree);

// 层序遍历
void levelOrder(Tree tree);

#endif //DATA_STRUCTURE_BINARY_TREE_H
