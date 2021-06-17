//
// Created by eagle on 2021/6/15.
//

#ifndef DATA_STRUCTURE_GRAPH_H
#define DATA_STRUCTURE_GRAPH_H

#include "stdio.h"
#include "stdlib.h"
#include "error_code.h"
#include "boolean.h"

typedef int T;
typedef struct Graph_T *Graph;

// 初始化图
Graph initGraph();

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
