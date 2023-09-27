#include <stdio.h>
#include <sys/stat.h>

int main() {
	int dd;
	

	dd = mkdir(argv[1], S_IRWXU | S_IRWXG);
	
