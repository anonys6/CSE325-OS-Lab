#include <stdio.h>
#include <sys/stat.h>

int main() {
	int dd;
	char dname[20];
	printf("Enter directory name: ");
	scanf("%s", dname);
	dd = mkdir(dname, S_IRWXU | S_IRWXG);
	if (dd == 0) printf("Directory created successfully\n");
	else printf("Directory already exists\n");

	return 0;
}
