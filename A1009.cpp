#include<stdio.h>
int main()
{
    int max1, max2, min1, min2, n, t, m;
    long sum;
    scanf("%d", &n);
    scanf("%d", &m);
    max1=m;
    min1=m;
    sum=m*m;
    scanf("%d", &m);
    if (m>=max1)
    {
        max2=max1;
        max1=m;
    }
    else
    {
        max2=m;
    }
    if (m<=min1)
    {
        min2=min1;
        min1=m;
    }
    else
    {
        min2=m;
    }
    sum+=m*m;
    for (t=1; t<=n-2; t++)
        {
            scanf("%d", &m);
            if (m>=max1)
            {
                max2=max1;
                max1=m;
            }
            else if (m>=max2)
            {
                max2=m;
            }
            if (m<=min1)
            {
                min2=min1;
                min1=m;
            }
            else if (m<=min2)
            {
                min2=m;
            }
            sum+=m*m;
        }
    printf("%d\n%d\n%d\n",max2,min2,sum);
    return 0;
}
