#include<stdio.h>
int main()
{
    long long a[50];
    int n, i, t;
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        a[i] = 1;
        for(t = i - 1; t >= 2; t--)
        {
            a[t] = a[t] + a[t-1];
        }
        for(t = 1; t <= i; t++)
        {
            printf("%d ", a[t]);
        }
        printf("\n");
    }
    return 0;
}
