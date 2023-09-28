/*
program in execution is known as process
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    fork();
    fork();
    printf("Hello\n");
    printf("PID of this process: %d\n", getpid());
    // printf("Parent PID of this process: %d\n", getppid());

    return 0;
}