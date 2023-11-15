// Here is a solution for your problem statement.

// First, we will implement the C program for part A.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Selection sort
void sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {4, 2, 3, 1, 5};    // Original array
    int n = sizeof(arr) / sizeof(arr[0]);   // Size of the array

    pid_t pid = fork(); // Forking a child process

    if (pid == 0) {
        printf("Child process:\n");
        sort(arr, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else if (pid > 0) {
        wait(NULL); // Waiting for the child process to finish
        printf("Parent process:\n");
        sort(arr, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}