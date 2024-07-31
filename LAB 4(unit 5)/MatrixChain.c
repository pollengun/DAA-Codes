#include <stdio.h>
#include <limits.h>

// Function to implement Matrix Chain Multiplication
void MatrixChainMultiplication(int p[], int n) {
    int m[n][n]; // m[i][j] stores minimum number of scalar multiplications needed to compute the matrix chain from i to j
    int s[n][n]; // s[i][j] stores the index at which the optimal split occurs

    // Initialize the main diagonal of m to 0, since the cost of multiplying one matrix is zero
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // l is the chain length
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Printing the m and s arrays
    printf("Matrix m (cost of multiplications):\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i <= j) {
                printf("%d ", m[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("\nMatrix s (split points):\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i <= j && i != j) {
                printf("%d ", s[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int p[] = {30, 35, 15, 5, 10, 20, 25}; // Example dimensions of matrices
    int n = sizeof(p) / sizeof(p[0]); // Number of matrices is n-1

    MatrixChainMultiplication(p, n);

    return 0;
}
