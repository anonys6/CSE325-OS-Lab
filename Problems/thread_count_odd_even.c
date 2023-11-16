/*

Write a program to create two threads. one will print the numbers from 1 to 10 and the other thread will find weather a number entered by the user is even or odd.

*/


#include <stdio.h>
#include <pthread.h>

void* print_numbers(void* arg) {
    for(int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }
    return NULL;
}

void* check_even_odd(void* arg) {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if(num % 2 == 0) {
        printf("%d is even\n", num);
    } else {
        printf("%d is odd\n", num);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, print_numbers, NULL);
    pthread_create(&thread2, NULL, check_even_odd, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}