// #include <stdio.h>
// #include <pthread.h>

// int *a;

// struct arg_struct
// {
//     int arg1;
//     int arg2;
//     int arg3;
// };

// void *print_the_arguments(void *arg)
// {
//     struct arg_struct *ar = (struct arg_struct *)arg;
//     scanf("%d", &ar->arg3);
//     scanf("%d", &ar->arg2);
//     int c = ar->arg2 + ar->arg3;
//     pthread_exit((void *)c);
// }

// int main()
// {
//     pthread_t some_thread;
//     struct arg_struct args;
//     args.arg1 = 5;
//     args.arg2 = 7;
//     void *result;
//     pthread_create(&some_thread, NULL, &print_the_arguments, &args);
//     pthread_join(some_thread, &result); /* Wait until the thread is finished */
//     printf("%d \n", (int)result);
//     return 0;
// }

#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

int *a;

struct arg_struct
{
    int arg1;
    int arg2;
    int arg3;
};

void *print_the_arguments(void *arg)
{
    struct arg_struct *ar = (struct arg_struct *)arg;
    scanf("%d", &ar->arg2);
    scanf("%d", &ar->arg3);
    int c = ar->arg2 + ar->arg3;
    pthread_exit((void *)(intptr_t)c);
}

int main()
{
    pthread_t some_thread;
    struct arg_struct args;
    args.arg1 = 5;
    args.arg2 = 7;
    void *result;
    pthread_create(&some_thread, NULL, &print_the_arguments, &args);
    pthread_join(some_thread, &result); /* Wait until the thread is finished */
    printf("%d \n", (intptr_t)result);
    return 0;
}