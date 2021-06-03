//
// Created by eagle on 2021/6/2.
//

#include "binary_tree.h"

typedef struct BNode
{
    T data;
    struct BNode *left;
    struct BNode *right;
} Node;

struct Tree_T
{
    Node *root;
    int length;
};

// 初始化二叉树
Tree initTree()
{
    Tree tree = (Tree)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->length = 0;
    return tree;
}

// 查找父节点
/**
 * if data==node.data return node
 * if node.
 * */
Node *findParentNode(Tree tree, T data)
{
    if (tree->root == NULL)
    {
        exit(ERROR_NULL_PTR);
    }
    Node *curr = tree->root;
    while (data < curr->data)
    {
        if (curr->left == NULL)
        {
            return curr;
        }
        else
        {
            curr = curr->left;
        }
    }

    return tree->root;
}

// 插入元素
void putElem(Tree tree, T data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (tree->root == NULL)
    {
        tree->length++;
        tree->root = node;
    }
    else
    {
        Node *parent = findParentNode(tree, data);
        if (data < parent->data)
        {
            parent->left = node;
        }
        else
        {
            parent->right = node;
        }
    }
}

// 移除元素
void removeElem(Tree tree, T data)
{
    Node *parent = findParentNode(tree, data);
    if (parent->data != data)
    {
        printf("\n---don't find element---\n");
        return;
    }
}

// 查找元素
int searchElem(Tree tree, T data)
{
}

// 获取树元素总量
int getLength(Tree tree)
{
}

// 获取树高
int getHeight(Tree tree)
{
}

// 先序遍历
void preOrder(Tree tree)
{
}

// 中序遍历
void inOrder(Tree tree)
{
}

// 后序遍历
void postOrder(Tree tree)
{
}

// 层序遍历
void levelOrder(Tree tree)
{
}
