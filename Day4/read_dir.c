#include <stdio.h>
#include <dirent.h>

int main() {
	DIR *dp;
	struct dirent *Ddp;
	dp = opendir("Hello");

	if (dp == NULL) printf("Directory is not opened\n");
	else printf("Directory is opened\n");

	while((Ddp = readdir(dp)) != NULL) {
		printf("%s \n", Ddp -> d_name);
		printf("%ld \n", Ddp -> d_ino);
	}

	return 0;
}
