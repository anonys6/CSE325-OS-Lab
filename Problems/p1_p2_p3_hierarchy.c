/*

Write a program to create the following hierarchy and verify the relationship using getpid() and getppid()

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t p2 = fork();

    if (p2 == 0) {
        pid_t p3 = fork();
        if (p3 == 0) {
            printf("In P3: pid = %d, parent pid = %d\n", getpid(), getppid());
        } else {
            printf("In P2: pid = %d, parent pid = %d, child pid = %d\n", getpid(), getppid(), p3);
        }
    } else {
        printf("In P1: pid = %d, child pid = %d\n", getpid(), p2);
    }

    return 0;
}