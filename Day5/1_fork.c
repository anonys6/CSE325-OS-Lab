/* 
fork returns the pid of child to the parent process
and 0 to the child process
parent = pid of child
child = 0
any error = -1

getpid is used to get the running process id
same lib as fork, no arguments required

*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();

    printf("Current process PID is %d\n", pid);
    printf("Forking a child process...\n");

    pid_t child_pid = fork();
    
    if (child_pid == -1) {
        printf("Failed to fork a child process\n");
        return 1;
    } else if (child_pid == 0) {
        printf("Child process PID: %d, Parent process PID: %d\n", getpid(), getppid());
    } else {
        printf("Parent process PID: %d\n", getpid());
    }

    return 0;

}
