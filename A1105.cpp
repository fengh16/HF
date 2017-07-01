#include <iostream>
#include <stdlib.h>
using namespace std;
int N, total = 0, getnum = 0;
int * num;
int * used;
int * ans;
int ** Through;
int * Get;
void Try(int k)
{
	int i, j, t, b;
	for (i = 0; i < N; i++)
	{
		if (used[i])
			continue;
		if (k > 0 && !Through[ans[k - 1]][i])
			continue;
		ans[k] = i;
		used[i] = 1;
		total += num[i];
		for (j = 0; j < N && (used[j] || !Through[j][i]); j++);
		if (j == N)
		{
			if (total > getnum)
			{
				getnum = total;
				for (b = 0; b <= k; b++)
					Get[b] = ans[b];
				Get[b] = -1;
			}
		}
		else
			Try(k + 1);
		used[i] = 0;
		total -= num[i];
	}
}
int main()
{
	int i, j, b;
	cin >> N;
	num = (int *)malloc(N * sizeof(int));
	used = (int *)malloc(N * sizeof(int));
	ans = (int *)malloc(N * sizeof(int));
	Get = (int *)malloc(N * sizeof(int));
	Through = (int **)malloc(N * sizeof(int *));
	for (i = 0; i < N; i++)
	{
		Through[i] = (int *)malloc(N * sizeof(int));
		cin >> num[i];
		used[i] = 0;
	}
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			cin >> Through[i][j];
			Through[j][i] = Through[i][j];
		}
	}
	Try(0);
	cout << Get[0] + 1;
	for (b = 1; Get[b] >= 0; b++)
		cout << "-" << Get[b] + 1;
	cout << "\nMAX=" << getnum;
	return 0;
}