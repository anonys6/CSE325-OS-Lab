#include <stdio.h>
#include <sys/stat.h>

int main() {
	int dd;
	dd = mkdir("Thursday", S_IRWXU | S_IRWXG);
	printf("Value of dd is %d \n", dd);
	
	return 0;
}
