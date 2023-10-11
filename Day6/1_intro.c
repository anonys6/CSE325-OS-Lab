/*
5 fun() of thread
pthread_init() - to initialize a thread
thread_create() - to create a thread
pthread_joid(td, NULL) - to join a thread in the main function and retrieve the value returned by thread fun()

pthread_create takes 4 arguments
1. thread id
2. thread attribute
3. thread fun()
4. thread fun() arguments

pthread_join takes 2 arguments
1. thread id
2. return value of thread fun()

pthread_exit() - to exit a thread

*/


#include <stdio.h>
#include <pthread.h>

void *hello (void *i) {
    int *p = (int *) i;
    
    printf("Hello, this statement is printed by thread1\n");
    printf("The argument: %d\n", *p);
    
    return NULL;
}

int main() {
    void *status;
    pthread_t thread1;
    int fun_arg = 10;
    pthread_create(&thread1, NULL, hello, (void *)&fun_arg);
    pthread_join(thread1, &status);
    printf("%s\n", (char *) status);
    
    return 0;
}