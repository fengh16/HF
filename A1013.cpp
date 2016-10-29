#include<stdio.h>
int main()
{
    char c;
    long long i = 0;
    c = getchar();
    while (((c >= '0'&&c <= '9') || (c >= 'A'&&c <= 'F')))
    {
        i = i * 16 + (c >= 'A' ? c - 'A' + 10 : c - '0');
        c = getchar();
    }
    printf("%lld", i);
    return 0;
}
