#include<stdio.h>
int n, i = 0, j = 0, b[10][10] = {0}, num = 1, k;
int main()
{
	scanf("%d", &n);
	for(k = 0; k < (n + 1) / 2; k++)
	{
		for(; i < n - k; i++)
			b[i][j] = num++;
		i--;
		j++;
		for(; j < n - 2 * k; j++)
			b[i][j] = num++;
		j -= 2;
		i--;
		for(; i > 2 * k; i--, j--)
			b[i][j] = num++;
		i += 2;
		j++;
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j <= i; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
	return 0;
}
