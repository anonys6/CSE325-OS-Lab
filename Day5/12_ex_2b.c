#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>

int main() {
    pid_t p1, p2, p3, p4, p5;

    p1 = fork();

    if (p1 < 0) {
        printf("fork failed\n");
        return 1;
    } else if (p1 == 0) {
        printf("This is P1 with PID: %d and parent PID: %d\n", getpid(), getppid());
        
        p2 = fork();
        if (p2 < 0) {
            printf("fork failed\n");
            return 1;
        } else if (p2 == 0) {
            printf("This is P2 with PID: %d and parent PID: %d\n", getpid(), getppid());
            
            p3 = fork();
            if (p3 < 0) {
                printf("fork failed\n");
                return 1;
            } else if (p3 == 0) {
                printf("This is P3 with PID: %d and parent PID: %d\n", getpid(), getppid());
                sleep(10); // Sleep to allow P2 to exit and make P3 orphan
            }
            
            exit(0);
        }
        
        p4 = fork();
        if (p4 < 0) {
            printf("fork failed\n");
            return 1;
        } else if (p4 == 0) {
            printf("This is P4 with PID: %d and parent PID: %d\n", getpid(), getppid());
            
            p5 = fork();
            if (p5 < 0) {
                printf("fork failed\n");
                return 1;
            } else if (p5 == 0) {
                printf("This is P5 with PID: %d and parent PID: %d\n", getpid(), getppid());
                exit(0); // Exit immediately to become a zombie as P4 will not wait
            }
            
            sleep(10); // Sleep to allow P5 to exit and become a zombie before P4 exits
        }
        
        exit(0);
    }

    while(wait(NULL) > 0);

    return 0;
}
