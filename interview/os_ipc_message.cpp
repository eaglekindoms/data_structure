//
// Created by eagle on 2022/3/4.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "fcntl.h"
#include "sys/shm.h"
#include "sys/stat.h"
#include "unistd.h"

const int SIZE = 4096;
const char *name = "os";
const char *message0 = "hello";
const char *message1 = "world";

int main() {
    int shm_fd;
    char *ptr;
    int key = ftok(name, 0);
    shm_fd = shmget(key, SIZE, IPC_CREAT | 0666);
    if (shm_fd < 0) perror("shmget"), exit(-1);
    ptr = (char *) shmat(shm_fd, NULL, 0);
    printf("write message\n");
    sprintf(ptr, "%s", message0);
    ptr += strlen(message0);
    sleep(2);
    sprintf(ptr, "%s", message1);
    printf("write done\n");
    sleep(6);
    return 0;
}
