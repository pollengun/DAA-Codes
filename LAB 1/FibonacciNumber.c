#include <stdio.h>
#include<time.h>

int fib(int);

int main(){
    clock_t start,end;
    int n;
    int result;
    printf("Enter the position of fibonacci sequence\n");
    scanf("%d",&n);
    start=clock();
    result = fib(n);
    end=clock();
    printf("The %dth number in fibonacci sequence is %d\n",n,result);
    printf("Time taken is %f seconds\n",(double)(end-start)/CLOCKS_PER_SEC);
}

int fib(int n)
{
    int first = 0;
    int second = 1;
    int i = 3;
    int temp;

    if(n==1)
    return 0;

    else if(n==2)
    return 1;

    else{
    while(i<=n)
        {
            temp =  first + second;
            first = second;
            second = temp;
            i++;
        }
    return temp;
    }
}