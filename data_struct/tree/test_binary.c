//
// Created by eagle on 2021/6/2.
//

#include "binary_tree.h"

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
int test_binary_tree()
{
    Tree tree = initTree();
    putElem(tree, 20);
    putElem(tree, 9);
    putElem(tree, 27);
    putElem(tree, 2);
    putElem(tree, 12);
    putElem(tree, 13);
    putElem(tree, 1);
    putElem(tree, 4);
    putElem(tree, 3);
    putElem(tree, 5);
    putElem(tree, 7);
    putElem(tree, 6);
    putElem(tree, 38);
    putElem(tree, 30);
    putElem(tree, 29);
    putElem(tree, 31);
    putElem(tree, 22);
    printf("\nCurrent Root: %d\n", getRoot(tree));
    printf("\nCurrent Height: %d\n", getHeight(tree));
    printf("\nCurrent Length: %d\n", getLength(tree));
    removeElem(tree, 20);
    printf("\nCurrent Root: %d\n",getRoot(tree));
    printf("\nCurrent Height: %d\n", getHeight(tree));
    removeElem(tree, 6);
    printf("\nCurrent Height: %d\n", getHeight(tree));
    printf("\nCurrent Length: %d\n", getLength(tree));
    preOrder(tree);
    inOrder(tree);
    postOrder(tree);
    levelOrder(tree);
    return 0;
}