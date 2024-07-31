#include <stdio.h>
#include <time.h>
int LinearSearch(int,int[],int);

int main()
{
    clock_t start,end;
    int key;
    int A[]={1,6,5,8,23,9};
    int n=sizeof(A)/sizeof(A[0]);
    printf("Enter the element to search\n");
    scanf("%d",&key);
    start=clock();
    LinearSearch(n,A,key);
    end=clock();
    printf("Time taken is %f seconds.\n",((double) (end - start)) / CLOCKS_PER_SEC);
}
int LinearSearch(int n,int A[],int key)
{
    int flag=0;
    int i=0;
    for(i=0;i<n;i++)
    {
        if(A[i]==key){
        flag=1;
        break;
        }
    }
    if(flag==1)
    printf("Element found at position %d\n",i+1);
    else
    printf("Element not found\n");
}