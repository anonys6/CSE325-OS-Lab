/*

Write a program to write into a pipe using popen() and pclose() functions

*/

#include <stdio.h>

/**
 * This program demonstrates how to use popen() and pclose() functions to open a pipe to a command
 * and write data to it. In this example, the "sort" command is used to sort the input data.
 */
int main() {
    FILE* pipe = popen("sort", "w"); // open a pipe to the "sort" command in write mode
    if (pipe == NULL) {
        perror("Failed to open pipe"); // print an error message if the pipe could not be opened
        return 1;
    }

    fprintf(pipe, "orange\napple\nbanana\n"); // write data to the pipe
    pclose(pipe); // close the pipe

    return 0;
}