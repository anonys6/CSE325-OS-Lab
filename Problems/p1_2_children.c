/*

Write a program to create following hierarchy and verify the relationship between processes where process P1 had 2 children P2 and P3

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t p2 = fork();

    if (p2 == 0) {
        printf("In P2: pid = %d, parent pid = %d\n", getpid(), getppid());
    } else {
        pid_t p3 = fork();
        if (p3 == 0) {
            printf("In P3: pid = %d, parent pid = %d\n", getpid(), getppid());
        } else {
            printf("In P1: pid = %d, child1 pid = %d, child2 pid = %d\n", getpid(), p2, p3);
        }
    }

    return 0;
}