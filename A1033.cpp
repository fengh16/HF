#include<stdio.h>
int a[30][30], i_x, i_y, k = 1, n, t;
int main()
{
    scanf("%d", &n);
    for(t = 0; t <= (n - 1) / 2; t++)
    {
        i_y = t;
        for(i_x = t; i_x <= n - 1 - t; i_x++)
            a[i_x][i_y] = k++;
        i_x--;
        for(i_y = t + 1; i_y <= n - 1 - t; i_y++)
            a[i_x][i_y] = k++;
        i_y--;
        for(i_x = n - 2 - t; i_x >= t; i_x--)
            a[i_x][i_y] = k++;
        i_x++;
        for(i_y = n - 2 - t; i_y >= t + 1; i_y--)
            a[i_x][i_y] = k++;
    }
    for(i_y = 0; i_y <= n - 1; i_y++)
    {
        for(i_x = 0; i_x <= n - 1; i_x++)
            printf("%d ", a[i_x][i_y]);
        printf("\n");
    }
    return 0;
}
