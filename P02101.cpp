#include<stdio.h>
int main()
{
    char c1,c2,c3;
    scanf("%c%c%c",&c1,&c2,&c3);
    int n, n1, n2, n3, n4;
    n=(c1>='A'?c1-'A'+10:c1-'0')*15*15+(c2>='A'?c2-'A'+10:c2-'0')*15+(c3>='A'?c3-'A'+10:c3-'0');
    n4=n%7;n/=7;n3=n%7;n/=7;n2=n%7;n1=n/7;
    printf("%1d%1d%1d%1d",n1,n2,n3,n4);
    return 0;
}
