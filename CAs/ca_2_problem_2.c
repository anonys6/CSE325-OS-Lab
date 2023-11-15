/*
    Reg No: 12203273, Name: Md Shakib Alam, Section: K22SK, Roll NO: 67
*/

/*
    Problem 2: You are given a shared data structure that can be read by multiple threads simultaneously, but can only be written to by one thread at a time. Readers can access the data structure concurrently, but writers must have exclusive access. When a writer is writing to the data structure, no readers can access it. Similarly, when a reader is reading from the data structure, no writers can write to it. Your task is to design a program that coordinates the readers and writers, ensuring that no reader or writer is left waiting indefinitely and that the data structure is not accessed concurrently by readers and writers.

    You should implement a solution using one of the following synchronization mechanisms: locks, semaphores, or monitors. Your program should also include a mechanism to test the correctness of your solution, such as printing debug information or using assertions to verify that the data structure is being accessed correctly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_READERS 10

int data = 0;       // shared data structure

// synchronization mechanisms
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;          // initialize mutex (unlocked stage)
sem_t rw_sem;
int readers_count = 0;

// reader thread function
void *reader(void *arg) {
    int id = *(int *)arg;
    
    while (1) {
        // acquire read lock
        pthread_mutex_lock(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&rw_sem);
        }
        pthread_mutex_unlock(&mutex);

        printf("Reader %d read data: %d\n", id, data);      // read data

        pthread_mutex_lock(&mutex);     // release read lock

        readers_count--;

        if (readers_count == 0) {
            sem_post(&rw_sem);
        }
        
        pthread_mutex_unlock(&mutex);

        // sleep for some time
        usleep(rand() % 1000000);
    }
    
    return NULL;
}

// writer thread function
void *writer(void *arg) {
    int id = *(int *)arg;
    while (1) {
        // acquire write lock
        sem_wait(&rw_sem);

        // write data
        data++;
        printf("Writer %d wrote data: %d\n", id, data);

        // release write lock
        sem_post(&rw_sem);

        // sleep for some time
        usleep(rand() % 1000000);
    }
    
    return NULL;
}

int main() {
    
    // initialize synchronization mechanisms
    if (sem_init(&rw_sem, 0, 1) != 0) {
        perror("Semaphore initialization failed");
        exit(EXIT_FAILURE);
    }

    // create reader threads
    pthread_t readers[MAX_READERS];
    int reader_ids[MAX_READERS];
    for (int i = 0; i < MAX_READERS; i++) {
        reader_ids[i] = i + 1;
        if (pthread_create(&readers[i], NULL, reader, &reader_ids[i]) != 0) {
            perror("Reader thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    // create writer threads
    pthread_t writers[2];
    int writer_ids[2];
    for (int i = 0; i < 2; i++) {
        writer_ids[i] = i + 1;
        if (pthread_create(&writers[i], NULL, writer, &writer_ids[i]) != 0) {
            perror("Writer thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    // join threads
    for (int i = 0; i < MAX_READERS; i++) {
        if (pthread_join(readers[i], NULL) != 0) {
            perror("Reader thread join failed");
            exit(EXIT_FAILURE);
        }
    }
    
    for (int i = 0; i < 2; i++) {
        if (pthread_join(writers[i], NULL) != 0) {
            perror("Writer thread join failed");
            exit(EXIT_FAILURE);
        }
    }

    // destroy synchronization mechanisms
    if (sem_destroy(&rw_sem) != 0) {
        perror("Semaphore destruction failed");
        exit(EXIT_FAILURE);
    }
    
    if (pthread_mutex_destroy(&mutex) != 0) {
        perror("Mutex destruction failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}