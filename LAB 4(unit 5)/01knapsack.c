#include <stdio.h>
#include <time.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);

    clock_t start_time = clock(); // Start the timer

    int result = knapSack(W, weight, profit, n);

    clock_t end_time = clock(); // Stop the timer

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Maximum profit: %d\n", result);
    printf("Execution time: %.6f seconds\n", execution_time);

    return 0;
}
