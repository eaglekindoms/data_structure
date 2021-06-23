//
// Created by eagle on 2021/6/2.
//

#include "../tree/binary_tree.h"

/* 
      ┌─────────────────────────────────────┐
      │                   20                │
      │             /           \           │
      │            9             27         │
      │          /   \          /   \       │
      │       2        12     22     38     │
      │     /   \        \         /        │
      │    1     4        13      30        │
      │         / \              /  \       │
      │       3     5          29    31     │
      │              \                      │
      │                7                    │
      │              /                      │
      │             6                       │
      └─────────────────────────────────────┘
*/
int main() {
    Tree tree = initTree();
    int data[] = {20, 9, 27, 2, 12, 13, 1, 4, 3, 5, 7, 6, 38, 30, 29, 31, 22};
    int len = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < len; ++i) {
        putElem(tree, data[i]);
    }
    printf("\nCurrent Root: %d\n", getRoot(tree));
    printf("\nCurrent Height: %d\n", getHeight(tree));
    printf("\nCurrent Length: %d\n", getLength(tree));
    inOrder(tree);
    removeElem(tree, 20);
//    printf("\nCurrent Root: %d\n", getRoot(tree));
//    printf("\nCurrent Height: %d\n", getHeight(tree));
    removeElem(tree, 38);
    removeElem(tree, 6);
//    printf("\nCurrent Height: %d\n", getHeight(tree));
//    printf("\nCurrent Length: %d\n", getLength(tree));
    preOrder(tree);
    inOrder(tree);
    postOrder(tree);
    levelOrder(tree);
    return 0;
}