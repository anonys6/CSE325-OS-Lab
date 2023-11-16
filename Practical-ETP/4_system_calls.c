// /*
// open()
// returns a file descriptor
// -1 on error
// int open(const char *pathname, int flags);
// int open(const char *pathname, int flags, mode_t mode);
// flags:
// O_RDONLY (read only)
// O_WRONLY (write only)
// O_RDWR (read and write)
// O_CREAT (create file if it doesn't exist)

// mode:
// S_IRWXU (user)
// S_IRWXG (group)
// S_IRWXO (others)

// returns 0 on success
// */

// #include <stdio.h>
// #include <fcntl.h>

// int main() {
//     int n, m;

//     n = open("new_file", O_RDONLY);
//     printf("File descriptor is %d \n", n);

//     m = open("new_file1", O_CREAT | O_WRONLY, 0777);
//     printf("File descriptor is %d \n", m);

//     return 0;
// }

// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>

// int main()
// {
//     int n, m;
//     char buffer[100];

//     n = write(1, "Hello World", 11);
//     printf("Number of bytes written: %d \n", n);
    
//     m = read(0, buffer, 12);
//     printf("Number of bytes read: %d \n", m);
//     return 0;
// }

// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>

// int main() {
//     int n, m;
//     char buffer[50];

//     n = write(1, "Hello World", 11); // 1 is the file descriptor for stdout 
//     printf("Number of bytes written: %d \n", n);

//     m = read(0, buffer, 12); // 0 is the file descriptor for stdin
//     printf("Number of bytes read: %d \n", m);

//     return 0;
// }

/*
write(1, , ) is equivalent to printf()
read(0, , ) is equivalent to scanf()

1 to write on screen
and 0 to read from keyboard

lseek()
int lseek(int fd, off_t offset, int whence);
SEEK_SET (start of file)
SEEK_CUR (current position of file pointer)
SEEK_END (end of file)
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd, f1;
    char buffer[50];

    fd = open("new_file1", O_RDONLY);
    
    f1 = lseek(fd, 0, SEEK_SET);

    read(fd, buffer, 5);
    write(1, buffer, 5);

    close(fd);

    return 0;
    
}