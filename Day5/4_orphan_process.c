/*
orphan process: parent terminated, child still executing

*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid > 0) {
        // Parent process exits immediately
        printf("Parent process with PID: %d is exiting\n", getpid());
        exit(0);
    } else if (child_pid == 0) {
        // Child process continues exucution
        printf("Child process with PID: %d and PPID: %d is running", getpid(), getppid());
        sleep(10);
        printf("Child process is done\n");
    } else {
        // Error occurred while forking
        printf("Error occurred while forking\n");
    }


}