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
    [1]──12─►[2]◄──32──[3]              prim: 给定一顶点开始。例：从[1]开始
     │        │         │               1. [1]-->[2], [1]-->[4], [2]-->[5] w=12+14+25
    14       25        36               2. [4]-->[7], [5]-->[6], [5]-->[8] w+=47+56+58
     │        │         │               3. [6]-->[9], [7]-->[10]           w+=69+70
     ▼        ▼         ▼               4. [3]-->[2]                       w+=32
    [4]──45─►[5] ──56─►[6]              kruskal: 从最短边开始(设为无向图）
     │        │         │               1. [1]--[2], [1]--[4], [10]--[9] w=12+14+19
    47       58        69               2. [2]--[5], [3]--[2], [3]--[6]  w+=25+32+36
     │        │         │               3. [4]--[7], [5]--[8], [6]--[9]  w+=47+58+69
     ▼        ▼         ▼
    [7]      [8]───89─►[9]
     │                  ▲
    70                  │
     └────►[10] ────19──┘
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
    floyd_path(graph);
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