#include "../list/linear_list.h"
#include "stdio.h"

int main() {
    printf("\nTest Init List\n");
    List list = initList();
    addElem(list, 1);
    addElem(list, 2);
    addElem(list, 3);
    addElem(list, 4);
    addElem(list, 5);
    printList(list);
    printf("\nTest Insert Data\n");
    insertElem(list, 0, 121);
    insertElem(list, getLength(list) - 1, 11);
    printf("the size of list is : %d\n", getLength(list));
    printList(list);
    printf("\nTest Different Implementations\n");
    uniqueFun(list);
    printf("\nTest replace Data\n");
    replaceElem(list, 2, 9);
    printList(list);
    printf("\nTest Remove Data\n");
    printf("reomve data: %d\n", removeElem(list, 0));
    printf("reomve data: %d\n", removeElem(list, 4));
    printList(list);
    printf("\nTest Get&Search Data\n");
    printf("get the element of index 4: %d\n", getElem(list, 4));
    printf("get the index of element 3: %d\n", searchElem(list, 3));
    printf("\nTest Clear List\n");
    clearList(list);
    printList(list);
    printf("\nTest Re-insert Data\n");
    addElem(list, 5);
    printList(list);
    return 0;
}