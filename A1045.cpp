#include<stdio.h>
int t, N, M, num[10001], i, x, y;
int main()
{
	scanf("%d", &t);
	for(; t >= 1; t--)
	{
		scanf("%d%d", &N, &M);
		for(i = 1; i <= N; i++)
		{
			scanf("%d", &num[i]);
		}
		for(i = 1; i <= M; i++)
		{
			scanf("%d%d", &x, &y);
			num[0] = num[x];
			num[x] = num[y];
			num[y] = num[0];
		}
		for(i = 1; i <= N; i++)
			printf("%d\n", num[i]);
	}
	return 0;
}
