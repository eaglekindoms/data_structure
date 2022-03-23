//
// Created by eagle on 2022/3/23.
//


#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    char *kind[] = {"acute", "right", "obtuse", "invalid"};

    int n;
    scanf("%d", &n);
    int tri[6];
    int *result = (int *) malloc(n * sizeof(int));

    int i;
    for (i = 0; i < n; ++i) {
        scanf("%d %d %d %d %d %d",
              &tri[0], &tri[1],
              &tri[2], &tri[3],
              &tri[4], &tri[5]);

        int ab = (tri[2] - tri[0]) * (tri[2] - tri[0]) + (tri[3] - tri[1]) * (tri[3] - tri[1]);
        int bc = (tri[4] - tri[2]) * (tri[4] - tri[2]) + (tri[5] - tri[3]) * (tri[5] - tri[3]);
        int ac = (tri[4] - tri[0]) * (tri[4] - tri[0]) + (tri[5] - tri[1]) * (tri[5] - tri[1]);

        if (ab > bc) swap(&ab, &bc);
        if (bc > ac) swap(&bc, &ac);

        if ((ab + bc) == ac) {
            result[i] = 1;
        } else if ((ab + bc) > ac) {
            result[i] = 0;
        } else if ((ab + bc) < ac) {
            // 点重合或与y轴平行
            if ((tri[0] == tri[2] && tri[1] == tri[3])
                || (tri[0] == tri[4] && tri[1] == tri[5])
                || (tri[2] == tri[4] && tri[3] == tri[5])
                || (tri[0]==tri[2]&&tri[2]==tri[4])) {
                result[i] = 3;
                continue;
            }
            // 共线
            if(((abs(tri[2]-tri[0])/ abs(tri[4]-tri[0]))==
            (abs(tri[3]-tri[1])/ abs(tri[5]-tri[0])))){
                result[i] = 3;
                continue;
            }

            result[i] = 2;
        }
    }

    for (i = 0; i < n; i++) {
        printf("%s\n", kind[result[i]]);
    }

    return 0;
}