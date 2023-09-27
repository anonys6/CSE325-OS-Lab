#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    printf("The process id (PID) is: %d\n", getpid());
    pid = fork();
    if (pid == 0) 
        printf("Child is printing: Hello\n");
    else
        printf("The parent process is printing: Hello\n");
    // printf("The parent process id (PID) is: %d\n", getppid());
    
    return 0;
}