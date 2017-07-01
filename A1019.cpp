#include<stdio.h>
int a, b, c, d;
int main()
{
    for (a = 1; a <= 4; a++)
    {
        for (b = 1; b <= 4; b++)
        {
            for (c = 1; c <= 4; c++)
            {
                for (d = 1; d <= 4; d++)
                {
                    printf("%c%c%c%c\n", 'A' + a - 1, 'A' + b - 1, 'A' + c - 1, 'A' + d - 1);
                }
            }
        }
    }
    return 0;
}
