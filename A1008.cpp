#include<stdio.h>
int main()
{
    int max1, min1, n, t, m;
    long sum;
    scanf("%d", &n);
    scanf("%d", &m);
    max1=m;
    min1=m;
    sum=m;
    for (t=1; t<=n-1; t++)
        {
            scanf("%d", &m);
            max1=max1>m?max1:m;
            min1=min1>m?m:min1;
            sum+=m;
        }
    printf("%d\n%d\n%d\n",max1,min1,sum);
    return 0;
}
