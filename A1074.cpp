#include <stdio.h>
int main()
{
	int A[100][100], X[100], ans[100] = { 0 }, i, t, j, N;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		for (t = 0; t < N; t++)
		{
			scanf("%d", &A[i][t]);
		}
	}
	for (i = 0; i < N; i++)
	{
		scanf("%d", &X[i]);
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			ans[i] += X[j] * A[i][j];
		}
	}
	for (i = 0; i < N; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}