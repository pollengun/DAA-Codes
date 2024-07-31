#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For measuring execution time

struct Item {
    int profit;
    int weight;
};

int compare(const void* a, const void* b) {
    double ratioA = ((struct Item*)a)->profit / (double)((struct Item*)a)->weight;
    double ratioB = ((struct Item*)b)->profit / (double)((struct Item*)b)->weight;
    return (ratioB > ratioA) - (ratioB < ratioA);
}

double fractionalKnapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(struct Item), compare);

    double result = 0.0;
    int currWeight = W;

    clock_t start_time = clock(); // Start measuring time

    for (int i = 0; i < n; ++i) {
        if (arr[i].weight <= currWeight) {
            result += arr[i].profit;
            currWeight -= arr[i].weight;
        } else {
            result += (double)arr[i].profit * currWeight / arr[i].weight;
            break;
        }
    }

    clock_t end_time = clock(); // Stop measuring time
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Maximum profit: %.2lf\n", result);
    printf("Time taken: %.6lf seconds\n", elapsed_time);

    return result;
}

int main() {
    int W = 50;
    int n = 3;

    struct Item items[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    fractionalKnapsack(W, items, n);

    return 0;
}
