#include<stdio.h>
int main()
{
    int j, i;
    for (j=1; j<=25; j++) 
    {
        for (i=j; i>1 && i>j-18; i--) 
            printf("%c",i-1+'A');
        for (i=1; i<=18-j+1; i++) 
            {
                printf("%c",i-1+'A');
            }
        printf("\n");
    }
    return 0;
}
