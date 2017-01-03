#include<stdio.h>
int n, m, a[50][100], ans[100] = { 0 }, i, j, b[100] = { 0 };
int main()
{
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	}
	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (a[i][j] != 0)
			{
				if (ans[j] == 0)
				{
					ans[j] = a[i][j];
					b[j] = i + 1;
				}
				else if (ans[j] >= a[i][j])
				{
					ans[j] = a[i][j];
					b[j] = i + 1;
				}
			}
		}
		printf("%d ", b[j]);
	}
	return 0;
}