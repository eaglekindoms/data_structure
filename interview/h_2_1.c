//
// Created by eagle on 2022/3/26.
//

#include "stdio.h"
#include "stdlib.h"

int year(int n);

int main() {
    int n, i;
    scanf("%d", &n);
    int x1, x2;
    int *result = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; ++i) {
        scanf("%d %d", &x1, &x2);
        result[i] = year(x2) - year(x1 - 1);
    }
    for (i = 0; i < n; i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}

int year(int n) {
    return n / 4 - n / 100 + n / 400;
}