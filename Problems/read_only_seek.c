/*

Write a program using system calls which will read from 3rd character to 10th character from a file open only in read only mode

*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("filename.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    lseek(fd, 2, SEEK_SET);

    char buffer[9] = {0};
    ssize_t numRead = read(fd, buffer, 8);
    if (numRead == -1) {
        perror("Failed to read");
        close(fd);
        return 1;
    }

    printf("Characters 3 to 10: %s\n", buffer);

    close(fd);
    return 0;
}