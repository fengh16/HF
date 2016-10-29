#include<stdio.h>
long int a, b, z, ans, a1, b1;
int main()
{
    scanf("%ld%ld%ld", &a, &b, &z);
    switch(z)
    {
    case 1:
        ans = a + b;
        break;
    case 2:
        ans = a - b;
        break;
    case 3:
        ans = a * b;
        break;
    case 4:
        ans = a / b;
        break;
    case 5:
        ans = a % b;
        break;
    case 6:
        while(a != 0 && b != 0)
        {
            a = a % b;
            if(a != 0)
                b = b % a;
        }
        ans = a == 0? b : a;
        break;
    case 7:
        a1 = a; b1 = b;
        while(a != 0 && b != 0)
        {
            a = a % b;
            if(a != 0)
                b = b % a;
        }
        ans = a == 0? b : a;
        ans = a1 * b1 / ans;
    }
    printf("%ld", ans);
    return 0;
}
