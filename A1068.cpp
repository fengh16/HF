#include<stdio.h>
int m, n, i, t, ans[201][201], taken[201][201] = {1};
int main()
{
	scanf("%d%d", &m, &n);
	for(i = 0; i < m; i++)
	{
		for(t = 0; t < n; t++)
			scanf("%d", &ans[i][t]);
	}
	printf("%d ", ans[i = 0][t = 0]);
	while(1)
	{
		if((t + 1 >= n || taken[i][t + 1]) && (t == 0 || taken[i][t - 1]) && (i + 1 >= m || taken[i + 1][t]) && (i == 0 || taken[i - 1][t]))
			break;
		while(i + 1 < m && !taken[i + 1][t])
		{
			printf("%d ", ans[++i][t]);
			taken[i][t] = 1;
		}
		while(t + 1 < n && !taken[i][t + 1])
		{
			printf("%d ", ans[i][++t]);
			taken[i][t] = 1;
		}
		while(i > 0 && !taken[i - 1][t])
		{
			printf("%d ", ans[--i][t]);
			taken[i][t] = 1;
		}
		while(t > 0 && !taken[i][t - 1])
		{
			printf("%d ", ans[i][--t]);
			taken[i][t] = 1;
		}
	}
	return 0;
}