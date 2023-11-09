#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int old_fd, new_fd;

    old_fd = open("7_input.txt", O_RDWR | O_CREAT);
    new_fd = dup(old_fd);

    printf("Old fd: %d\n", old_fd);
    printf("New fd: %d\n", new_fd);

    write(old_fd, "Writing using old fd\n", 22);
    write(new_fd, "Writing using new fd\n", 22);

    // dup2(old_fd, 1);
    // printf("Hello wolrd\n");

    return 0;
}