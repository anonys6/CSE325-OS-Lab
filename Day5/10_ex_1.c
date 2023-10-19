// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>

// int main() {
//     pid_t pid;

//     int count_child = 0;
//     int count_parent = 0;
//     pid = fork();
//     pid = fork();

//     if (pid == -1) {
//         printf("Error\n");
//     } else if (pid == 0) {
//         printf("Child process with PID: %d\n", getpid());
//         count_child++;
//     } else {
//         printf("Parent process with PID: %d\n", getpid());
//         count_parent++;
//     }

//     printf("No of Parent Prodess: %d\n", count_parent);
//     printf("No of Child Prodess: %d\n", count_child);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>

// int main()
// {
//   int n = 3; // Replace with desired value of n

//   pid_t pid;
//   int count_child = 0;
//   int count_parent = 0;

//   for (int i = 0; i < n; i++)
//   {
//     pid = fork();

//     if (pid == -1)
//     {
//       printf("Error\n");
//       exit(1);
//     }
//     else if (pid == 0)
//     {
//       printf("Child process with PID: %d\n", getpid());
//       count_child++;
//     }
//     else
//     {
//       printf("Parent process with PID: %d\n", getpid());
//       count_parent++;
//     }
//   }

//   printf("No of Parent Processes: %d\n", count_parent);
//   printf("No of Child Processes: %d\n", count_child);

//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int n;
  printf("How many times fork should work: ");
  scanf("%d", &n);
  pid_t pid;

  for (int i = 0; i < n; i++) {
    pid = fork();
    if (pid == -1)
      printf("Fork call unsuccessfull\n");
    else if (pid == 0) {
      printf("Child process wit PID: %d\n", getpid());
    }
    else {
      sleep(2);
    }
  }

  return 0;
}