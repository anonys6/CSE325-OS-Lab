#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void *thread_function( void * arg);    // thread function declaration

int i,j;

int main() {
        pthread_t a_thread; //thread declaration 
        pthread_create(&a_thread, NULL, thread_function, NULL); //thread created
        // pthread_join(a_thread, NULL);

        printf("Inside main program \n");
        for(i = 20; i < 25; i++){
                printf("%d \n",i);
                // sleep(2);
        }

    pthread_join(a_thread, NULL);
    return 0;
}

void *thread_function(void *arg) {   // thread function definition
        printf("Inside Thread \n");
        for(j = 0; j < 5; j++){
                printf("%d \n", j);
                // sleep(2);
        }
}