#include<stdio.h>
#include<string.h>
int N, i, n1, n2, n3, t, num_move;
long long int score[11];
char name[11][21];
int main()
{
	scanf("%d", &N);
	for(i = 1; i <= N; i++)
	{
		scanf("%s%d%d%d", &name[i], &n1, &n2, &n3);
		score[i] = n3 + (n2 + 200) *1000 + n1 * 100000;
		num_move = i;
		for(t = i - 1; t >= 1; t--)
		{
			if(score[t] < score[num_move])
			{
				score[0] = score[t];
				score[t] = score[num_move];
				score[num_move] = score[0];
				strcpy(name[0], name[t]);
				strcpy(name[t], name[num_move]);
				strcpy(name[num_move], name[0]);
				num_move = t;
			}
			else if(score[t] == score[num_move] && strcmp(name[t], name[num_move]) > 0)
			{
				score[0] = score[t];
				score[t] = score[num_move];
				score[num_move] = score[0];
				strcpy(name[0], name[t]);
				strcpy(name[t], name[num_move]);
				strcpy(name[num_move], name[0]);
				num_move = t;
			}
		}
	}
	for(i = 1; i <= N; i++)
		printf("%s\n", name[i]);
	return 0;
}
