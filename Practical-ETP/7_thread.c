#include <stdio.h>
#include <pthread.h>

void* t_f (void* args) {
    printf("Inside thread\n");
}

void* tp_f(void* args) {
    printf("Inside thread agian\n");
    int *x = args;
    printf("Sum: %d\n", x[0] + x[1]);
    pthread_exit("bye-bye");
}

int main() {
    pthread_t t;

    void* result;
    int num[2] = {3, 5};

    pthread_create(&t, NULL, t_f, NULL);
    pthread_join(t, NULL);

    printf("In main\n");

    pthread_t tp;

    pthread_create(&tp, NULL, tp_f, (void *)num);
    pthread_join(tp, &result);

    printf("Inside main again\n");
    printf("Thread returned: %s", (char *)result);

    return 0;
}

