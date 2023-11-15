#include<stdio.h>

struct process {
    int pid;
    int bt;
    int priority;
};

void findWaitingTime(struct process proc[], int n, int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n ; i++ )
        wt[i] = proc[i-1].bt + wt[i-1];
}

void findTurnAroundTime(struct process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n ; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findavgTime(struct process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);
    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for (int i=0; i<n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d", proc[i].pid, proc[i].bt, wt[i], tat[i]);
    }
    printf("\n\nAverage waiting time = %.2f", (float)total_wt / (float)n);
    printf("\nAverage turnaround time = %.2f\n", (float)total_tat / (float)n);
}

void priorityScheduling(struct process proc[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (proc[i].priority > proc[j].priority) {
                struct process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
    findavgTime(proc, n);
}

int main() {
    struct process proc[] = {{1, 10, 1}, {2, 5, 0}, {3, 8, 1}};
    int n = sizeof proc / sizeof proc[0];
    priorityScheduling(proc, n);
    return 0;
}
