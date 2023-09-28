#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    pid = fork();

    if (pid == -1) {
        printf("Error\n");
        exit(1);
    } else if (pid == 0) {
        printf("Child process is running\n");
        sleep(1);
        printf("Child process exiting\n");
        exit(0);
    } else {
        printf("Parent process waiting for child process\n");
        sleep(3);
        printf("Parent process exiting after child terminated\n");
        exit(1);
    }

    return 0;
}