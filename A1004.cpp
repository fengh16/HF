#include<stdio.h>
int main()
{
    int j, i, n, m;
    scanf("%d%d",&n,&m);
    for (j=1; j<=n; j++) 
    {
        for (i=j; i>1 && i>j-m; i--) 
            printf("%c",i-1+'A');
        for (i=1; i<=m-j+1; i++) 
            {
                printf("%c",i-1+'A');
            }
        printf("\n");
    }
    return 0;
}
