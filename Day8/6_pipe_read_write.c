// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>

// int main() {
//     int pipefd[2]; // [0] for read and [1] for write
//     char buffer[25];
//     pid_t pid;

//     if (pipe(pipefd) == -1) {
//         printf("Error in creating pipe\n");
//         return 1;
//     }

//     pid = fork();

//     if (pid < 0) {
//         printf("Failed to fork\n");
//         return 1;
//     } else if (pid > 0) {
//         // parent process, in this we are performing write operation so closing read end first
//         close (pipefd[0]);

//         printf("Parent process writing to pipe\n");
//         write(pipefd[1], "Hello child process!", 25);   // write end, message, buffer size

//         close (pipefd[1]);  // also closing write end of the pipe
//     } else {
//         // child process, in the we are performing read operation so closing write end
//         close(pipefd[1]);

//         printf("Child process reading from pipe\n");
//         read(pipefd[0], buffer, 25);                    // reading and storing in buffer
//         printf("Printing from buffer: %s\n", buffer);

//         close(pipefd[0]);
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[25];

    if (pipe(pipefd) == -1) {
        printf("Failed to create pipe\n");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid > 0) {
        // Parent process
        close (pipefd[0]);

        printf("Writing from parent process\n");
        write(pipefd[1], "Hello, child process!", 25);

        close (pipefd[1]);
    } else {
        // Child process
        close (pipefd[1]);

        printf("Reading from pipe using child process\n");
        read(pipefd[0], buffer, 25);
        printf("From buffer: %s\n", buffer);

        close (pipefd[1]);
    }

    return 0;
}