#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd, fd1, n, m;
	char buff[100];
	
	fd = open("Day3.txt", O_RDONLY, 666);
	fd1 = open("CopyFile.txt", O_CREAT | O_WRONLY, 666);
	printf("Value of fd is %d and fd1 is %d \n", fd, fd1);
	n = read(fd, buff, 20);
	printf("Read count is %d \n", n);
	m = write(fd1, buff, n);
	printf("Write count is %d \n", m);
	close(fd);

	
	return 0;
}
