#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd, l, n, m;
	char buff[100];
	fd = open("Third.txt", O_RDONLY, 666);
    l = lseek(fd, -1, SEEK_END);
    printf("\n Raturn ")
	

	
	return 0;
}
