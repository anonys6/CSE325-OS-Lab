#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if(pid < 0) {
        printf("Fork failed");
        return 1;
    } else if (pid == 0) {
        sleep(2);
        printf("Child process\n");
        printf("Child process ID: %d\n", getpid());
        printf("Parent process ID: %d\n", getppid());
    } else {
        // wait(NULL);
        printf("Parent process\n");
        printf("Parent process ID: %d\n", getpid());
        printf("Child process ID: %d\n", pid);
    }
}