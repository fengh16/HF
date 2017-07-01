#include<stdio.h>
int N, i;
long sum = 0;
long long int factorial(int);
long int c(int m, int n)
{
    return n == 0 ? 1 : factorial(m) / factorial(n) / factorial(m - n);
}
long long int factorial(int i)
{
    return i == 0 ? 1 : i * factorial(i - 1);
}
int main()
{
    scanf("%d", &N);
    for(i = 0; i <= N / 2; i++)
        sum += c(N - i, i);
    printf("%ld", sum);
    return 0;
}
