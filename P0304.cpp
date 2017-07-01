#include<stdio.h>
double sum = 2;
int n, b[41] = {1, 2}, i;
int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n - 1; i++)
    {
        b[i + 1] = b[i] + b[i - 1];
        sum += (double)b[i + 1] / b[i];
    }
    printf("%.2f", sum);
    return 0;
}
