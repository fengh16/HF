#include <stdio.h>
int K, ans[4][4], num = 0, used[17] = { 0 };
int Can(int i, int num)
{
	int t;
	if (i % 4 == 3)
	{
		if (ans[i / 4][0] + ans[i / 4][1] + ans[i / 4][2] + num != 34)
			return 0;
	}
	if (i / 4 == 3)
	{
		if (ans[0][i % 4] + ans[1][i % 4] + ans[2][i % 4] + num != 34)
			return 0;
	}
	if (i == 12)
	{
		if (ans[0][3] + ans[1][2] + ans[2][1] + num != 34)
			return 0;
	}
	if (i == 15)
	{
		if (ans[0][0] + ans[1][1] + ans[2][2] + num != 34)
			return 0;
	}
	return 1;
}
void Try(int n)
{
	int i, j, t;
	for (i = 1; i < 17; i++)
	{
		if (used[i])
			continue;
		if (Can(n, i))
		{
			*(&ans[0][0] + n) = i;
			used[i] = 1;
			if (n == 15)
			{
				num++;
				if (num == K)
				{
					for (t = 0; t < 4; t++)
					{
						for (j = 0; j < 4; j++)
							printf("%d ", ans[t][j]);
						printf("\n");
					}
				}
			}
			else
				Try(n + 1);
			used[i] = 0;
		}
		else
			continue;
		if (num >= K)
			break;
	}
}
int main()
{
	scanf("%d", &K);
	Try(0);
	return 0;
}