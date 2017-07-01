#include<stdio.h>
int n, h[1001], a, i, t = -1;
int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &h[i]);
    }
    scanf("%d", &a);
    for (i = 1; i <= n && t == -1; i++)
    {
        if(a == h[i])
        {
            t = i;
        }
    }
    printf("%d", t);
    return 0;
}
