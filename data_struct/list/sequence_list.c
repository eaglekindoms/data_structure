#include <stdio.h>
#include <stdlib.h>
#include "error_code.h"

#define TABLE_INIT_SIZE 10
#define TABLE_INCREMENT 5

typedef int T;
typedef struct STable {
    int *head;
    int length;
    int capacity;
} *Table;

Table initTable() {
    Table t = (Table) malloc(sizeof(Table));
    t->head = (T *) malloc(TABLE_INIT_SIZE * sizeof(T));
    if (!t->head) {
        printf("---malloc memory failed---\n");
        exit(ERROR_MALLOC_FAILED);
    }
    t->length = 0;
    t->capacity = TABLE_INIT_SIZE;
    return t;
}

void insertElem(Table table, int index, T data) {
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

void setElem(Table table, int index, T data) {
    if (index > table->length - 1 || index < 0) {
        printf("---invalid index---");
        exit(ERROR_INVALID_INDEX);
    }
    table->head[index] = data;
}

void addElem(Table table, T data) {
    insertElem(table, table->length, data);
}

T getElem(Table table, int index) {
    if (index > table->length - 1 || index < 0) {
        printf("---invalid index---");
        exit(ERROR_INVALID_INDEX);
    }
    return table->head[index];
}

T removeElem(Table table, int index) {
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

int searchElem(Table table, T data) {
    for (int i = 0; i < table->length; ++i) {
        if (table->head[i] == data) {
            return i;
        }
    }
    return -1;
}

void replaceElem(Table table, T old, T new) {
    int oldIndex = searchElem(table, old);
    while (oldIndex != -1 && old != new) {
        table->head[oldIndex] = new;
        oldIndex = searchElem(table, old);
    }
}

void printTable(Table table) {
    printf("\n--- print all of elements at the table ---\n");
    for (int i = 0; i < table->length; ++i) {
        printf("%d ", table->head[i]);
    }
    printf("\n");
}
