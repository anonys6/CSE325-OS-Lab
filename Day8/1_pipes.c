/*
Inter-process communication (IPC)
- pipes
    - named
    - unnamed
- shared memory
- memory queues
- remote procedure call (RPC)

pipes :-
half duplex
return 0 = success
return -1 = error

pipe() - creates a pipe
    - returns 0 on success
    - returns -1 on error

pipefd[0] - read end
pipefd[1] - write end

unnamed pipe - created using pipe() system call
    - parent and child process
    - parent writes to pipe
    - child reads from pipe
    - pipe is half duplex
    - pipe is destroyed when parent and child process terminates

named pipe - created using mkfifo() system call
    - parent and child process
    - parent writes to pipe
    - child reads from pipe
    - pipe is half duplex
    - pipe is not destroyed when parent and child process terminates
    - pipe is destroyed when all the processes closes the pipe

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int fd[2], nb;
    pid_t cpid;
    char inf[] = " Welcome to LPU\n";
    char rbuff[50];

    pipe(fd);

    if((cpid= fork()) == -1) {
        printf("Parent failed to create child process\n");
        exit(1);
    }

    if (cpid == 0) {
        close (fd[0]);
        write (fd[1], inf, strlen(inf) + 1);
        printf("The information written in the pipe by child is: %s\n", inf);
        exit(0);
    } else {
        close(fd[1]);
        nb = read(fd[0], rbuff, sizeof(rbuff));
        printf("The information read from the pipe by parent is: %s\n", rbuff);
    }

    return 0;
}
