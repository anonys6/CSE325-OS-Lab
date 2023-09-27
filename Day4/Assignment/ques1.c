#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    char d_name[20];
    printf("Enter the name of the directory: ");
    scanf("%s", d_name);
    
    int dd = mkdir(d_name, 0777);
    
    if (dd == 0) {
        printf("Directory created successfully\n");
        chdir(d_name);
        int fd = open("Read1.txt", O_CREAT | O_RDWR, 0666);
        
        char buffer[1024];
        int bytesread = read(STDIN_FILENO, buffer, sizeof(buffer));
        write(fd, buffer, bytesread);
        
        int size = lseek(fd, 0, SEEK_END);
        printf("File size: %d\n", size);
        close(fd);
    } else {
        printf("Directory not created\n");
    }

    return 0;
}