#include "linear_list.h"
#include <string.h>

#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 5

typedef struct raw_data
{
    int next_ptr;
    T data;
} RawData;

struct linear_list
{
    RawData *head;
    int length;
    int capacity;
};

// 初始化线性表
List initList()
{
    List list = (List)malloc(sizeof(List));
    list->head = (RawData *)malloc(LIST_INIT_SIZE * sizeof(RawData));
    memset(list->head, 0, LIST_INIT_SIZE * sizeof(RawData));
    if (!list->head)
    {
        printf("---malloc memory failed---\n");
        exit(ERROR_MALLOC_FAILED);
    }
    list->length = 0;
    list->capacity = LIST_INIT_SIZE;
    return list;
}

// 数组扩容
void reallocList(List list)
{
    if (list->length >= list->capacity)
    {
        list->head = (RawData *)realloc(list->head, LIST_INCREMENT * sizeof(RawData));
        if (!list->head)
        {
            printf("---malloc memory failed---\n");
            exit(ERROR_MALLOC_FAILED);
        }
        list->capacity += LIST_INCREMENT;
    }
}

// 从数组中获取空闲区块索引
int getFreeSpace(List list)
{
    for (int i = 0; i <= list->capacity; i++)
    {
        RawData freeSpace = list->head[i];
        if (freeSpace.data==0&&freeSpace.next_ptr==0)
        {
            return i;
        }

    }
    printf("non't free space");
    exit(ERROR_MALLOC_FAILED);
}

// 获取指定索引的数据
RawData *getCurrNode(List list, int index)
{
    RawData *temp = &list->head[0];
    for (int i = 0; i < index; i++)
    {
        temp = &list->head[temp->next_ptr];
    }
    return temp;
}
// 在指定位置插入元素，长度加一
void insertElem(List list, int index, T data)
{
    if (index > list->length || index < 0)
    {
        printf("---invalid index---");
        exit(ERROR_INVALID_INDEX);
    }

    reallocList(list);
    int freeIndex = getFreeSpace(list);
    RawData *piror = getCurrNode(list, index);
    list->head[freeIndex].data = piror->data;
    list->head[freeIndex].next_ptr = piror->next_ptr;
    piror->next_ptr = freeIndex;
    piror->data=data;
    list->length++;
}

// 添加元素
void addElem(List list, T data)
{
    reallocList(list);
    int freeIndex = getFreeSpace(list);
    list->head[freeIndex].data = data;
    list->head[freeIndex].next_ptr = -1;
    if (list->length > 0)
    {
        list->head[list->length - 1].next_ptr = freeIndex;
    }
    list->length++;
}

// 替换指定索引的元素
void replaceElem(List list, int index, T data)
{
    RawData *piror = getCurrNode(list, index);
    piror->data = data;
}

// 获取指定索引的元素
T getElem(List list, int index)
{
    RawData *piror = getCurrNode(list, index);
    return piror->data;
}

// 查找元素，返回索引
int searchElem(List list, T data)
{
    for (int i = 0; i < list->length; i++)
    {
        RawData *curr = getCurrNode(list, i);
        if (curr->data == data)
        {
            return i;
        }
    }
    return -1;
}

// 删除指定位置的元素
T removeElem(List list, int index)
{
    RawData *temp = getCurrNode(list, index);
    T data = temp->data;
    if (temp->next_ptr == -1)
    {
        temp->data = NULL;
        temp->next_ptr = NULL;
    }
    else
    {
        RawData *nextData = &list->head[temp->next_ptr];
        temp->data = nextData->data;
        temp->next_ptr = nextData->next_ptr;
        nextData->data = NULL;
        nextData->next_ptr = NULL;
    }
    list->length--;
    return data;
}

// 获取线性表长度
int getLength(List list)
{
    return list->length;
}

// 判断线性表是否为空
int isEmpty(List list)
{
    return list->length == 0;
}

// 清空线性表
void clearList(List list)
{
    for (int i = 0; i < list->length; i++)
    {
        RawData *temp = getCurrNode(list, i);
        temp->data = NULL;
        temp->next_ptr = NULL;
    }
    list->length = 0;
}

// 打印线性表所有元素
void printList(List list)
{
    printf("\n--- Print Static Link List ---\n");
    for (int i = 0; i < list->length; i++)
    {
        RawData *temp = getCurrNode(list, i);
        printf("%d ", temp->data);
    }
    printf("\n--- Print Done ---\n");
}

//独有方法
void uniqueFun(List list)
{
}