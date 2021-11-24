//
// Created by eagle on 2021/6/2.
//

#ifndef DATA_STRUCTURE_BINARY_TREE_H
#define DATA_STRUCTURE_BINARY_TREE_H

#include "stdio.h"
#include "stdlib.h"
#include "error_code.h"
#include "boolean.h"

typedef int T;
typedef struct Tree_T *Tree;

/*
 * 前+中序，后+中序，层+中序 可以确定一颗二叉树
 */

// 初始化二叉树
Tree initTree();

// 插入元素
void putElem(Tree tree, T data);

// 移除元素
void removeElem(Tree tree, T data);

// 查找元素
int searchElem(Tree tree, T data);

// 获取根节点数据
int getRoot(Tree tree);

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

// 打印树
void printTree(Tree tree);
#endif //DATA_STRUCTURE_BINARY_TREE_H
