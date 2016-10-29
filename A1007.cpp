#include<stdio.h>
int main()
{
    int c1, c2, c3, n;
    scanf("%d", &n);
    for (c1=1; c1<=9; c1++)
    {
        for (c2=0; c2<=9; c2++)
        {
            for (c3=0; c3<=9; c3++)
            {
                if(c1*2+c2*2+c3==n)
                printf("%d%d%d%d%d\n",c1, c2, c3, c2, c1);
            }
        }
    }
    for (c1=1; c1<=9; c1++)
    {
        for (c2=0; c2<=9; c2++)
        {
            for (c3=0; c3<=9; c3++)
            {
                if(c1*2+c2*2+c3*2==n)
                    printf("%d%d%d%d%d%d\n",c1, c2, c3, c3, c2, c1);
            }
        }
    }
    return 0;
}
