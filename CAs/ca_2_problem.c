#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

// process structure
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int priority;
} process;

// queue structure
typedef struct {
    process *processes[MAX_PROCESSES];
    int front;
    int rear;
} queue;

// function prototypes
void enqueue(queue *q, process *p);
process *dequeue(queue *q);
int is_empty(queue *q);
int is_full(queue *q);
void srot(queue *q1, queue *q2);
void execute_process(process *p, int time_quantum);

int main() {
    // initialize queues
    queue q1 = { .front = 0, .rear = -1 };
    queue q2 = { .front = 0, .rear = -1 };

    // get number of processes from user
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // get arrival time and burst time for each process from user
    process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].priority = 1;
        enqueue(&q1, &processes[i]);
    }

    // execute processes
    int current_time = 0;
    while (!is_empty(&q1) || !is_empty(&q2)) {
        if (!is_empty(&q1)) {
            srot(&q1, &q2);
            process *p = dequeue(&q1);
            execute_process(p, 1);
            current_time++;
            if (p->remaining_time > 0) {
                enqueue(&q2, p);
            }
        } else {
            process *p = dequeue(&q2);
            execute_process(p, 2);
            current_time += 2;
        }
    }

    // calculate average turnaround time and average waiting time for each process
    float avg_turnaround_time = 0;
    float avg_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
    }
    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    // print results
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    printf("Average waiting time: %.2f\n", avg_waiting_time);

    return 0;
}

// enqueue a process in the queue
void enqueue(queue *q, process *p) {
    if (is_full(q)) {
        printf("Queue is full\n");
        exit(EXIT_FAILURE);
    }
    q->rear++;
    q->processes[q->rear] = p;
}

// dequeue a process from the queue
process *dequeue(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    process *p = q->processes[q->front];
    q->front++;
    return p;
}

// check if the queue is empty
int is_empty(queue *q) {
    return q->front > q->rear;
}

// check if the queue is full
int is_full(queue *q) {
    return q->rear == MAX_PROCESSES - 1;
}

// perform shortest remaining processing time first algorithm
void srot(queue *q1, queue *q2) {
    for (int i = q1->front; i <= q1->rear; i++) {
        for (int j = i + 1; j <= q1->rear; j++) {
            if (q1->processes[i]->remaining_time > q1->processes[j]->remaining_time) {
                process *temp = q1->processes[i];
                q1->processes[i] = q1->processes[j];
                q1->processes[j] = temp;
            }
        }
    }
}

// execute a process for a given time quantum
void execute_process(process *p, int time_quantum) {
    p->remaining_time -= time_quantum;
    if (p->remaining_time < 0) {
        p->remaining_time = 0;
    }
    for (int i = p->arrival_time; i < p->arrival_time + time_quantum && i < p->arrival_time + p->burst_time; i++) {
        p->waiting_time += i < p->arrival_time ? 0 : 1;
    }
}