#include <stdio.h>
#include <sys/time.h>

void MinMax(int A[], int l, int r, int *min, int *max) {
    if (l == r) { // If there is only one element
        *max = *min = A[l];
    } else if (l == r - 1) { // If there are two elements
        if (A[l] < A[r]) {
            *max = A[r];
            *min = A[l];
        } else {
            *max = A[l];
            *min = A[r];
        }
    } else {
        // Divide the array into halves
        int mid = (l + r) / 2;
        int min1 = *min, max1 = *max;
        
        // Recursively find the Min and Max of the first half
        MinMax(A, l, mid, min, max);
        
        // Recursively find the Min and Max of the second half
        MinMax(A, mid + 1, r, &min1, &max1);
        
        // Combine the results
        if (max1 > *max) {
            *max = max1;
        }
        if (min1 < *min) {
            *min = min1;
        }
    }
}


int main() {
    int A[] = {3, 5, 1, 2, 4, 6}; // Example array
    int n = sizeof(A) / sizeof(A[0]);
    int min, max;
    struct timeval start, end;
    long seconds, useconds;    
    double mtime;
    
    gettimeofday(&start, NULL);
    MinMax(A, 0, n - 1, &min, &max);
    gettimeofday(&end, NULL);
    
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;

    
    printf("Minimum element is %d\n", min);
    printf("Maximum element is %d\n", max);
    printf("Time taken to execute: %f milliseconds\n", mtime);
    
    return 0;
}
