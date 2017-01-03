#include <stdio.h>
int n, i, S[30], j, ans = 0;
int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &S[i]);
	}
	for (j = n - 1; j >= 0; j--)
	{
		ans += S[j];
		for (i = 0; i < j; i++)
		{
			S[i] = S[i + 1] - S[i];
		}
	}
	printf("%d", ans);
	return 0;
}