#include <stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};


// Adjusted sort, used example here
//https://www.geeksforgeeks.org/c/c-program-to-sort-an-array-in-ascending-order/
void sortFcfs(struct process proc[], int n) {
    struct process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Sort by arrival time, then by PID
            if (proc[j].arrival_time > proc[j + 1].arrival_time ||
                (proc[j].arrival_time == proc[j + 1].arrival_time 
                    && proc[j].pid > proc[j + 1].pid)) {
                temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}


void fcfs(struct process proc[], int n) {
    sortFcfs(proc, n);

    int time = 0;
    
    float total_wait = 0, total_turn = 0, total_response = 0;

    for (int i = 0; i < n; i++) {
        if (time < proc[i].arrival_time) {
        time = proc[i].arrival_time;
        }

        proc[i].waiting_time = time - proc[i].arrival_time;
        time += proc[i].burst_time;
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
        proc[i].response_time = proc[i].waiting_time;

        total_wait += proc[i].waiting_time;
        total_turn += proc[i].turnaround_time;
        total_response += proc[i].response_time;
    }

    printf("\n=== First Come First Served (FCFS) ===\n");
    printf("Gantt Chart: ");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", proc[i].pid);
    }
    printf("|\n\n");
    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               proc[i].pid, proc[i].arrival_time, proc[i].burst_time,
               proc[i].waiting_time, proc[i].turnaround_time, proc[i].response_time);
    }

    printf("Average Waiting Time: %.2f\n", total_wait / n);
    printf("Average Turnaround Time: %.2f\n", total_turn / n);
    printf("Average Response Time: %.2f\n", total_response / n);

}


int main() 
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter the arrival time and burst time for process %d: ", proc[i].pid);
        scanf("%d %d", &proc[i].arrival_time, &proc[i].burst_time);
    }
    
    fcfs(proc, n);
    return 0;
}
