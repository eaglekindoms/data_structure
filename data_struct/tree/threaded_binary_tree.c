//
// Created by eagle on 2021/6/23.
// 线索二叉树
//

#include "binary_tree.h"

typedef struct BNode {
    T data; // 节点本身数据
    struct BNode *left, *right; // 左右子节点指针
    int ltag; // 左标识，0-表示指针指向子节点，1-表示指针指向前驱节点
    int rtag; // 右标识，0-表示指针指向子节点，1-表示指针指向后继节点
} Node;

struct Tree_T {
    Node *head;
    Node *root;
    int length;
};

Node *createNode(T data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->ltag = 0;
    node->rtag = 0;
    return node;
}

// 初始化二叉树
Tree initTree() {
    Tree tree = (Tree) malloc(sizeof(Tree));
    tree->head = createNode(0);
    tree->root = NULL;
    tree->length = 0;
    return tree;
}

// 查找节点
/**
 * if data==node.data return node
 * */
Node *findNode(Tree tree, T data) {
    if (tree->root == NULL) {
        exit(ERROR_NULL_PTR);
    }
    Node *curr = tree->root;
    while (curr != NULL) {
        if (data > curr->data) {
            if (curr->right == NULL)
                return curr;
            curr = curr->right;
        } else if (data < curr->data) {
            if (curr->left == NULL)
                return curr;
            curr = curr->left;
        } else {
            return curr;
        }
    }
    return NULL;
}

// 插入元素
void putElem(Tree tree, T data) {
    Node *node = createNode(data);
    if (tree->root == NULL) {
        tree->length++;
        tree->root = node;
        tree->head->left = tree->root;
        return;
    } else {
        Node *parent = findNode(tree, data);
        if (data < parent->data) {
            parent->left = node;
            tree->length++;
            return;
        } else if (data > parent->data) {
            parent->right = node;
            tree->length++;
            return;
        }
    }
}

// 移除元素
void removeElem(Tree tree, T data) {
    return;
}

// 查找元素
int searchElem(Tree tree, T data) {
    Node *node = findNode(tree, data);
    if (node != NULL && data == node->data) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// 获取根节点数据
int getRoot(Tree tree) {
    return tree->root->data;
}

// 获取树元素总量
int getLength(Tree tree) {
    return tree->length;
}

int getNodeHeight(Node *node) {
    if (node == NULL) {
        return 0;
    }
    int left = getNodeHeight(node->left);
    int right = getNodeHeight(node->right);
    return (left > right) ? left + 1 : right + 1;
}

// 获取树高
int getHeight(Tree tree) {
   return getNodeHeight(tree->root);
}


// 先序遍历,
void preOrder(Tree tree) {
    return;
}

void visitNode(Node *node, Node **pre) {
    if (node->left == NULL) {//处理前驱，什么时候能知道前驱，就是当前节点的时候，
        //已经知道前一个是pre了，所以直接tag=thread，lchild=pre
        node->ltag = 1;
        node->left = *pre;
    }
    if (*pre != NULL && (*pre)->right == NULL) {
        //处理后继，什么时候处理后继，只有访问到下一个的时候，
        //才能知道下一个是谁，因为当访问下一个的时候，下一个是T，让pre的rchild指向T就好
        (*pre)->rtag = 1;
        (*pre)->right = node;
    }
    *pre = node;
}

void inThreading(Node *node, Node **pre) {
    if (node) {
        inThreading(node->left, pre);//递归左孩子线索
        //节点处理
        visitNode(node, pre);
        inThreading(node->right, pre);//递归右孩子线索
    }
}

void preThreading(Node *node, Node **pre) {
    if (node) {
        //节点处理
        visitNode(node, pre);
        if (node->ltag == 0) {
            preThreading(node->left, pre);//递归左孩子线索
        }
        preThreading(node->right, pre);//递归右孩子线索
    }
}

void postThreading(Node *node, Node **pre) {
    if (node) {
        postThreading(node->left, pre);//递归左孩子线索
        postThreading(node->right, pre);//递归右孩子线索
        //节点处理
        visitNode(node, pre);
    }
}

// 返回以node为根的子树中第一个被中序遍历的节点
Node *inFirstNode(Node *node) {
    while (node->ltag == 0) node = node->left;
    return node;
}

// 返回中序线索二叉树中node的后继节点
Node *inNextNode(Node *node) {
    if (node->rtag == 0)
        return inFirstNode(node->right);
    else
        return node->right;
}


// 返回以node为根的子树中最后一个被中序遍历的节点
Node *inLastNode(Node *node) {
    while (node->rtag == 0) node = node->right;
    return node;
}

// 返回中序线索二叉树中node的前驱节点
Node *inPreNode(Node *node) {
    if (node->ltag == 0)
        return inLastNode(node->left);
    else
        return node->left;
}

// 中序遍历
void inOrder(Tree tree) {
    // 线索化
    //全局变量用于暂存当前访问结点的前驱
    Node *pre = NULL;
    if (tree != NULL) {//非空二叉树才能线索化
        inThreading(tree->root, &pre);//中序线索二叉树
        pre->right = NULL;//处理遍历的最后最后一个结点
        pre->rtag = 1;
    }
    // 非递归遍历
    printf("in-Threading order\n");
    for (Node *node = inFirstNode(tree->root); node != NULL; node = inNextNode(node)) {
        printf(" %d", node->data);
    }
    printf("\nreverse in-Threading order\n");
    for (Node *node = inLastNode(tree->root); node != NULL; node = inPreNode(node)) {
        printf(" %d", node->data);
    }
}

// 后序遍历
void postOrder(Tree tree) {
    return;
}

// 层序遍历
void levelOrder(Tree tree) {
    return;
}

void printTree(Tree tree) {
    printf("\n--- print Tree ---\n");
}