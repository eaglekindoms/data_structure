/*
 * 顺序表(线性表的顺序实现, 存储结构)
 * 定义：
 *     1.用一组地址连续的存储单元依次存储线性表中的数据元素
 *     2.一维数组空间分配（动态分配，静态分配）
 * 特点：
 *     1.随机访问，通过首地址和序号可在o(1)时间内找到指定元素
 *     2.存储密度高，每个节点只存储数据元素
 *     3.逻辑上相邻的元素在物理位置上也相邻
 *     4.插入和删除操作，需移动大量元素
 * 线性表基本操作的实现：
 *     1.插入（原长度为n）
 *       最好情况：表尾插入(i=n+1)，时间复杂度O(1)
 *       最坏情况：表头插入(i=1),需执行后移语句n次，时间复杂度O(n)
 *       平均情况：O(n)
 *     2.删除（原长度为n）
 *       最好情况：表尾删除，时间复杂度O(1)
 *       最坏情况：表头删除,需执行前移语句n次，时间复杂度O(n)
 *       平均情况：O(n)
 *     3.查找（原长度为n）
 *       最好情况：查找元素在表头，时间复杂度O(1)
 *       最坏情况：查找元素在表尾,需比较n次，时间复杂度O(n)
 *       平均情况：O(n)
 */
#include "linear_list.h"
#include <memory.h>

#define TABLE_INIT_SIZE 10
#define TABLE_INCREMENT 5

struct linear_list {
    T *head;
    int length;
    int capacity;
};

List initList() {
    List t = (List) malloc(sizeof(List));
    t->head = (T *) malloc(TABLE_INIT_SIZE * sizeof(T));
    memset(t->head, 0, TABLE_INIT_SIZE * sizeof(T));
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
    list->length = 0;
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