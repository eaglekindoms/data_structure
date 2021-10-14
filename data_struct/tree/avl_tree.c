//
// Created by eagle on 2021/6/23.
//

typedef int T;

// 平衡二叉树节点
typedef struct AVLNode {
    T data;// 数据域
    int balance;// 平衡因子
    struct AVLNode *left, *right;
} AVLNode, *AVLTree;