#include<stdio.h>
int a, b, c, Price;
int main()
{
    scanf("%d%d%d", &a, &b, &c);
    Price = 3 * a + 2 * b + 8 * c;
    printf("%d", Price);
    return 0;
}
