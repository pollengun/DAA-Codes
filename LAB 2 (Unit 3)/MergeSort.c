#include <stdio.h>
#include <sys/time.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    int arr[100], arr_size, i;
    struct timeval start, end;
    long seconds, useconds;    
    double mtime;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &arr_size);
    printf("Enter the elements of the array: ");
    for (i = 0; i < arr_size; i++)
        scanf("%d", &arr[i]);

    gettimeofday(&start, NULL);
    mergeSort(arr, 0, arr_size - 1);
    gettimeofday(&end, NULL);

     seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;

    printf("\nSorted array is \n");
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
   printf("Time taken to execute: %f milliseconds\n", mtime);
    return 0;
}
