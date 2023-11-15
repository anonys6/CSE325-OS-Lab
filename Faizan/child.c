// In the child process, we can sort the array and print it.

#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[]) {
    int arr[argc - 1];
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    sort(arr, argc - 1);

    for (int i = 0; i < argc - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


// Please note that you need to compile the child process code and name the executable as child and place it in the same directory as the parent process code.