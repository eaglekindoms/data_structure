//
// Created by eagle on 2021/11/11.
// hash 表 及hash冲突解决算法
//
#include "stdio.h"
#include "string.h"

typedef char K;
typedef char *V;
typedef struct HNode {
    K key;
    V value;
} HNode;

#define MAX_CAPACITY 20

typedef struct HTable {
    HNode raw[MAX_CAPACITY];
    int len;
} HTable;

HTable init_table() {
    HTable table;
    table.len = 0;
    return table;
}

/*
 * hash冲突解决办法
 * 拉链法：构造链表
 * 直接定址法：冲突后地址递增
 * 再hash法：使用多个hash算法，
 */
int hash(K key);

void put_node(HTable *table, HNode node);

V get_value(HTable table, K key);

int main() {
    HTable table = init_table();
    printf("%d", table.len);
    HNode node;
    node.key = 'c';
    node.value = "bb";
    put_node(&table, node);
    printf(" %s\n", get_value(table, 'c'));
    char *s = "jkaqnkqnieyvkamlq,dq.13";
    for (int i = 0; i < strlen(s); ++i) {
        printf("%d ", hash(s[i]));
    }
}

int hash(K key) {
    return ((int) key) % 13;
}

void put_node(HTable *table, HNode node) {
    if (table->len == MAX_CAPACITY) return;
    int index = hash(node.key);
    while (table->raw[index].key >= 0) {
        index++;
    }
    table->raw[index] = node;
    table->len += 1;
}

V get_value(HTable table, K key) {
    int index = hash(key);
    while (table.raw[index].key >= 0) {
        HNode node = table.raw[index];
        if (node.key == key) return node.value;
        index++;
    }
    return NULL;
}