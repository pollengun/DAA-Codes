#include <stdio.h>
#include <string.h>
#include <time.h>

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int editDistanceDP(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
        }
    }

    return dp[m][n];
}

int main() {
    char str1[] = "computer";
    char str2[] = "timemachine";

    clock_t start_time = clock(); // Start the timer

    int result = editDistanceDP(str1, str2);

    clock_t end_time = clock(); // Stop the timer

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Edit distance between \"%s\" and \"%s\" is %d\n", str1, str2, result);
    printf("Execution time: %.6f seconds\n", execution_time);

    return 0;
}
