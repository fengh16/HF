#include<stdio.h>
#include<math.h>
int main()
{
    double a, b, c, max, s, l;
    max=a>b?a:b;
    max=max>c?max:c;
    if (a+b>c && a+c>b && b+c>a) 
    {
        l=(a+b+c)/2;
        s=sqrt(l*(l-a)*(l-b)*(l-c));
        printf("%f",2*s/max);
    }
    else printf("NO");
    return 0;
}
