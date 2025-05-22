#include <stdio.h>

int main() {
    int i, j, n, time, remain, temps = 0, time_quantum;
    int wt = 0, tat = 0;
    int at[10], bt[10], rt[10];

    printf("Enter Total Process: ");
    scanf("%d", &n);
    remain = n;

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process P[%d]: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    for(time = 0, i = 0; remain != 0;) {
        if(rt[i] <= time_quantum && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            temps = 1;
        } else if(rt[i] > 0) {
            rt[i] -= time_quantum;
            time += time_quantum;
        }
        if(rt[i] == 0 && temps == 1) {
            remain--;
            printf("P[%d]\t%d\t\t%d\n", i+1, time - at[i], time - at[i] - bt[i]);
            wt += time - at[i] - bt[i];
            tat += time - at[i];
            temps = 0;
        }
        if(i == n - 1)
            i = 0;
        else if(at[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    printf("\nAverage Waiting Time = %.2f", (float)wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)tat / n);

    return 0;
}
