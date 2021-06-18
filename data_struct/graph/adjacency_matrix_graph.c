//
// Created by eagle on 2021/6/18.
//

#include "graph.h"

#define GRAPH_INIT_SIZE 20

// 边节点定义
struct EdgeNode {
    int adj;  // 是否邻接的标识 1-相邻 0-不相邻
    W weight; // 权重
};

// 图定义
struct Graph_T {
    T *vertices; // 图中顶点的数组
    ENode **edges; // 记录顶点关系
    int vertex_num; // 记录图中顶点数
    int edge_num; // 记录图中边数
    int capacity; // 容量
};

ENode **mallocAdjMatrix(int size) {
    // 初始化边邻接矩阵每行指针
    // 注：memset设初值时不能sizeof(graph->edges),因为graph->edges是指针只占一个指针位大小
    // 但是如：int arr[size] memset设初值时可直接sizeof(arr)
    ENode **matrix = (ENode **) malloc(size * sizeof(ENode *));
    if (!matrix)
        exit(ERROR_MALLOC_FAILED);
    // 为每行分配空间并设初值
    for (int i = 0; i < size; ++i) {
        matrix[i] = (ENode *) malloc(size * sizeof(ENode));
        if (!matrix[i])
            exit(ERROR_MALLOC_FAILED);
        memset(matrix[i], 0, size * sizeof(ENode));
    }
    return matrix;
}

// 初始化图
Graph initGraph() {
    Graph graph = (Graph) malloc(sizeof(Graph));
    // 初始化顶点数组
    graph->vertices = (T *) malloc(GRAPH_INIT_SIZE * sizeof(T));
    if (!graph->vertices)
        exit(ERROR_MALLOC_FAILED);
    memset(graph->vertices, 0, GRAPH_INIT_SIZE * sizeof(T));
    // 初始化边矩阵
    graph->edges = mallocAdjMatrix(GRAPH_INIT_SIZE);
    graph->edge_num = 0;
    graph->vertex_num = 0;
    graph->capacity = GRAPH_INIT_SIZE;
    return graph;
}

// 储存顶点数据到顶点数组中
int saveVertex(Graph graph, T data) {

    graph->vertices[graph->vertex_num] = data;
    int index = graph->vertex_num;
    graph->vertex_num++;
    return index;
}

// 根据顶点数据查找顶点，返回下标
int getVertex(Graph graph, T data) {
    int index = -1;
    for (int i = 0; i < graph->vertex_num; ++i) {
        T temp = graph->vertices[i];
        if (temp == data) {
            index = i;
            break;
        }
    }
    return index;
}

// 判断边是否存在
int isExistedEdge(Graph graph, int fromIndex, int toIndex) {
    return graph->edges[fromIndex][toIndex].adj;
}

// 添加边
void addEdge(Graph graph, T from, T to) {
    int fromIndex = getVertex(graph, from);
    // 顶点不存在时，储存顶点
    if (fromIndex == -1) {
        fromIndex = saveVertex(graph, from);
    }
    int toIndex = getVertex(graph, to);
    // 顶点不存在时，储存顶点
    if (toIndex == -1) {
        toIndex = saveVertex(graph, to);
    }
    if (TRUE == isExistedEdge(graph, fromIndex, toIndex)) {
        printf("\n---repeat edge---\n");
    } else {
        graph->edges[fromIndex][toIndex].adj = TRUE;
    }
}

// 移除边
void removeEdge(Graph graph, T from, T to) {
    int fromIndex = getVertex(graph, from);
    int toIndex = getVertex(graph, to);
    if (fromIndex == -1 || toIndex == -1) {
        printf("\n--- vertex dosen't exist ---\n");
        return;
    }
    if (FALSE == isExistedEdge(graph, fromIndex, toIndex)) {
        printf("\n--- edge dosen't exist ---\n");
    } else {
        graph->edges[fromIndex][toIndex].adj = FALSE;
    }
}

// DFS递归遍历
void DFSTraverse(Graph graph, int visit_arr[], int index) {
    visit_arr[index] = TRUE;
    printf("%d -> ", graph->vertices[index]);
    ENode *temp = graph->edges[index];
    for (int i = 0; i < graph->vertex_num; ++i) {
        if (temp->adj != FALSE && visit_arr[i] == FALSE) {
            DFSTraverse(graph, visit_arr, i);
        }
        temp++;
    }
}

// DFS 深度优先搜索
void DFS(Graph graph) {
    // 判断顶点是否已被遍历的辅助数组
    int visit_arr[graph->vertex_num];
    memset(visit_arr, FALSE, sizeof(visit_arr));
    printf("\n--- DFS ---\n");
    for (int i = 0; i < graph->vertex_num; i++) {
        if (visit_arr[i] == FALSE)
            DFSTraverse(graph, visit_arr, i);
    }
    printf("\n--- DONE ---\n");
}

// BFS遍历
void BFSTraverse(Graph graph, int visit_arr[], int first) {
    Queue queue = initQueueWithSize(graph->vertex_num);
    visit_arr[first] = TRUE;
    // 顶点入队
    enQueue(queue, first);
    printf("%d -> ", graph->vertices[first]);
    while (!isEmpty(queue)) {
        // 顶点出队，获取其邻接顶点
        int index = deQueue(queue);
        ENode *temp = graph->edges[index];
        // 打印未遍历的邻接顶点并入队
        for (int i = 0; i < graph->vertex_num; i++) {
            if (temp->adj != FALSE && visit_arr[i] == FALSE) {
                printf("%d -> ", graph->vertices[i]);
                visit_arr[i] = TRUE;
                enQueue(queue, i);
            }
            temp++;
        }
    }
}

// BFS 广度优先搜索
void BFS(Graph graph) {
    // 判断顶点是否已被遍历的辅助数组
    int visit_arr[graph->vertex_num];
    memset(visit_arr, FALSE, sizeof(visit_arr));
    printf("\n--- BFS ---\n");
    for (int i = 0; i < graph->vertex_num; i++) {
        if (visit_arr[i] == FALSE)
            BFSTraverse(graph, visit_arr, i);
    }
    printf("\n--- DONE ---\n");
}

// 打印图
void printGraph(Graph graph) {
    printf("\n------ PRINT GRAPH ------\n   ");
    for (int c = 0; c < graph->vertex_num; ++c) {
        printf("%d ", graph->vertices[c]);
    }
    printf("\n");
    for (int i = 0; i < graph->vertex_num; ++i) {
        ENode *rows = graph->edges[i];
        printf("%d: ", graph->vertices[i]);
        for (int j = 0; j < graph->vertex_num; ++j) {
            printf("%d ", (rows + j)->adj);
        }
        printf("\n");
    }
    printf("------ PRINT DONE ------\n");
}