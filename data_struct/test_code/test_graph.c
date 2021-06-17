//
// Created by eagle on 2021/6/16.
//

#include "../graph/graph.h"

int main() {
    Graph graph = initGraph();
    addEdge(graph, 2, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 3, 2);
    addEdge(graph, 2, 6);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 11);
    printGraph(graph);
    removeEdge(graph, 2, 1);
    removeEdge(graph, 2, 1);
    removeEdge(graph, 2, 4);
    printGraph(graph);
    return 0;
}