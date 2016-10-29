#include<stdio.h>
int a[201], n_a, i, Num_Compare, Num_Move;
int main()
{
    scanf("%d", &n_a);
    for(i = 1; i <= n_a; i++)
    {
        scanf("%d", &a[i]);
        for(Num_Compare = 1; Num_Compare < i;)
        {
            if (a[Num_Compare] >= a[i]) break;
            Num_Compare ++;
        }
        if (Num_Compare < i)
        {
            a[0] = a[i];
            for(Num_Move = i ; Num_Move >= Num_Compare + 1; Num_Move --)
            {
                a[Num_Move] = a[Num_Move - 1];
            }
            a[Num_Compare] = a[0];
        }
    }
    for(i = 1; i <= n_a; i++)
        printf("%d ", a[i]);
    return 0;
}
