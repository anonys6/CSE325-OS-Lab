#include <stdio.h>
#include <pthread.h>

int shared = 5;
pthread_mutex_t l; // mutex varialbe l

void *func1() {
    int local;
    // Critical section

    pthread_mutex_lock(&l); // lock the mutex (initially unlocked)
    local = shared;
    local = local + 1;

    shared = local;
    pthread_mutex_unlock(&l); // unlock the mutex

    // Critical section

    printf("shared in func1: %d\n", shared);
    pthread_exit(NULL);
}

void *func2() {
    int local;

    // Critical section
    pthread_mutex_lock(&l); // if acquired by func1, l will return true
    local = shared;
    local = local - 1;

    shared = local;
    pthread_mutex_unlock(&l); // unlock the mutex

    // Critical section

    printf("shared in func2: %d\n", shared);
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    
    pthread_mutex_init(&l, NULL); // initialize the mutex
    pthread_create(&t1, NULL, func1, NULL);
    pthread_create(&t2, NULL, func2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&l); // destroy the mutex

    return 0;
}