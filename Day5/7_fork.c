#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t a;
    printf("Process PID: %d\n", getpid());
    a = fork();
    
    if (a == 0) {
        sleep(3);
        printf("Child process with PID: %d\n", getpid());
    } else if (a == -1) {
        printf("Faliure of fork\n");
    } else {
        // sleep(1);
        sleep(2);
        printf("Parent process with PID: %d\n", getpid());
        printf("%d\n", a);
        // exit(1);
    }

    return 0;
}