#include <stdio.h>
int N, a[100], i, j, ans = 0;
int main()
{
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (a[i] > a[j])
				ans++;
		}
	}
	printf("%d", ans);
	return 0;
}