//
// Created by eagle on 2021/6/23.
//
#include "stdio.h"
#include "stdlib.h"

typedef int T;
// 特性：平衡因子不能够大于1。
// 平衡二叉树节点
typedef struct AVLNode {
    T data;// 数据域
    int height;// 节点高度
    struct AVLNode *left, *right;
} AVLNode, *AVLTree;

AVLNode *init_node(T data) {
    AVLNode *node = (AVLNode *) malloc(sizeof(AVLNode));
    node->data = data;
    node->height = NULL;
    node->right = NULL;
    node->left = NULL;
    return node;
}

int get_height(AVLNode *node) {
    if (node == NULL) return -1;
    return node->height;
}

int get_balance(AVLNode *node) {
    if (node == NULL) return 0;
    return get_height(node->left) - get_height(node->right);
}

AVLNode *search_node(AVLNode *root, T data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (root->data > data) {
        return search_node(root->left, data);
    }
    return search_node(root->right, data);
}

// 右旋
AVLNode *right_rotate(AVLNode *node) {
    AVLNode *new_node = node->left;
    AVLNode *old_node_child = new_node->right;
    // 右旋
    new_node->right = node;
    node->left = old_node_child;
    // 更新节点高度
    node->height = max(get_height(node->left),
                       get_height(node->right)) + 1;
    new_node->height = max(get_height(new_node->left),
                           get_height(new_node->right)) + 1;
    return new_node;
}

// 左旋
AVLNode *left_rotate(AVLNode *node) {
    AVLNode *new_node = node->right;
    AVLNode *old_node_child = new_node->left;
    // 左旋
    new_node->left = node;
    node->right = old_node_child;
    // 更新节点高度
    node->height = max(get_height(node->left),
                       get_height(node->right)) + 1;
    new_node->height = max(get_height(new_node->left),
                           get_height(new_node->right)) + 1;
    return new_node;
}

/*
 * https://www.cnblogs.com/flydean/p/15409557.html
 * 平衡节点的算法
 * 存在几种情况：
 *    计算节点的平衡因子 rootb(左子树高 - 右子树高)
 *    2.1 rootb>1 (左子树不平衡)
 *        2.1.1 lb>=0 为 left-left结构 进行一次右旋即可(new root=root.left)
 *        2.1.2 lb<0 为 left-right结构 先左旋再右旋(new root=root.left.right)
 *    2.2 rootb<-1 (右子树不平衡)
 *        2.2.1 rb<=0 为 right-right结构 进行一次左旋即可(new root=root.right)
 *        2.2.2 rb>0 为 right-left结构 先右旋再左旋(new root=root.right.left)
 */
AVLNode *balance_node(AVLNode *node) {
    //判断节点是否平衡
    int balance = get_balance(node);

    //left-left
    if (balance > 1 && get_balance(node->left) >= 0)
        return right_rotate(node);

    // Right-Right
    if (balance < -1 && get_balance(node->right) <= 0)
        return left_rotate(node);

    // Left Right
    if (balance > 1 && get_balance(node->left) < 0) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left
    if (balance < -1 && get_balance(node->right) > 0) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    //返回插入后的节点
    return node;
}

/*
 * 1. 根节点为空，直接插入，高度加一
 * 2. 根节点非空，按左小右大规则插入，插入后高度加一
 * 3. 平衡节点
 */
AVLNode *insert_node(AVLNode *node, T data) {
    // 先按照普通的BST方法插入节点
    if (node == NULL)
        return init_node(data);
    if (data < node->data)
        node->left = insert_node(node->left, data);
    else if (data > node->data)
        node->right = insert_node(node->right, data);
    else
        return node;

    //更新节点的高度
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    return balance_node(node);
}

/*
 * 先直接删除，然后再调整树让其平衡
 */
AVLNode *remove_node(AVLNode *node, T data) {
    //Step 1. 普通BST节点删除
    // 如果节点为空，直接返回
    if (node == NULL)
        return node;
    // 如果值小于当前节点，那么继续左节点删除
    if (data < node->data)
        node->left = remove_node(node->left, data);
        //如果值大于当前节点，那么继续右节点删除
    else if (data > node->data)
        node->right = remove_node(node->right, data);
        //如果值相同，那么就是要删除的节点
    else {
        // 如果是单边节点的情况
        if ((node->left == NULL) || (node->right == NULL)) {
            AVLNode *temp = NULL;
            if (temp == node->left)
                temp = node->right;
            else
                temp = node->left;
            //没有子节点的情况
            if (temp == NULL) {
                node = NULL;
            } else // 单边节点的情况
                node = temp;
        } else {  //非单边节点的情况
            // 拿到右侧节点的最小值
            // 然后删除该右子树的最小值(最小值的左子树必为空)
            // 运用递归的思路
            AVLNode *temp = node->right;
            while (temp->left) {
                temp = temp->left;
            }
            //将最小值作为当前的节点值
            node->data = temp->data;
            // 将该值从右侧节点删除
            node->right = remove_node(node->right, temp->data);
        }
    }
    // 如果节点为空，直接返回
    if (node == NULL)
        return node;

    //更新节点的高度
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    return balance_node(node);
}

void insert(AVLTree *tree, T data) {
    *tree = insert_node(*tree, data);
}

void removeT(AVLTree *tree, T data) {
    *tree = remove_node(*tree, data);
}

int main() {
    AVLTree tree = NULL;
    int data[] = {20, 9, 27, 2, 12, 13, 1, 4, 3, 5, 7, 6, 38, 30, 29, 31, 22};
    for (int i = 0; i < sizeof(data) / sizeof(int); ++i) {
        insert(&tree, data[i]);
    }
    for (int i = 0; i < 6; ++i) {
        removeT(&tree, data[i]);
    }
    printf("%d\n", tree->data);
    printf("%d\n", tree->height);
    printf("%d\n", get_height(tree));
    printf("%d\n", get_balance(tree));
}