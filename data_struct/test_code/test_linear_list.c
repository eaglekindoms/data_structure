#include "../list/linear_list.h"
#include "stdio.h"

int test_list() {
    List list = initList();
    addElem(list, 1);
    addElem(list, 2);
    addElem(list, 3);
    addElem(list, 4);
    addElem(list, 5);
    printList(list);
    insertElem(list, 0, 121);
    printList(list);
    printf("the size of list is : %d\n", getLength(list));
    insertElem(list, getLength(list) - 1, 11);
    printList(list);
    uniqueFun(list);
    printList(list);
    replaceElem(list, 2, 9);
    printf("reomve data: %d\n", removeElem(list, 0));
    printf("reomve data: %d\n", removeElem(list, 4));
    printf("get the element of index 4: %d\n", getElem(list, 4));
    printf("get the index of element 3: %d\n", searchElem(list, 3));
    printList(list);
    clearList(list);
    printList(list);
    addElem(list, 5);
    printList(list);
    return 0;
}