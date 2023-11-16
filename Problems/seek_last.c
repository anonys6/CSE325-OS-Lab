/*

Write a program to open a file in read only mode and read the last 5 characters from the file. print the same on terminal

*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("seek_last.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    off_t offset = lseek(fd, -5, SEEK_END);
    if (offset == -1) {
        perror("Failed to seek");
        close(fd);
        return 1;
    }

    char buffer[6] = {0};
    ssize_t numRead = read(fd, buffer, 5);
    if (numRead == -1) {
        perror("Failed to read");
        close(fd);
        return 1;
    }

    write(1, "Last 5 characters: ", 19);
    write(1, buffer, 5);
    write(1, "\n", 1);

    close(fd);
    return 0;
}