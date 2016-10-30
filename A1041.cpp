#include<stdio.h>
int n, A[30][30] = {0}, m, B[30][30] = {0}, i, j, C[30][30], k;
int main()
{
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	}
	switch(m)
	{
	case 0:
		for(i = 0; i < n; i++)
			B[i][i] = 1;
		break;
	default:
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
				C[i][j] = B[i][j] = A[i][j];
		}
		for(; m > 1; m--)
		{
			for(i = 0; i < n; i++)
			{
				for(j = 0; j < n; j++)
				{
					B[i][j] = 0;
					for(k = 0; k < n; k++)
					B[i][j] += A[i][k] * C[k][j];
				}
			}
			for(i = 0; i < n; i++)
			{
				for(j = 0; j < n; j++)
					C[i][j] = B[i][j];
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("%d ", B[i][j]);
		printf("\n");
	}
	return 0;
}
