#include<stdio.h>
double b[12] = {0}, A[12][11] = {0}, times, x[11];
int N, cross, row, t, h, error = 1;
int main()
{
    scanf("%d", &N);
    for(row = 1; row <= N; row++)
    {
        for(cross = 0; cross < N; cross++)
            scanf("%lf", &A[row][cross]);
    }
    for(row = 1; row <= N; row++)
        scanf("%lf", &b[row]);
    for(cross = 0; cross < N; cross++)
    {
        if(A[cross + 1][cross] <= 0.0000001 && A[cross + 1][cross] >= -0.0000001)
        {
            for(h = cross + 2; h <= N && A[h][cross] <= 0.0000001 && A[h][cross] >= -0.0000001; h++);
            for(t = 0; t < N; t++)
            {
                A[0][t] = A[cross + 1][t];
                A[cross + 1][t] = A[h][t];
                A[h][t] = A[0][t];
            }
            b[0] = b[cross + 1];
            b[cross + 1] = b[h];
            b[h] = b[0];
        }
        if(A[cross + 1][cross] <= 0.0000001 && A[cross + 1][cross] >= -0.0000001)
        {
            printf("Error");
            error = 0;
            break;
        }
        for(h = N; h > cross + 1; h--)
        {
            times = A[h][cross] / A[cross + 1][cross];
            for(t = 0; t < N; t++)
            {
                A[h][t] -= A[cross + 1][t] * times;
            }
            b[h] -= b[cross + 1] * times;
        }
    }
    if(error)
    {
        for(t = N - 1; t >= 0; t--)
        {
            x[t] = b[t + 1] / A[t + 1][t];
            for(h = t - 1; h >= 0; h--)
            {
                b[h + 1] -= A[h + 1][t] * x[t];
            }
        }
        for(t = 0; t < N; t++)
            printf("%.2lf\n", x[t]);
    }
    return 0;
}
