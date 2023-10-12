#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 

int main() {
    pid_t f1;

    f1 = fork();

    if (f1 == -1) {
        printf("Error\n");
    } else if (f1 == 0) {
        printf("---------------------------------------\n");
        printf("Child process with PID: %d, parent PID: %d\n", getpid(), getppid());
        pid_t f2 = fork();
        
        if (f2 == -1) {
            printf("Error\n");
        } else if (f2 == 0) {
            printf("---------------------------------------\n");
            printf("Child process with PID: %d, parent PID: %d\n", getpid(), getppid());
            pid_t f3 = fork();

            if (f3 == -1) {
                printf("Error\n");
            } else if (f3 == 0) {
                printf("---------------------------------------\n");
                printf("Child process with PID: %d, parent PID: %d\n", getpid(), getppid());
                pid_t f3 = fork(); 
                
            } else {
                exit(0);
                printf("---------------------------------------\n");
                printf("Parent process with PID: %d\n", getpid());
            }

        } else {
            exit(0);
            printf("---------------------------------------\n");
            printf("Parent process with PID: %d\n", getpid());
        }

    } else {
        printf("---------------------------------------\n");
        printf("Parent process with PID: %d\n", getpid());
    }

    return 0;
}