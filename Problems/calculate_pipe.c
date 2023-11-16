/*

Write a program to calculate addition of 2 numbers in parent process and display result in child process

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int fd[2];
    pid_t pid;
    int sum;

    pipe(fd);
    pid = fork();

    if (pid > 0) {
        close(fd[0]);
        int a = 5, b = 10;
        sum = a + b;
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
    } else if (pid == 0) {
        close(fd[1]);
        read(fd[0], &sum, sizeof(sum));
        printf("Sum in child process: %d\n", sum);
        close(fd[0]);
    }

    return 0;
}