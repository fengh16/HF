#include <stdio.h>
#include <stdlib.h>
int CaCulate(int **S, int n)
{
	int** A;
	int i, j, t, ans = 0;
	A = (int **)malloc((n - 1) * sizeof(int*));
	for (i = 0; i < n - 1; i++)
		A[i] = (int *)malloc((n - 1) * sizeof(int));
	if (n == 1)
		return S[0][0];
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			for (t = 0; t < n; t++)
			{
				if (t == i)
					continue;
				A[j - 1][t > i ? t - 1 : t] = S[j][t];
			}
		}
		if (i % 2 == 0)
			ans += CaCulate(A, n - 1) * S[0][i];
		else
			ans -= CaCulate(A, n - 1) * S[0][i];
	}
	for (i = 0; i < n - 1; i++)
		free(A[i]);
	free(A);
	return ans;
}
int main()
{
	int n, i, j;
	int ** S;
	scanf("%d", &n);
	S = (int **)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		S[i] = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &S[i][j]);
	}
	printf("%d", CaCulate(S, n));
	return 0;
}