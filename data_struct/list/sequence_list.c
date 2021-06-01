#include <stdio.h>
#include <stdlib.h>
#include "linear_list.h"

#define TABLE_INIT_SIZE 10
#define TABLE_INCREMENT 5

struct linear_list {
    int *head;
    int length;
    int capacity;
};

List initList() {
    List t = (List) malloc(sizeof(List));
    t->head = (T *) malloc(TABLE_INIT_SIZE * sizeof(T));
    if (!t->head) {
        printf("---malloc memory failed---\n");
        exit(ERROR_MALLOC_FAILED);
    }
    t->length = 0;
    t->capacity = TABLE_INIT_SIZE;
    return t;
}

void insertElem(List table, int index, T data) {
    if (index > table->length || index < 0) {
        printf("---invalid index---");
        exit(ERROR_INVALID_INDEX);
    }
    if (table->length >= table->capacity) {
        table->head = (T *) realloc(table->head, TABLE_INCREMENT * sizeof(T));
        if (!table->head) {
            printf("---malloc memory failed---\n");
            exit(ERROR_MALLOC_FAILED);
        }
        table->capacity += TABLE_INCREMENT;
    }
    for (int i = table->length - 1; i >= index; i--) {
        table->head[i + 1] = table->head[i];
    }
    table->head[index] = data;
    table->length++;
}

void addElem(List table, T data) {
    insertElem(table, table->length, data);
}

void replaceElem(List table, int index, T data) {
    if (index > table->length - 1 || index < 0) {
        printf("---invalid index---");
        exit(ERROR_INVALID_INDEX);
    }
    table->head[index] = data;
}

T getElem(List table, int index) {
    if (index > table->length - 1 || index < 0) {
        printf("---invalid index---");
        exit(ERROR_INVALID_INDEX);
    }
    return table->head[index];
}

int searchElem(List table, T data) {
    for (int i = 0; i < table->length; ++i) {
        if (table->head[i] == data) {
            return i;
        }
    }
    return -1;
}

T removeElem(List table, int index) {
    if (index > table->length - 1 || index < 0) {
        printf("---invalid index---");
        exit(ERROR_INVALID_INDEX);
    }
    T data = table->head[index];
    for (int i = index; i < table->length - 1; i++) {
        table->head[i] = table->head[i + 1];
    }
    table->length--;
    return data;
}

int getLength(List list) {
    return list->length;
}

int isEmpty(List list) {
    return list->length == 0;
}

void clearList(List list) {

}

void printList(List table) {
    printf("\n--- print all of elements at the table ---\n");
    for (int i = 0; i < table->length; ++i) {
        printf("%d ", table->head[i]);
    }
    printf("\n");
}

void uniqueFun(List list) {

}