//
// Created by eagle on 2021/6/16.
//

#include "graph.h"

#define GRAPH_INIT_SIZE 10
#define GRAPH_INCREMENT 10

// 顶点节点
typedef struct VertexNode {
    T data; // 顶点的数据域
    ENode *firstEdge; // 指向邻接点的指针
} VNode;

// 边节点定义
struct EdgeNode {
    int vertexIndex; // 顶点下标
    struct EdgeNode *nextEdge; // 指向下一个邻接点的指针
    W weight; // 权重
};

// 图定义
struct Graph_T {
    VNode *vertices; // 图中顶点的数组
    int vertex_num; // 记录图中顶点数
    int edge_num; // 记录图中边数
    int capacity; // 容量
};

// 初始化图
Graph initGraph() {
    Graph graph = (Graph) malloc(sizeof(Graph));
    graph->vertices = (VNode *) malloc(GRAPH_INIT_SIZE * sizeof(VNode));
    memset(graph->vertices, 0, GRAPH_INIT_SIZE * sizeof(VNode));
    graph->edge_num = 0;
    graph->vertex_num = 0;
    graph->capacity = GRAPH_INIT_SIZE;
    return graph;
}

// 创建顶点
VNode *createVertex(T data) {
    VNode *vertex = (VNode *) malloc(sizeof(VNode));
    vertex->data = data;
    vertex->firstEdge = NULL;
    return vertex;
}

// 储存顶点数据到顶点数组中
int saveVertex(Graph graph, T data) {
    // 扩容
    if (graph->vertex_num >= graph->capacity) {
        graph->vertices = (VNode *) realloc(graph->vertices, GRAPH_INCREMENT * sizeof(VNode));
        if (!graph->vertices) {
            printf("---malloc memory failed---\n");
            exit(ERROR_MALLOC_FAILED);
        }
        graph->capacity += GRAPH_INCREMENT;
    }
    graph->vertices[graph->vertex_num] = *createVertex(data);
    int index = graph->vertex_num;
    graph->vertex_num++;
    return index;
}

// 根据顶点数据查找顶点，返回下标
int getVertex(Graph graph, T data) {
    int index = -1;
    for (int i = 0; i < graph->vertex_num; ++i) {
        T temp = graph->vertices[i].data;
        if (temp == data) {
            index = i;
            break;
        }
    }
    return index;
}

// 判断边是否存在
int isExistedEdge(Graph graph, int fromIndex, int toIndex) {
    VNode *fromVertex = &graph->vertices[fromIndex];
    ENode *edge = fromVertex->firstEdge;
    while (edge != NULL) {
        if (edge->vertexIndex == toIndex) {
            return TRUE;
        }
        edge = edge->nextEdge;
    }
    return FALSE;
}

// 创建边节点
ENode *createENode(int vIndex, W weight) {
    ENode *edge = (ENode *) malloc(sizeof(ENode));
    edge->vertexIndex = vIndex;
    edge->nextEdge = NULL;
    edge->weight = weight;
    return edge;
}

// 添加边
void addEdge(Graph graph, T from, T to, W weight) {
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
    VNode *fromVertex = &graph->vertices[fromIndex];
    if (TRUE == isExistedEdge(graph, fromIndex, toIndex)) {
        printf("\n---repeat edge---\n");
        return;
    }
    // 初始化边节点
    ENode *edge = createENode(toIndex, weight);
    if (fromVertex->firstEdge == NULL) {
        fromVertex->firstEdge = edge;
        graph->edge_num++;
    } else {
        ENode *temp = fromVertex->firstEdge;
        while (temp) {
            if (temp->nextEdge == NULL)
                break;
            temp = temp->nextEdge;
        }
        temp->nextEdge = edge;
        graph->edge_num++;
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
    VNode *fromVertex = &graph->vertices[fromIndex];
    if (FALSE == isExistedEdge(graph, fromIndex, toIndex)) {
        printf("\n--- edge dosen't exist ---\n");
        return;
    }
    ENode *temp = fromVertex->firstEdge;
    if (temp->vertexIndex == toIndex) {
        fromVertex->firstEdge = fromVertex->firstEdge->nextEdge;
        free(temp);
        graph->edge_num--;
    } else {
        while (temp) {
            if (temp->nextEdge->vertexIndex == toIndex) {
                ENode *freeNode = temp->nextEdge;
                temp->nextEdge = temp->nextEdge->nextEdge;
                free(freeNode);
                graph->edge_num--;
                break;
            }
            temp = temp->nextEdge;
        }
    }
}

// DFS递归遍历
void DFSTraverse(Graph graph, int visit_arr[], int index) {
    visit_arr[index] = TRUE;
    printf("%d -> ", graph->vertices[index].data);
    ENode *edge = graph->vertices[index].firstEdge;
    while (edge != NULL) {
        if (visit_arr[edge->vertexIndex] == FALSE)
            DFSTraverse(graph, visit_arr, edge->vertexIndex);
        edge = edge->nextEdge;
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
    Queue queue = MyQueue.initWithSize(graph->vertex_num);
    visit_arr[first] = TRUE;
    // 顶点入队
    MyQueue.insert(queue, first);
    printf("%d -> ", graph->vertices[first].data);
    while (!MyQueue.isEmpty(queue)) {
        // 顶点出队，获取其邻接顶点
        int index = MyQueue.remove(queue);
        ENode *temp = graph->vertices[index].firstEdge;
        // 打印未遍历的邻接顶点并入队
        while (temp) {
            if (visit_arr[temp->vertexIndex] != TRUE) {
                printf("%d -> ", graph->vertices[temp->vertexIndex].data);
                visit_arr[temp->vertexIndex] = TRUE;
                MyQueue.insert(queue, temp->vertexIndex);
            }
            temp = temp->nextEdge;
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
    printf("\n--- PRINT GRAPH ---\n");
    for (int i = 0; i < graph->vertex_num; ++i) {
        printf("vertex: %d ", graph->vertices[i].data);
        ENode *edge = graph->vertices[i].firstEdge;
        while (edge) {
            printf(" -> %d", graph->vertices[edge->vertexIndex].data);
            edge = edge->nextEdge;
        }
        printf("\n");
    }
    printf("\n--- PRINT DONE ---\n");
}