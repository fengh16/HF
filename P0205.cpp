#include<stdio.h>
int main()
{
    int n, min;
    double tax, salary;
    scanf("%d",&n);
    switch (n)
    {
        case 1:
            min=17850;
            break;
        case 2:
            min=23900;
            break;
        case 3:
            min=29750;
            break;
        case 4:
            min=14875;
            break;
    }
    scanf("%lf",&salary);
    tax= salary<min? 0.15*salary: 0.15*min+0.28*(salary-min);
    printf("%lf",tax);
    return 0;
}
