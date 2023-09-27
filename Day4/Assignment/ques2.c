#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    char d_name[5] = "XYZ";
    int dd = mkdir(d_name, 0777);
    
    if (dd == 0) {
        printf("Directory created successfully\n");
        chdir(d_name);
        int fd1 = open("Read1.txt", O_RDONLY);
        int fd2 = open("Read2.txt", O_CREAT | O_RDWR, 0666);
        
        int size = lseek(fd1, 0, SEEK_END);
        lseek(fd1, -size/3, SEEK_END);
        
        char buffer[1024];
        int bytesread;
        
        while ((bytesread = read(fd1, buffer, sizeof(buffer))) > 0) {
            write(fd2, buffer, bytesread);
        }
        
        lseek(fd2, 0, SEEK_SET);
        
        while ((bytesread = read(fd2, buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, bytesread);
        }
        
        close(fd1);
        close(fd2);
    } else {
        printf("Directory not created\n");
    }

    return 0;
}
