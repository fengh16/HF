#include <iostream>
#include <stdlib.h>
using namespace std;
int m, n = 1, i, j, ok = 1;
int * used;
int ** Played;
void Try(int t)
{
	if (ok == 0)
		return;
	if (used[t] >= 0)
	{
		if (t == n - 1)
			return;
		else
			Try(t + 1);
	}
	int j;
	for (j = 0; j < n; j++)
	{
		if (j == t || used[j] >= 0 || Played[t][j])
			continue;
		used[j] = t;
		used[t] = j;
		if (t == n - 1)
		{
			ok = 0;
			return;
		}
		Try(t + 1);
		if (ok == 0)
			return;
	}
}
int main()
{
	cin >> m;
	while (m--)
		n *= 2;
	used = (int *)malloc(n * sizeof(int));
	Played = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
	{
		Played[i] = (int *)malloc(n * sizeof(int));
		for (j = 0; j < n; j++)
			Played[i][j] = 0;
		used[i] = -1;
	}
	for (j = 1; j < n; j++)
	{
		ok = 1;
		Try(0);
		for (i = 0; i < n; i++)
			Played[i][used[i]] = 1;
		cout << "<" << j << ">";
		for (i = 0; i < n; i++)
		{
			if (used[i] < 0)
				continue;
			cout << i + 1 << "-" << used[i] + 1 << " ";
			used[used[i]] = -1;
			used[i] = -1;
		}
		cout << endl;
	}
	return 0;
}