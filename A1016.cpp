#include<stdio.h>
int i, n;
long year[500];
double x[500], y[500];
int main()
{
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &x[i], &y[i]);
        year[i] = (( x[i] * x[i] + y[i] * y[i]) * 3.141519)/100 + 1;
    }
    for(i = 1; i <= n; i++)
    {
        printf("%ld\n",year[i]);
    }
    return 0;
}
