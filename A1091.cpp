#include <stdio.h>
int n, m, ans[12];
void Try(int t)
{
	int i, j;
	if (t == 0)
		i = 1;
	else
		i = ans[t - 1] + 1;
	for (; i < n - m + t + 2; i++)
	{
		ans[t] = i;
		if (t == m - 1)
		{
			for (j = 0; j < m; j++)
			{
				printf("%d ", ans[j]);
			}
			printf("\n");
		}
		else
			Try(t + 1);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	Try(0);
	return 0;
}