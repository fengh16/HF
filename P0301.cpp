#include<stdio.h>
int min, max;
long long sum = 0;
int main()
{
    scanf("%d%d", &min, &max);
    for( ; min <= max; min++)
    {
        sum += min * min;
    }
    printf("%lld", sum);
    return 0;
}
