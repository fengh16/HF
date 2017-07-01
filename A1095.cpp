#include <stdio.h>
int Room[9] = { 0, 120, 40, 85, 50, 100, 140, 70, 100 }, N[4], i, ok = 0, People[4];
void Try(int n)
{
	int i, t;
	for (i = 1; i < 9; i++)
	{
		if (Room[i] < People[n])
			continue;
		for (t = 0; t < n && N[t] != i; t++);
		if (t < n)
			continue;
		N[n] = i;
		if (n == 3)
		{
			ok = 1;
			for (t = 0; t < 4; t++)
				printf("%d ", N[t]);
			printf("\n");
		}
		else
			Try(n + 1);
	}
}
int main()
{
	for (i = 0; i < 4; i++)
		scanf("%d", &People[i]);
	Try(0);
	if (!ok)
		printf("-1");
	return 0;
}