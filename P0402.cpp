#include<stdio.h>
int a[16] = {1, 3}, i;
int main()
{
    for(i = 2; i <= 15; i++)
        a[i] = 4 * a[i - 1] - a[i - 2];
    scanf("%d", &i);
    printf("%d", a[i]);
    return 0;
}
