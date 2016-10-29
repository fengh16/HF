#include<stdio.h>
int main()
{
    int i, k, n;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        for(k = i; k >= 2; k--)
            printf("%c", 'A' + k - 1);
        for(k = 1; k <= i; k++)
            printf("%c", 'A' + k - 1);
        printf("\n");
    }
    return 0;
}
