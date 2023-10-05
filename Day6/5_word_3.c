#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

struct arg_struct
{
    int arg1;
    int arg2;
};

void *first(void *arg)
{
    struct arg_struct *args = arg;

    printf("%d \n", args->arg1);
    printf("%d \n", args->arg2);

    int c = args->arg1 + args->arg2;
    // printf("Sum of two no`s is : %d \n",c);

    pthread_exit((void *)(intptr_t)c);
}

void *second(void *arg)
{
    struct arg_struct *args = arg;

    printf("%d \n", args->arg1);
    printf("%d \n", args->arg2);

    int d = args->arg1 - args->arg2;

    pthread_exit((void *)(intptr_t)d);
}

int main()
{
    pthread_t t1ID, t2ID; // thread declaration

    struct arg_struct args;
    args.arg1 = 6;
    args.arg2 = 4;

    void *a1, *a2;

    pthread_create(&t1ID, NULL, first, &args); // thread created
    pthread_join(t1ID, &a1);
    printf("Return of first thread is sum : %ld \n", (intptr_t)a1);

    pthread_create(&t2ID, NULL, first, &args); // thread created
    pthread_join(t2ID, &a2);
    printf("Return of second thread is sub : %ld \n", (intptr_t)a2);

    return 0;
}
