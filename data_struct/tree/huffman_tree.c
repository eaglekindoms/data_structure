//
// Created by eagle on 2021/6/23.
// 哈夫曼树动态数组实现
//

#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "error_code.h"
#include "boolean.h"

typedef struct HNode {
    int weight;
    char data;
    struct HNode *parent, *left, *right;
} HNode, *Tree;

// 树初始化
Tree initTree() {
    Tree tree = NULL;
    return tree;
}

// 创建节点
HNode *createNode(int weight, char data) {
    HNode *node = (HNode *) malloc(sizeof(HNode));
    node->data = data;
    node->weight = weight;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 树节点合并

// 树叶子节点遍历

int main() {
    printf("\n---Huffman Tree---\n");
    return 0;
}