#include<stdio.h>
int main()
{
    char c1, c2, c3;
    int i0, o1, o2, o3, o4, i;
    scanf("%c%c%c", &c1, &c2, &c3);
    i0 = (c1 >= 'A' ? c1 - 'A' + 10 : c1 - '0') * 16 * 16 + (c2 >= 'A' ? c2 - 'A' + 10 : c2 - '0') * 16 + (c3 >= 'A' ? c3 - 'A' + 10 : c3 - '0');
    i = i0;
    o4 = i % 8; i /= 8; o3 = i % 8; i /= 8; o2 = i % 8; i /= 8; o1 = i % 8;
    printf("0x%c%c%c\n%.4d\n%1d%1d%1d%1d", c1, c2, c3, i0, o1, o2, o3, o4);
    return 0;
}
