//
// Created by eagle on 2022/3/2.
//
#include <sys/wait.h>
#include "sys/types.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"

#define  BUFFER_SIZE 12
#define  READ 0
#define  WRITE 1

int main() {
    char  write_msg[BUFFER_SIZE]="hello,world";
    char  read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;
    if(pipe(fd)==-1) return -1;
    pid = fork();
    printf("pid: %d\n", pid);
    if (pid < 0) {
        printf("create pro failed\n");
    } else if (pid > 0) {
        close(fd[READ]);
        write(fd[WRITE],write_msg,strlen(write_msg)+1);
        close(fd[WRITE]);
//        wait(NULL);
//        printf("Child completed");
    } else{
//        execlp("/bin/ls","ls",NULL);
        close(fd[WRITE]);
        read(fd[READ],read_msg,BUFFER_SIZE);
        printf("read: %s",read_msg);
        close(fd[READ]);
    }
    sleep(2);
    return 0;
}