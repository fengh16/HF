#include<stdio.h>
int main()
{
    int h, m, s;
    long t;
    scanf("%ld", &t);
    s = t % 60;
    t /= 60;
    m = t % 60;
    h = t / 60;
    printf("%d:%d:%d", h, m, s);
    return 0;
}
