#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
int partition_random(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_random(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int arr[100], n, i;
    struct timeval start, end;
    long seconds, useconds;    
    double mtime;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
        
    gettimeofday(&start, NULL);
    quickSort(arr, 0, n - 1);
    gettimeofday(&end, NULL);

    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;


    printf("\nSorted array is \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
   printf("Time taken to execute: %f milliseconds\n", mtime);
    return 0;
}
