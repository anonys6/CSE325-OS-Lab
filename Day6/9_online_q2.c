#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

struct Operand
{
    int o1;
    int o2;
};

void *sum(void *Operand)
{
    struct Operand *args = Operand;

    int result = args->o1 + args->o2;
    printf("Sum = %d\n", result);

    pthread_exit(NULL);
}

void *difference(void *Operand)
{
    struct Operand *args = Operand;

    int result = args->o1 - args->o2;
    printf("Difference = %d\n", result);

    pthread_exit(NULL);
}

void *product(void *Operand)
{
    struct Operand *args = Operand;

    int result = args->o1 * args->o2;
    printf("Product = %d\n", result);

    pthread_exit(NULL);
}

void *quotient(void *Operand)
{
    struct Operand *args = Operand;

    if (args->o2 == 0)
    {
        printf("Division by zero\n");
        return NULL;
    }
    int result = args->o1 / args->o2;
    printf("Quotient = %d\n", result);

    pthread_exit(NULL);
}

void *mod(void *Operand)
{
    struct Operand *args = Operand;

    int result = args->o1 % args->o2;
    printf("Modulus = %d\n", result);

    pthread_exit(NULL);
}

int main()
{
    int a, b;
    printf("Enter two operands: ");
    scanf("%d %d", &a, &b);

    struct Operand o;
    o.o1 = a;
    o.o2 = b;

    pthread_t sum_thread, diff_thread, pro_thread, quo_thread, mod_thread;

    pthread_create(&sum_thread, NULL, sum, &o);
    pthread_create(&diff_thread, NULL, difference, &o);
    pthread_create(&pro_thread, NULL, product, &o);
    pthread_create(&quo_thread, NULL, quotient, &o);
    pthread_create(&mod_thread, NULL, mod, &o);

    pthread_join(sum_thread, NULL);
    pthread_join(diff_thread, NULL);
    pthread_join(pro_thread, NULL);
    pthread_join(quo_thread, NULL);
    pthread_join(mod_thread, NULL);

    return 0;
}