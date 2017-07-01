#include <stdio.h>
int A[100][100], i, j, n;
int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", A[i][j] + A[j][i]);
		}
		printf("\n");
	}
	return 0;
}