/*

Write a program to create a file with some lines of content and write "hello" into that file after 4 characteres from starting using system call.

*/

#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("filename.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    write(fd, "1234567890", 10);

    lseek(fd, 4, SEEK_SET);

    write(fd, "hello", 5);

    close(fd);
    return 0;
}