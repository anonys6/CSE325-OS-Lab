#include <stdio.h>
#include <unistd.h>

int main() {
	int n;
	char buff[100];
	n =  read(0, buff, 10);
	printf("Read count is %d \n", n);
	int m;
	m = write(1, buff, n);
	printf("Write count is %d \n", m);
	
	return 0;
}
