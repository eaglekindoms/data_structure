//
// Created by eagle on 2021/6/2.
//

#include "binary_tree.h"

typedef struct BNode
{
    T data;
    struct BNode *parent;
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
 * */
Node *findParentNode(Tree tree, T data)
{
    if (tree->root == NULL)
    {
        exit(ERROR_NULL_PTR);
    }
    Node *curr = tree->root;
    while (curr != NULL)
    {
        if (data > curr->data)
        {
            if (curr->right == NULL)
                return curr;
            curr = curr->right;
        }
        else if (data < curr->data)
        {
            if (curr->left == NULL)
                return curr;
            curr = curr->left;
        }
        else
        {
            return curr;
        }
    }
    return NULL;
}

// 插入元素
void putElem(Tree tree, T data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    if (tree->root == NULL)
    {
        tree->length++;
        tree->root = node;
        return;
    }
    else
    {
        Node *parent = findParentNode(tree, data);
        if (data < parent->data)
        {
            node->parent = parent;
            parent->left = node;
            tree->length++;
            return;
        }
        else if (data > parent->data)
        {
            node->parent = parent;
            parent->right = node;
            tree->length++;
            return;
        }
    }
}

void removeElemNode(Node *node, T data)
{
    if (node == NULL)
    {
        return;
    }

    if (node->data == data)
    {
        if (node->left == NULL)
        {
            Node *temp = node;
            node = temp->right;
            if (node != NULL)
            {
                node->parent = temp->parent;
            }
            if (temp->parent->left->data == temp->data)
            {
                temp->parent->left = node;
            }
            else
            {
                temp->parent->right = node;
            }
            free(temp);
            return;
        }
        else if (node->right == NULL)
        {
            Node *temp = node;
            node = temp->left;
            if (node != NULL)
            {
                node->parent = temp->parent;
            }
            if (temp->parent->left->data == temp->data)
            {
                temp->parent->left = node;
            }
            else
            {
                temp->parent->right = node;
            }
            free(temp);
            return;
        }
        else
        {
            // 只有子树非空，获取右子树的最小值
            // 替换待删除节点的值，
            // 然后删除该右子树的最小值(最小值的左子树必为空)
            // 运用递归的思路
            Node *temp = node->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            node->data = temp->data;
            removeElemNode(node->right, temp->data);
        }
    }
    else if (node->data > data)
    {
        removeElemNode(node->left, data);
    }
    else if (node->data < data)
    {
        removeElemNode(node->right, data);
    }
}

// 移除元素
void removeElem(Tree tree, T data)
{
    Node *node = findParentNode(tree, data);
    if (node == NULL || node->data != data)
    {
        printf("\n---don't find element---\n");
        return;
    }
    removeElemNode(node, data);
    tree->length--;
}

// 查找元素
int searchElem(Tree tree, T data)
{
    Node *node = findParentNode(tree, data);
    if (node != NULL && data == node->data)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

// 获取根节点数据
int getRoot(Tree tree)
{
    return tree->root->data;
}

// 获取树元素总量
int getLength(Tree tree)
{
    return tree->length;
}

int getNodeHeight(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int left = getNodeHeight(node->left);
    int right = getNodeHeight(node->right);
    return (left > right) ? left + 1 : right + 1;
}
// 获取树高
int getHeight(Tree tree)
{
    getNodeHeight(tree->root);
}

void preOrderNode(Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preOrderNode(node->left);
        preOrderNode(node->right);
    }
}

// 先序遍历
void preOrder(Tree tree)
{
    printf("\n--- Pre Order Traverse ---\n");
    preOrderNode(tree->root);
}

void inOrderNode(Node *node)
{
    if (node != NULL)
    {
        inOrderNode(node->left);
        printf("%d ", node->data);
        inOrderNode(node->right);
    }
}

// 中序遍历
void inOrder(Tree tree)
{
    printf("\n--- In Order Traverse ---\n");
    inOrderNode(tree->root);
}

void postOrderNode(Node *node)
{
    if (node != NULL)
    {
        postOrderNode(node->left);
        postOrderNode(node->right);
        printf("%d ", node->data);
    }
}

// 后序遍历
void postOrder(Tree tree)
{
    printf("\n--- Post Order Traverse ---\n");
    postOrderNode(tree->root);
}

// 层序遍历
void levelOrder(Tree tree)
{
    printf("\n--- Level Order Traverse ---\n");
    Node *temp[tree->length];
    int in = 0;
    int out = 0;

    temp[in++] = tree->root; //先保存二叉树根节点

    while (in > out)
    {
        if (temp[out])
        {
            printf("%d ", temp[out]->data);
            if (temp[out]->left != NULL)
                temp[in++] = temp[out]->left;
            if (temp[out]->right != NULL)
                temp[in++] = temp[out]->right;
        }
        out++;
    }
    free(temp);
}
