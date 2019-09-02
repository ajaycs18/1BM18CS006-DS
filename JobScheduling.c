#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid, time;
};

void insert(struct process *p, int *r, int n) {
    if (*r == n - 1) {
        printf("overflow");
        return;
    }
    printf("enter pid and time of the process %d: ", ++(*r) + 1);
    scanf("%d %d", &p[*r].pid, &p[*r].time);
}

int main() {
    struct process *jobs;
    int nJobs, r = -1, f = 0;
    printf("enter number of jobs: ");
    scanf("%d", &nJobs);
    jobs = calloc(nJobs, sizeof(struct process));

    for (int i = 0; i < nJobs; i++) {
        insert(jobs, &r, nJobs);
    } 

    int initTime = 0;
    for (int i = f; i <= r; i++) {
        printf("process %d starts at %d and ends at %d\n", jobs[i].pid, initTime, initTime + jobs[i].time);
        initTime = jobs[i].time;
    }

    fflush(stdin);
    getchar();
    return 0;
}