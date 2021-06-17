//
// Created by eagle on 2021/6/16.
//

#include "graph.h"
#include "memory.h"

#define GRAPH_INIT_SIZE 100
#define GRAPH_INCREMENT 10

typedef int W;    // 边权值

// 边节点
typedef struct EdgeNode {
    int vertexIndex; // 顶点下标
    struct EdgeNode *nextEdge;// 指向下一个邻接点的指针
    W *weight;// 权重
} *ENode;

// 顶点节点
typedef struct VertexNode {
    T data;// 顶点的数据域
    ENode firstEdge;// 指向邻接点的指针
} *VNode;

struct Graph_T {
    VNode *vertices;// 图中顶点的数组
    int vertex_num;// 记录图中顶点数
    int edge_num;// 记录图中边数
    int capacity;// 容量
};

// 初始化图
Graph initGraph() {
    Graph graph = (Graph) malloc(sizeof(Graph));
    graph->vertices = (VNode) malloc(GRAPH_INIT_SIZE * sizeof(VNode));
    memset(graph->vertices, NULL, GRAPH_INIT_SIZE * sizeof(VNode));
    graph->edge_num = 0;
    graph->vertex_num = 0;
    graph->capacity = GRAPH_INIT_SIZE;
    return graph;
}

// 创建顶点
VNode createVertex(T data) {
    VNode vertex = (VNode) malloc(sizeof(VNode));
    vertex->data = data;
    vertex->firstEdge = NULL;
}

// 储存顶点数据到顶点数组中
int saveVertex(Graph graph, T data) {
    // 扩容
    if (graph->vertex_num >= graph->capacity) {
        graph->vertices = (T *) realloc(graph->vertices, GRAPH_INCREMENT * sizeof(VNode));
        if (!graph->vertices) {
            printf("---malloc memory failed---\n");
            exit(ERROR_MALLOC_FAILED);
        }
        graph->capacity += GRAPH_INCREMENT;
    }
    graph->vertices[graph->vertex_num] = createVertex(data);
    int index = graph->vertex_num;
    graph->vertex_num++;
    return index;
}

// 根据顶点数据查找顶点，返回下标
int getVertex(Graph graph, T data) {
    int index = -1;
    for (int i = 0; i < graph->vertex_num; ++i) {
        T temp = graph->vertices[i]->data;
        if (temp == data) {
            index = i;
            break;
        }
    }
    return index;
}

// 判断边是否存在
int isExistedEdge(VNode vertex, int toIndex) {
    ENode edge = vertex->firstEdge;
    while (edge != NULL) {
        if (edge->vertexIndex == toIndex) {
            return TRUE;
        }
        edge = edge->nextEdge;
    }
    return FALSE;
}

// 创建边节点
ENode createENode(int vIndex, W weight) {
    ENode edge = (ENode) malloc(sizeof(ENode));
    edge->vertexIndex = vIndex;
    edge->nextEdge = NULL;
    edge->weight = weight;
    return edge;
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
    VNode fromVertex = graph->vertices[fromIndex];
    if (TRUE == isExistedEdge(fromVertex, toIndex)) {
        printf("\n---repeat edge---\n");
        return;
    }
    // 初始化边节点
    ENode edge = createENode(toIndex, NULL);
    if (fromVertex->firstEdge == NULL) {
        fromVertex->firstEdge = edge;
        graph->edge_num++;
    } else {
        ENode temp = fromVertex->firstEdge;
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
    VNode fromVertex = graph->vertices[fromIndex];
    if (FALSE == isExistedEdge(fromVertex, toIndex)) {
        printf("\n--- edge dosen't exist ---\n");
        return;
    }
    ENode temp = fromVertex->firstEdge;
    if (temp->vertexIndex == toIndex) {
        fromVertex->firstEdge = fromVertex->firstEdge->nextEdge;
        free(temp);
        graph->edge_num--;
    } else {
        while (temp) {
            if (temp->nextEdge->vertexIndex == toIndex) {
                ENode freeNode = temp->nextEdge;
                temp->nextEdge = temp->nextEdge->nextEdge;
                free(freeNode);
                graph->edge_num--;
                break;
            }
            temp = temp->nextEdge;
        }
    }
}

// DFS 深度优先搜索
void DFS(Graph graph) {

}

// BFS 广度优先搜索
void BFS(Graph graph) {

}

// 打印图
void printGraph(Graph graph) {
    printf("\n--- PRINT GRAPH ---\n");
    for (int i = 0; i < graph->vertex_num; ++i) {
        printf("vertex: %d ", graph->vertices[i]->data);
        ENode edge = graph->vertices[i]->firstEdge;
        while (edge) {
            printf(" -> %d", graph->vertices[edge->vertexIndex]->data);
            edge = edge->nextEdge;
        }
        printf("\n");
    }
    printf("\n--- PRINT DONE ---\n");
}