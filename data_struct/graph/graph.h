//
// Created by eagle on 2021/6/15.
//

#ifndef DATA_STRUCTURE_GRAPH_H
#define DATA_STRUCTURE_GRAPH_H

#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "../queue/queue.h"
#include "error_code.h"
#include "boolean.h"

typedef int T;
typedef int W;    // 边权值

// 边节点声明
typedef struct EdgeNode ENode;

// 图声明
typedef struct Graph_T *Graph;

// 初始化图
Graph initGraph();

// 储存顶点数据到顶点数组中
int saveVertex(Graph graph, T data);

// 根据顶点数据查找顶点，返回下标
int getVertex(Graph graph, T data);

// 判断边是否存在
int isExistedEdge(Graph graph, int fromIndex, int toIndex);

// 添加边
void addEdge(Graph graph, T from, T to);

// 移除边
void removeEdge(Graph graph, T from, T to);

// DFS 深度优先搜索
void DFS(Graph graph);

// BFS 广度优先搜索
void BFS(Graph graph);

// 打印图
void printGraph(Graph graph);

#endif //DATA_STRUCTURE_GRAPH_H
