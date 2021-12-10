//
// Created by eagle on 2021/6/2.
//

#include "binary_tree.h"

typedef struct BNode {
    T data;
    struct BNode *left;
    struct BNode *right;
} Node;

struct Tree_T {
    Node *root;
    int length;
};

// 初始化二叉树
Tree initTree() {
    Tree tree = (Tree) malloc(sizeof(Tree));
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
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    if (tree->root == NULL) {
        tree->length++;
        tree->root = node;
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

Node *removeElemNode(Node *node, T data) {
    if (node == NULL) {
        return NULL;
    }
    if (node->data == data) {
        if (node->left == NULL) {
            Node *temp = node;
            node = temp->right;
            free(temp);
            return node;
        } else if (node->right == NULL) {
            Node *temp = node;
            node = temp->left;
            free(temp);
            return node;
        } else {
            // 左右子树非空，获取右子树的最小值
            // 替换待删除节点的值，
            // 然后删除该右子树的最小值(最小值的左子树必为空)
            // 运用递归的思路
            Node *temp = node->right;
            while (temp->left) {
                temp = temp->left;
            }
            node->data = temp->data;
            // 这样删除子节点时不用考虑原父节点的左右子节点指针指向问题,
            // 直接返回子节点本身就可以修改对应父节点左右子节点指针指向
            node->right = removeElemNode(node->right, temp->data);
        }
    } else if (node->data > data) {
        node->left = removeElemNode(node->left, data);
    } else if (node->data < data) {
        node->right = removeElemNode(node->right, data);
    }
    return node;
}

// 移除元素
void removeElem(Tree tree, T data) {
    Node *node = findNode(tree, data);
    if (node == NULL || node->data != data) {
        printf("\n---don't find element---\n");
        return;
    }
    removeElemNode(tree->root, data);
    tree->length--;
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
    getNodeHeight(tree->root);
}

void preOrderNode(Node *node,int depth) {
    if (node != NULL) {
        printf("\n");
        for (int i = 0; i <depth ; ++i) {
            printf("-");
        }
        printf("%d", node->data);
        preOrderNode(node->left,depth+1);
        preOrderNode(node->right,depth+1);
    }
}

// 先序遍历
void preOrder(Tree tree) {
    printf("\n--- Pre Order Traverse ---\n");
    preOrderNode(tree->root,0);
}

void inOrderNode(Node *node) {
    if (node != NULL) {
        inOrderNode(node->left);
        printf("%d ", node->data);
        inOrderNode(node->right);
    }
}

void inOrderNoRec(Node *node) {
    Node *stack[40]={NULL};
    int stack_ptr=0;
    Node *ptr = node;
    while (ptr != NULL || stack_ptr!=0) {
        if (ptr != NULL) {
            stack[stack_ptr++]=ptr;
            ptr = ptr->left;
        } else {
            ptr = stack[--stack_ptr];
            printf("%d ", ptr->data);
            ptr = ptr->right;
        }
    }
}

// 中序遍历
void inOrder(Tree tree) {
    printf("\n--- In Order Traverse ---\n");
    inOrderNode(tree->root);
    printf("\n--- In Order Traverse No rec---\n");
    inOrderNoRec(tree->root);
}

void postOrderNode(Node *node) {
    if (node != NULL) {
        postOrderNode(node->left);
        postOrderNode(node->right);
        printf("%d ", node->data);
    }
}

// 后序遍历
void postOrder(Tree tree) {
    printf("\n--- Post Order Traverse ---\n");
    postOrderNode(tree->root);
}

// 层序遍历
void levelOrder(Tree tree) {
    printf("\n--- Level Order Traverse ---\n");
    Node **temp = (Node **) malloc(tree->length * sizeof(Node *));
    int in = 0;
    int out = 0;
    temp[in++] = tree->root; //先保存二叉树根节点
    while (in > out) {
        if (temp[out]) {
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

// 打印树
void printTree(Tree tree) {
    printf("\n--- print Tree ---\n");
}