#include<stdio.h>
int n_old = 0, n_new = 1, N, num_old, num_new, now;
int main()
{
    scanf("%d%d", &N, &num_new);
    num_old = num_new;
    for(; N > 1; N--)
    {
        scanf("%d", &now);
        if(now == num_new)
        {
            n_new ++;
            if(n_new > n_old)
                num_old = num_new;
        }
        else
            num_new = now;
            n_old = (n_new > n_old? n_new: n_old);
    }
    printf("%d", num_old);
    return 0;
}
