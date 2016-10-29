#include<stdio.h>
int main()
{
    int i,t,h;
    int a[6];
    for (i=0; i<64; i++) 
        {
            h=i;
            for (t=0; t<6; t++) 
            {
                a[5-t]=h%2;
                h=h/2;
            }
            for (t=0; t<6; t++)
            {
                printf("%d",a[t]);
            }
            printf("\n");
        }
    return 0;
}
