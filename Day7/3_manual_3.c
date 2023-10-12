#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int shared = 5;

sem_t s; // semaphore variable s

void *func1() {
    int local;

    // Critical section
    sem_wait(&s); // applying lock using s (initially 1)
    local = shared;
    local = local + 1;
    // sleep(5);
    shared = local;
    sem_post(&s); // releasing lock using s

    // Critical section

    printf("shared in func1: %d\n", shared);
    pthread_exit(NULL);
}

void *func2() {
    int local;

    // Critical section
    sem_wait(&s); // applying lock using s (initially 1)
    local = shared;
    local = local - 1;
    shared = local;
    sem_post(&s); // releasing lock using s

    // Critical section

    printf("shared in func2: %d\n", shared);
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    sem_init(&s, 0, 1); // initialize the semaphore
    pthread_create(&t1, NULL, func1, NULL);
    pthread_create(&t2, NULL, func2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&s); // destroy the semaphore

    return 0;
}