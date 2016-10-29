#include<stdio.h>
int Primenum[2001], n, i, Now, Reminder = 0, Divider;
long long sum;
int main()
{
    scanf("%d", &n);
    sum = Primenum[1] = 2;
    for(i = 2; i <= n; i++)
    {
        for(Now = Primenum[i - 1] + 1; Reminder == 0; Now++)
        {
            for(Divider = 1; Divider <= i - 1; Divider++)
            {
                Reminder = Now % Primenum[Divider];
                if (Reminder == 0) break;
            }
        }
        Now--;
        Primenum[i] = Now;
        sum += Now;
        Reminder = 0;
    }
    printf("%lld", sum);
    return 0;
}
