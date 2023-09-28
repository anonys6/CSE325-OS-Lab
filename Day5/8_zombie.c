#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t pid;
	pid = fork();
	if (pid > 0) {
		sleep(5);
		printf("The process ID of the parent is: %d\n", getpid());
	}
	else if (pid == 0) { 
		printf("The process ID of the child is: %d \n", getpid());
        exit(0); 
	} else {
		printf("Forking failed!\n");
		exit(1);
	}
	return 0;
}
