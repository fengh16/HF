#define NOQUEEN 0
#define BLACK 1
#define WHITE 2
#include<stdio.h>
#include<stdlib.h>
typedef struct POS
{
	int CanPlace;
	int Exist;
}pos;
int N, ans = 0;
pos**Now;
int* CrossTaken[2];
int* diagonal[2];
int* Diagonal[2];
int CanPlaceNow(int x, int y, int Type)
{
	int i;
	if (Now[x][y].CanPlace && Now[x][y].Exist == NOQUEEN)
	{
		if (!CrossTaken[Type - 1][y] && !diagonal[Type - 1][x - y + N - 1] && !Diagonal[Type - 1][x + y])
			return 1;
	}
	return 0;
}
void Place(int x, int y, int Type)
{
	Now[x][y].Exist = Type;
	CrossTaken[Type - 1][y] = 1;
	diagonal[Type - 1][x - y + N - 1] = 1;
	Diagonal[Type - 1][x + y] = 1;
}
void GetAway(int x, int y)
{
	int Type = Now[x][y].Exist;
	Now[x][y].Exist = 0;
	CrossTaken[Type - 1][y] = 0;
	diagonal[Type - 1][x - y + N - 1] = 0;
	Diagonal[Type - 1][x + y] = 0;
}
void Try(int n)
{
	int iw, ib;
	//int i, m;//Debug
	for (iw = 0; iw < N; iw++)
	{
		if (!CanPlaceNow(n, iw, WHITE))
			continue;
		for (ib = 0; ib < N; ib++)
		{
			if (ib == iw || !CanPlaceNow(n, ib, BLACK))
				continue;
			Place(n, iw, WHITE);
			Place(n, ib, BLACK);
			if (n == N - 1)
			{
				ans++;
				//printf("%d\n", ans);
				//for (i = 0; i < N; i++)
				//{
				//	for (m = 0; m < N; m++)
				//	{
				//		printf("%d ", Now[i][m].Exist);
				//	}
				//	printf("\n");
				//}
				//printf("--------------------------\n\n");
			}
			else
				Try(n + 1);
			GetAway(n, iw);
			GetAway(n, ib);
		}
	}
}
int main()
{
	int i, m;
	scanf("%d", &N);
	Now = (pos**)malloc(N * sizeof(pos*));
	CrossTaken[0] = (int *)malloc(N * sizeof(int));
	CrossTaken[1] = (int *)malloc(N * sizeof(int));
	diagonal[0] = (int *)malloc((2 * N - 1) * sizeof(int));
	diagonal[1] = (int *)malloc((2 * N - 1) * sizeof(int));
	Diagonal[0] = (int *)malloc((2 * N - 1) * sizeof(int));
	Diagonal[1] = (int *)malloc((2 * N - 1) * sizeof(int));
	for (i = 0; i < N; i++)
	{
		Now[i] = (pos*)malloc(N * sizeof(pos));
		for (m = 0; m < N; m++)
		{
			scanf("%d", &Now[i][m].CanPlace);
			Now[i][m].Exist = NOQUEEN;
		}
		CrossTaken[0][i] = 0;
		CrossTaken[1][i] = 0;
	}
	for (i = 0; i < 2 * N - 1; i++)
	{
		diagonal[0][i] = 0;
		diagonal[1][i] = 0;
		Diagonal[0][i] = 0;
		Diagonal[1][i] = 0;
	}
	Try(0);
	printf("%d", ans);
	return 0;
}