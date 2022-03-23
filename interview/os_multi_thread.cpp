//
// Created by eagle on 2022/3/17.
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int sum;

void *runner(void *param);

int main(int argc, char *argv[]) {
    pthread_t tid;
    pthread_attr_t attr;
    if (argc != 2) {
        fprintf(stderr, "usage: a.out <integer value>\n");
        return -1;
    }
    if (atoi(argv[1]) < 0) {
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
        return -1;
    }
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    pthread_join(tid, NULL);
    printf("sum = %d\n", sum);
    {
#pragma omp parallel num_threads(5)
        {
            printf("a parallel region.\n");
        }
    }
}

void *runner(void *param) {
    int i;
    int upper = atoi(param);
    sum = 0;
    for (i = 1; i < upper; ++i) {
        sum += i;
    }
    pthread_exit(0);
}
