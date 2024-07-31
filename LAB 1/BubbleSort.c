#include <stdio.h>
#include <time.h>
int BubbleSort(int[],int);
int main()
{
    int A[]={1,6,5,8,23,9};
    int n=sizeof(A)/sizeof(A[0]);
    clock_t start,end;
    start=clock();
    BubbleSort(A,n);
    end=clock();
    printf("Sorted Array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    printf("Time taken is %f seconds.\n",((double) (end - start)) / CLOCKS_PER_SEC);

}

int BubbleSort(int A[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if(A[j]>A[j+1])
            {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
        
    }
    
}