#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child process\n");
        printf("Child process ID: %d\n", getpid());
        printf("Parent process ID: %d\n", getppid());
    } else {
        sleep(5);
        printf("Parent process\n");
        printf("Parent process ID: %d\n", getpid());
        printf("Child process ID: %d\n", pid);
    }

}