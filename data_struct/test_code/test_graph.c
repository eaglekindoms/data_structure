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
    int arr[13][3] = {1, 2, 12, 1, 4, 14, 2, 5, 25,
                      3, 2, 32, 3, 6, 36, 4, 5, 45,
                      4, 7, 47, 5, 8, 58, 5, 6, 56,
                      6, 9, 69, 7, 10, 70, 8, 9, 89, 10, 9, 19};
    for (int i = 0; i < 13; ++i) {
        addEdge(graph, arr[i][0], arr[i][1], arr[i][2]);
    }
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
    int arr1[10];
    memset(arr1, 0, sizeof(arr1));
    for (int i = 0; i < size; ++i) {
        printf("%d ", *(arr1 + 1));
    }
    printf("\n");
    int arr2[10];
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