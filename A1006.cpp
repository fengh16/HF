#include<stdio.h>
int main()
{
    int c1, c2;
    for (c1=1; c1<=9; c1++)
    {
        for (c2=0; c2<=9; c2++)
        {
            printf("%d%d%d%d\n",c1, c2, c2, c1);
        }
    }
    return 0;
}
