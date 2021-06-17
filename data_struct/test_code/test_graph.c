//
// Created by eagle on 2021/6/16.
//

#include "../graph/graph.h"

/**
     1───► 2◄──────3
     │     │       │
     ▼     ▼       ▼
     4────►5 ─────►6
     │     │       │
     ▼     ▼       ▼
     7     8─────► 9
     |             ▲
     │             │
     └────►10 ─────┘
 */
int main() {
    Graph graph = initGraph();
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 8);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 9);
    addEdge(graph, 7, 10);
    addEdge(graph, 8, 9);
    addEdge(graph, 10, 9);
    printGraph(graph);
    DFS(graph);
    BFS(graph);
//    removeEdge(graph, 2, 1);
//    removeEdge(graph, 2, 1);
//    removeEdge(graph, 2, 4);
//    printGraph(graph);
    return 0;
}