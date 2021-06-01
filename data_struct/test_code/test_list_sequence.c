//
// Created by eagle on 2021/5/31.
//

#include "../list/linear_list.h"
#include "stdio.h"

int main() {
    List t1 = initList();
    for (int i = 1; i <= 10; i++) {
        addElem(t1, i);
    }
    printf("the original List: \n");
    printList(t1);

    printf("delete the element at position 1: \n");
    removeElem(t1, 1);
    printList(t1);

    printf("insert \"5\" at the position 2: \n");
    replaceElem(t1, 2, 5);
    insertElem(t1, 2, 19);
    printList(t1);

    printf("search the position of element 3: \n");
    int add = searchElem(t1, 3);
    printf("%d\n", add);

    printf("change element 3 to element 6: \n");
    replaceElem(t1, 3, 6);
    printList(t1);
    return 0;
}