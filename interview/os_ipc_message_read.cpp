//
// Created by eagle on 2022/3/4.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "sys/shm.h"

const int SIZE = 4096;
const char *name = "os";

int main() {
    int key = ftok(name, 0);

    int id = shmget(key, SIZE, 0);
    char *p = (char *) shmat(id, NULL, 0);

    printf("read: %s", p);
    return 0;
}