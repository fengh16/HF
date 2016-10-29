#include<stdio.h>
int main()
{
    char c1, c2, c3;
    int i;
    scanf("%c%c%c", &c1, &c2, &c3);
    i=(c1>='A'? c1-'A'+10: c1-'0')*16*16+(c2>='A'? c2-'A'+10: c2-'0')*16+(c3>='A'? c3-'A'+10: c3-'0');
    printf("0x%.3X\n%.4d\n%.4o", i, i, i);
    return 0;
}
