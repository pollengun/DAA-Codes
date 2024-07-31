#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// Structure to represent a job
typedef struct Job {
    int id;
    int profit;
    int deadline;
} Job;

// Compare function for sorting jobs by profit (in decreasing order)
int compare(const void* a, const void* b) {
    Job* job1 = (Job*)a;
    Job* job2 = (Job*)b;
    return job2->profit - job1->profit;
}

// Find an available time slot
int getSlot(int dl, bool slot[], int n) {
    for (int i = dl - 1; i >= 0; i--) {
        if (!slot[i]) {
            return i;
        }
    }
    return -1;
}

// Schedule jobs and print the result
void jobSequencing(Job arr[], int n) {
    clock_t start_time = clock();
    qsort(arr, n, sizeof(Job), compare);
    bool slot[n];
    int result[n];
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        int avail = getSlot(arr[i].deadline, slot, n);
        if (avail != -1) {
            slot[avail] = true;
            result[avail] = i;
            totalProfit += arr[i].profit;
        }
    }

    printf("Job sequence: ");
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("%d ", arr[result[i]].id);
        }
    }
    printf("\nTotal profit: %d\n", totalProfit); 
    clock_t end_time = clock();

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time: %.6f seconds\n", execution_time);

}

int main() {
    Job arr[] = {
        {1, 100, 2},
        {2, 19, 1},
        {3, 27, 2},
        {4, 25, 1},
        {5, 15, 3}
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Job sequencing with deadlines:\n");
    jobSequencing(arr, n);

    return 0;
}
