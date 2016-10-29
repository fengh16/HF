#include<stdio.h>
int main()
{
    int c1, c2, c3;
    for (c1=1; c1<=9; c1++)
    {
        for (c2=0; c2<=9; c2++)
        {
            for (c3=0; c3<=9; c3++)
            {
                if (100*c1+10*c2+c3 == c1*c1*c1+c2*c2*c2+c3*c3*c3)
                    printf("%d%d%d\n",c1,c2,c3);
            }
        }
    }
    return 0;
}
