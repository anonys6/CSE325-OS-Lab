// // Here is a solution for your problem statement.

// // First, we will implement the C program for part A.

// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>

// // Selection sort
// void sort(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[i] > arr[j]) {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

// int main() {
//     int arr[] = {4, 2, 3, 1, 5};    // Original array
//     int n = sizeof(arr) / sizeof(arr[0]);   // Size of the array

//     pid_t pid = fork(); // Forking a child process

//     if (pid == 0) {
//         printf("Child process:\n");
//         sort(arr, n);
//         for (int i = 0; i < n; i++) {
//             printf("%d ", arr[i]);
//         }
//         printf("\n");
//     } else if (pid > 0) {
//         wait(NULL); // Waiting for the child process to finish
//         printf("Parent process:\n");
//         sort(arr, n);
//         for (int i = 0; i < n; i++) {
//             printf("%d ", arr[i]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

// For part B, we will implement the C program that uses the fork() and execve() system calls. However, please note that passing a sorted array to the child process through the command line arguments of the execve() system call is not possible because the command line arguments are strings. Instead, we can pass the original array to the child process and sort it in the child process.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int arr[] = {4, 2, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    char *args[n + 2];

    args[0] = "./child";
    for (int i = 0; i < n; i++) {
        args[i + 1] = malloc(10);
        sprintf(args[i + 1], "%d", arr[i]);
    }
    args[n + 1] = NULL;

    pid_t pid = fork();

    if (pid == 0) {
        execve(args[0], args, NULL);
    } else if (pid > 0) {
        wait(NULL);
    }

    for (int i = 1; i <= n; i++) {
        free(args[i]);
    }

    return 0;
}


// // In the child process, we can sort the array and print it.



// #include <stdio.h>
// #include <stdlib.h>

// void sort(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[i] > arr[j]) {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

// int main(int argc, char *argv[]) {
//     int arr[argc - 1];
//     for (int i = 1; i < argc; i++) {
//         arr[i - 1] = atoi(argv[i]);
//     }

//     sort(arr, argc - 1);

//     for (int i = 0; i < argc - 1; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }


// // Please note that you need to compile the child process code and name the executable as child and place it in the same directory as the parent process code.