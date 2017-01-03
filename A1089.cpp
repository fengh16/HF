#include <stdio.h>
#include <stdlib.h>
int N, ans[100000] = { 1 }, i, bit = 1, temp, t;
int main()
{
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		temp = 0;
		for (t = 0; t < bit; t++)
		{
			temp += i * ans[t];
			ans[t] = temp % 10;
			temp /= 10;
		}
		while (temp)
		{
			ans[bit++] = temp % 10;
			temp /= 10;
		}
	}
	for (i = bit - 1; i >= 0; i--)
		printf("%1d", ans[i]);
	return 0;
}