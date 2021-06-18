//
// Created by eagle on 2021/6/16.
//

#include "../graph/graph.h"

int testGraph();

void testArray();

int main() {
    testGraph();
//    testArray();
    return 0;
}

/**
     1───► 2◄──────3
     │     │       │
     ▼     ▼       ▼
     4────►5 ─────►6
     │     │       │
     ▼     ▼       ▼
     7     8─────► 9
     │             ▲
     │             │
     └────►10 ─────┘
 */
int testGraph() {
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
    removeEdge(graph, 2, 1);
    removeEdge(graph, 2, 5);
    removeEdge(graph, 3, 2);
    printGraph(graph);
    return 0;
}

void testArray() {
    int size = 10;
    int arr1[size];
    memset(arr1, 0, sizeof(arr1));
    for (int i = 0; i < size; ++i) {
        printf("%d ", *(arr1 + 1));
    }
    printf("\n");
    int arr2[size];
    memset(arr1, 0, size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        printf("%d ", *(arr2 + 1));
    }
    printf("\n");
    int *arr3 = (int *) malloc(size * sizeof(int));
    memset(arr3, 0, 10 * sizeof(int));
    for (int i = 0; i < size; ++i) {
        printf("%d ", *(arr3 + 1));
    }
    printf("\n");
    int *arr4 = (int *) malloc(size * sizeof(int));
    memset(arr1, 0, sizeof(arr4));
    for (int i = 0; i < size; ++i) {
        printf("%d ", *(arr4 + 1));
    }
}