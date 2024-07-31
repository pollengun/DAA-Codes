#include <stdio.h>
#include <time.h>

int GCD(int m,int n)
{
    int r;
    if(n==0)
    return m;

    else if(m==0)
    return n;

    else
    {
        while(n != 0)
        {
            r = m % n;
            m = n;
            n=r;
        }
        return m;
    }
}



int main()
{
    clock_t start,end;
    int a,b;
    int result;
    printf("Enter any two numbers.\n");
    scanf("%d %d",&a,&b);
    start=clock();
    result=GCD(a,b);
    end=clock();
    printf("GCD of %d and %d is %d.\n",a,b,result);
    printf("Time taken is %f seconds.\n",((double) (end - start)) / CLOCKS_PER_SEC);
}

