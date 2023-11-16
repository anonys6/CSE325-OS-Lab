/*

Write a program to implement the process synchronization using mutex locks

*/

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int counter = 0;

void* thread_func(void* arg) {
    pthread_mutex_lock(&lock);
    counter += 1;
    printf("Counter: %d\n", counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[10];
    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }

    for(int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("Final Counter: %d\n", counter);
    return 0;
}