#include <stdio.h>
#include <time.h>
int SelectionSort(int[],int);

int main()
{
    clock_t start,end;
    int A[]={1,6,5,8,23,9};
    int n=sizeof(A)/sizeof(A[0]);
    start=clock();
    SelectionSort(A,n);
    end=clock();
    printf("Sorted Array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    printf("Time taken is %f seconds.\n",((double) (end - start)) / CLOCKS_PER_SEC);
    return 0; 
}

int SelectionSort(int A[],int n)
{
    int least;
    int p;
    int temp;
    for (int i = 0; i < n; i++)
    {
        least=A[i];
        p=i;
        for (int j = i+1; j < n; j++) // Start j from i+1
        {
            if(A[j]<least) // Compare A[j] with least
            {
                least = A[j];
                p=j;
            }
        }
        temp=A[i];
        A[i]=A[p];
        A[p]=temp;
    }
}
