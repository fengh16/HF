#include<stdio.h>
int main()
{
    char a[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char b[99];
    int p = 16, t = 1;
    long n;
    scanf_s("%ld",&n);
    if (n != 0)
    {
        while (n != 0)
        {
            b[t] = a[n%p];
            n /= p;
            t++;
        }
        while (t > 1)
        {
            t--;
            printf("%c", b[t]);
        }
    }
    else printf("0");
    return 0;
}
