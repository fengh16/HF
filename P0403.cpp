#include<stdio.h>
unsigned int a, sum;
int main()
{
    scanf("%u", &a);
    while(a >= 10)
    {
        sum = (a%10 == 0 ? 1 : a%10);
        a /= 10;
        while(a > 0)
        {
            sum *= (a%10 == 0 ? 1 : a%10);
            a /= 10;
        }
        a = sum;
    }
    printf("%u", a);
    return 0;
}
