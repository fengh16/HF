#include <stdio.h>
int k, ans[22], p = 0;
void Try(int n)
{
	int i, j;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < n && ans[j] != i; j++);
		if (j < n)
			continue;
		if (n == 1 && ans[0] == i)
			continue;
		else if (n > 1)
		{
			if ((ans[n - 2] - ans[n - 1]) * (ans[n - 2] - i) > 0)
				continue;
		}
		ans[n] = i;
		Try(n + 1);
	}
	if (n >= 2)
	{
		p++;
	}
}
int main()
{
	scanf("%d", &k);
	Try(0);
	printf("%d", p);
	return 0;
}