#include <stdio.h>
struct Process {
    int id;
    int burst_time;
    int priority;
};

int main() {
    int n, i, j;
    struct Process p[10], temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        p[i].id = i + 1;

        printf("\nProcess %d:\n", p[i].id);
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].burst_time);

        printf("Enter Priority: ");
        scanf("%d", &p[i].priority);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("\nExecution Order (Priority Scheduling):\n");
    for(i = 0; i < n; i++) {
        printf("P%d ", p[i].id);
    }
    printf("\n");
    return 0;
}
