#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function( void * arg);    
int num[2]={3,4};

int main()
{
        pthread_t a_thread; //thread declaration 
        void *result;

        pthread_create(&a_thread, NULL, thread_function, (void *)num); //thread created
        pthread_join(a_thread, &result);

        printf("Inside main program \n");
        printf("Thread returned sum is : %ld \n", (intptr_t)result);
        //printf("Thread returned sum is : %s \n", (char *)result);
        

    return 0;
}

void *thread_function(void *arg){
    printf("Inside Thread \n");
    int *x=arg;
    int sum=x[0]+x[1];
    printf("Sum is %d \n",sum);

    pthread_exit( (void*)(intptr_t)sum);
    //pthread_exit("Return of thread is sum \n");
}
