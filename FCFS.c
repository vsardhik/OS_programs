#include<stdio.h>
#define MAX 100

int main() {
    int n, i;
    int process[MAX], arrival[MAX], burst[MAX];
    int completion[MAX], turnaround[MAX], waiting[MAX];
    float avg_tat = 0, avg_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter arrival time and burst time for process %d: ", process[i]);
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    int current_time = 0;
    for (i = 0; i < n; i++) {
        if (current_time < arrival[i]) {
            current_time = arrival[i];
        }
        completion[i] = current_time + burst[i];
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
        avg_tat += turnaround[i];
        avg_wt += waiting[i];
        current_time = completion[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", process[i], arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}
