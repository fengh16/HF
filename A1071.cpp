#include <stdio.h>
#include <stdlib.h>
typedef struct STUDENT
{
	int num;
	int score;
}S;
S* Students;
int i, t, n, m, temp;
int main()
{
	scanf("%d%d", &n, &m);
	Students = (S*)malloc(n * sizeof(S));
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &Students[i].num, &Students[i].score);
		for (t = i - 1; t >= 0; t--)
		{
			if (Students[t + 1].score > Students[t].score || (Students[t + 1].score == Students[t].score && Students[t + 1].num < Students[t].num))
			{
				temp = Students[t + 1].num;
				Students[t + 1].num = Students[t].num;
				Students[t].num = temp;
				temp = Students[t + 1].score;
				Students[t + 1].score = Students[t].score;
				Students[t].score = temp;
			}
		}
	}
	m = m * 3 / 2;
	t = Students[m - 1].score;
	for (i = m; i < n && t == Students[i].score; i++);
	m = i;
	printf("%d %d\n", t, m);
	for (i = 0; i < m; i++)
		printf("%d %d\n", Students[i].num, Students[i].score);
	return 0;
}