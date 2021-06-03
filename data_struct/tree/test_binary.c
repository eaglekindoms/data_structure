//
// Created by eagle on 2021/6/2.
//

#include "binary_tree.h"

int test_binary_tree() {
    Tree tree = initTree();
    putElem(tree, 2);
    putElem(tree, 42);
    putElem(tree, 2);
    putElem(tree, 24);
    putElem(tree, 21);
    removeElem(tree,222);
    preOrder(tree);
    return 0;
}