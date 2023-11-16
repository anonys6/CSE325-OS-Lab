/*

Write a program to create one parent process and one child process also display id of both processes

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("In child: pid = %d, parent pid = %d\n", getpid(), getppid());
    } else {
        printf("In parent: pid = %d, child pid = %d\n", getpid(), pid);
    }

    return 0;
}