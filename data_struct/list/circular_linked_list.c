//
// Created by eagle on 2021/5/30.
//

#include "linear_list.h"

typedef struct SNode {
    T data;
    struct SNode *next;
} Node;


struct linear_list {
    int length;
    Node *head;
};

// 初始化线性表
List initList() {
    List list = (List) malloc(sizeof(List));
    list->head = (Node *) malloc(sizeof(Node));
    list->head->next = list->head;
    list->length = 0;
    return list;
}

// 获取尾节点
Node *getTailNode(List list) {
    Node *temp = list->head->next;
    Node *tail = NULL;
    while (temp) {
        if (temp->next == list->head->next) {
            tail = temp;
            break;
        }
        temp = temp->next;
    }
    return tail;
}

// 获取指定索引的前驱节点
Node *getPriorNode(List list, int index) {
    Node *temp = list->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

// 在指定位置插入元素，长度加一
void insertElem(List list, int index, T data) {
    if (index > list->length - 1 || index < 0) {
        printf("---invalid index---");
        exit(ERROR_INVALID_INDEX);
    }
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;

    Node *prior = getPriorNode(list, index);
    node->next = prior->next;
    prior->next = node;
    list->length++;
}

// 添加元素
void addElem(List list, T data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (list->length == 0) {
        list->head->next = node;
        node->next = list->head->next;
        list->length++;
        return;
    }

    Node *tail = getTailNode(list);
    node->next = tail->next;
    tail->next = node;
    list->length++;
}

// 替换指定索引的元素
void replaceElem(List list, int index, T data) {
    if (index > list->length - 1 || index < 0 || isEmpty(list)) {
        printf("---invalid index---");
        exit(ERROR_INVALID_INDEX);
    }
    Node *prior = getPriorNode(list, index);
    prior->next->data = data;
}

// 获取指定索引的元素
T getElem(List list, int index) {
    if (index > list->length - 1 || index < 0 || isEmpty(list)) {
        printf("---invalid index---");
        exit(ERROR_INVALID_INDEX);
    }
    Node *prior = getPriorNode(list, index);
    return prior->next->data;
}

// 查找元素，返回索引
int searchElem(List list, T data) {
    Node *temp = list->head;
    int index = -1;
    for (int i = 0; i < list->length; i++) {
        temp = temp->next;
        if (data == temp->data) {
            index = i;
        }
    }
    return index;
}

// 删除指定位置的元素
T removeElem(List list, int index) {
    if (index > list->length - 1 || index < 0 || isEmpty(list)) {
        printf("---invalid index---");
        exit(ERROR_INVALID_INDEX);
    }
    Node *prior = getPriorNode(list, index);
    Node *delNode = prior->next;
    T data = delNode->data;
    prior->next = prior->next->next;
    list->length--;
    free(delNode);
    return data;
}

// 获取线性表长度
int getLength(List list) {
    return list->length;
}

// 判断线性表是否为空
int isEmpty(List list) {
    return list->length == 0;
}

// 清空线性表
void clearList(List list) {
    printf("\n---clearStack list ---\n");
    Node *curr = list->head->next;
    for (int i = 0; i < list->length; i++) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    list->length = 0;
}

// 打印线性表所有元素
void printList(List list) {
    if (isEmpty(list)) {
        printf("\n---empty list ---\n");
        return;
    }
    printf("\n---print single link list ---\n");
    Node *temp = list->head;
    for (int i = 0; i < list->length; i++) {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n---print done---\n");
}

//独有方法
void uniqueFun(List list) {
    // 单链表反转
    printf("\n---reverse list ---\n");
    Node *tail = getPriorNode(list, list->length - 1)->next;
    for (int i = list->length - 1; i > 0; i--) {
        Node *prior = getPriorNode(list, i);
        prior->next->next = prior;
        // printf("%d ",prior->next->data);
    }
    list->head->next = tail;
}