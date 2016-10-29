#include<stdio.h>
unsigned int n, i;
int main()
{
    scanf("%u", &n);
    i = n << 16;
    n >>= 16;
    n += i;
    printf("%u", n);
    return 0;
}
