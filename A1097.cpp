//借鉴试题讨论区，两个人相遇之后转身相当于没有转身（相当于两个人换了一下）
#include <stdio.h>
int L, N, max, min, tmax, tmin, i, t;
int main()
{
	scanf("%d%d", &L, &N);
	if (N == 0)
		printf("0 0");
	else
	{
		scanf("%d", &t);
		max = t > L - t + 1 ? t : L - t + 1;
		min = t > L - t + 1 ? L - t + 1 : t;
		for (i = 1; i < N; i++)
		{
			scanf("%d", &t);
			tmax = t > L - t + 1 ? t : L - t + 1;
			tmin = t > L - t + 1 ? L - t + 1 : t;
			if (tmax > max)
				max = tmax;
			if (tmin > min)
				min = tmin;
		}
		printf("%d %d", min, max);
	}
	return 0;
}
/*根据题目要求按步骤写的，但明显超时
#include <stdio.h>
int L, N, max = -1, min = -1;
typedef struct A
{
	int Pos;
	int vel;
	int Turn;
}a;
a S[5001];
int Now[5001][2] = { 0 }, T[5001];
void Get()
{
	int i, num = N, t = 0;
	for (i = 0; i < N; i++)
	{
		S[i].Pos = T[i];
		if (S[i].vel < 0)
			Now[S[i].Pos][0]++;
		else
			Now[S[i].Pos][1]++;
		S[i].Turn = 0;
	}
	while (num)
	{
		t++;
		for (i = 0; i < N; i++)
		{
			if (S[i].Pos <= 0 || S[i].Pos > L)
				continue;
			if ((S[i].Pos < L - 1 && S[i].vel > 0 && ((Now[S[i].Pos + 1][0]) || (Now[S[i].Pos + 2][0]))) || (S[i].Pos > 1 && S[i].vel < 0 && ((Now[S[i].Pos - 1][1]) || (Now[S[i].Pos - 2][1]))))
				S[i].Turn = 1;
			else if ((S[i].Pos == L - 1 && S[i].vel > 0 && Now[S[i].Pos + 1][0]) || (S[i].Pos == 1 && S[i].vel < 0 && Now[S[i].Pos - 1][1]))
				S[i].Turn = 1;
		}
		for (i = 0; i < N; i++)
		{
			if (S[i].Pos <= 0 || S[i].Pos > L)
				continue;
			if (S[i].vel > 0)
			{
				if (S[i].Turn)
				{
					Now[S[i].Pos][1]--;
					S[i].vel = -1;
					S[i].Pos += S[i].vel;
					Now[S[i].Pos][0]++;
					S[i].Turn = 0;
				}
				else
				{
					Now[S[i].Pos][1]--;
					S[i].Pos += S[i].vel;
					Now[S[i].Pos][1]++;
				}
			}
			else
			{
				if (S[i].Turn)
				{
					Now[S[i].Pos][0]--;
					S[i].vel = 1;
					S[i].Pos += S[i].vel;
					Now[S[i].Pos][1]++;
					S[i].Turn = 0;
				}
				else
				{
					Now[S[i].Pos][0]--;
					S[i].Pos += S[i].vel;
					Now[S[i].Pos][0]++;
				}
			}
			if (S[i].Pos <= 0 || S[i].Pos > L)
				num--;
		}
	}
	if (t < min || min < 0)
		min = t;
	if (t > max)
		max = t;
}
void Try(int n)
{
	S[n].vel = 1;
	if (n == N - 1)
		Get();
	else
		Try(n + 1);
	S[n].vel = -1;
	if (n == N - 1)
		Get();
	else
		Try(n + 1);
}
int main()
{
	scanf("%d%d", &L, &N);
	int i;
	for (i = 0; i < N; i++)
		scanf("%d", &T[i]);
	Try(0);
	printf("%d %d", min, max);
	return 0;
}
*/