#include <stdio.h>
#include <time.h>

int InsertionSort(int[],int);

int main()
{
    clock_t start,end;
    int A[] = {1, 6, 5, 8, 23, 9};
    int n = sizeof(A) / sizeof(A[0]);
    start = clock();
    InsertionSort(A, n);
    end = clock();
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    printf("Time taken is %f seconds.\n",((double) (end - start)) / CLOCKS_PER_SEC);

    return 0;
}

int InsertionSort(int A[], int n)
{
     int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;

        /* Move elements of A[0..i-1], that are greater than key,
        to one position ahead of their current position */
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}