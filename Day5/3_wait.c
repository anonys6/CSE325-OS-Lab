#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork(); // Creating child process

    if (pid == -1) {
        printf("Error: Failed to fork process\n");
        exit(1);
    } else if (pid == 0) {
        printf("Child process is running\n");
        sleep(2);
        printf("Child process exiting\n");
        exit(0);
    } else {
        printf("Parent process waiting for child process...\n");
        wait(&status); // wait for child to terminate
        printf("Child process exited with status %d\n", status);
    }

    return 0;
}