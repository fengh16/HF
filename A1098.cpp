#include <stdio.h>
int NAll, m, i, t, A[15];
void Try(int n, int N, int i)
{
	int j, t;
	for (j = i; j <= N; j++)
	{
		A[n] = j;
		if (j == N)
		{
			printf("%d=%d", NAll, A[0]);
			for (t = 1; t <= n; t++)
				printf("+%d", A[t]);
			printf("\n");
		}
		else if (m == 1)
			Try(n + 1, N - j, 1);
		else
			Try(n + 1, N - j, j);
	}
}
int main()
{
	scanf("%d%d", &NAll, &m);
	Try(0, NAll, 1);
	return 0;
}