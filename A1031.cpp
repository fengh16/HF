#include<stdio.h>
int main()
{
    int i, k;
    for(i = 1; i <= 15; i++)
    {
        for(k = i; k >= 2; k--)
            printf("%c", 'A' + k - 1);
        for(k = 1; k <= i; k++)
            printf("%c", 'A' + k - 1);
        printf("\n");
    }
    return 0;
}
