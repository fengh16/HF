#include<stdio.h>
#include<string.h>
int base, i, n[11], t[11], k, numm, num;
char a[11][100001]={0};
int b[11][70000];
int Sixteen_to_ten(char m)
{
    int o;
    o = m > '9'? m - 'A' + 10: m - '0';
    return o;
}
int main()
{
    scanf("%d",&numm);
    for(num = 1; num <= numm; num++)
    {
    k = 0;
    scanf("%s", &a[num][1]);
    a[num][0] = '0';
    i = strlen(a[num]) - 1;
    n[num] = (i - 1) / 3 + 1;
    base = i - n[num] * 3 + 3;
    for(t[num] = 1; t[num] <= base; t[num]++)
    {
        k = 16 * k + Sixteen_to_ten(a[num][t[num]]);
    }
    b[num][1] = k; 
    for(t[num] = 2; t[num] <= n[num]; t[num]++)
    {
        b[num][t[num]] = k = Sixteen_to_ten(a[num][base + 3 * t[num] - 5]) * 16 * 16 + Sixteen_to_ten(a[num][base + 3 * t[num] - 4]) * 16 + Sixteen_to_ten(a[num][base + 3 * t[num] - 3]);
    } 
    }
    for(num = 1; num <= numm; num++)
    {
    printf("%o", b[num][1]);
    t[num] = 2;
    while(t[num] <= n[num])
    {printf("%.4o", b[num][t[num]]);
    t[num] ++;}
    printf("\n");
    }
    return 0;
}
