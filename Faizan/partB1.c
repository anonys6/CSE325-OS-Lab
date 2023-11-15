// For part B, we will implement the C program that uses the fork() and execve() system calls. However, please note that passing a sorted array to the child process through the command line arguments of the execve() system call is not possible because the command line arguments are strings. Instead, we can pass the original array to the child process and sort it in the child process.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int arr[] = {4, 2, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    char *args[n + 2];

    args[0] = "./child";
    for (int i = 0; i < n; i++) {
        args[i + 1] = malloc(10);
        sprintf(args[i + 1], "%d", arr[i]);
    }
    args[n + 1] = NULL;

    pid_t pid = fork();

    if (pid == 0) {
        execve(args[0], args, NULL);
    } else if (pid > 0) {
        wait(NULL);
    }

    for (int i = 1; i <= n; i++) {
        free(args[i]);
    }

    return 0;
}