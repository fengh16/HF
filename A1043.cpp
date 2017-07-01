//在这道题里面，应该先从左右开始交换，把单数的移到最后换
#include<stdio.h>
#include<stdlib.h>
char *m, ch;
int i, letter[26] = {0}, n, ok = 1, t, step, k, ans = 0, t1, t2;
int Change(int from, int to)
{
	int Change = 0;
	if(from == to)
		return 0;
	if(from < to)
		step = 1;
	else
		step = -1;
	for(t = from; t != to; t += step)
	{
		ch = m[t];
		m[t] = m[t + step];
		m[t + step] = ch;
		Change++;
	}
	return Change;
}
int main()
{
	scanf("%d", &n);
	m = (char*)malloc((n + 1) * sizeof(char));
	scanf("%s", m);
	for(i = 0; i < n; i++)
	{
		letter[m[i] - 'a']++;
	}
	for(i = 0; i < 26; i++)
	{
		if(letter[i] % 2)
		{
			if(ok)
				ok = 0;
			else
				break;
		}
	}
	if(i < 26 || (!ok && n % 2 == 0))
	{
		printf("Impossible");
		return 0;
	}
	for(i = 0; i < n / 2; i++)
	{
		for(k = n - 1 - i; m[k] != m[i]; k--);
		if(k == i)
			break;
		ans += Change(k, n - 1 - i);
	}
	if(k == i)
	{
		for(i = n - 1 - i; i > n / 2; i--)
		{
			for(k = n - 1 - i; m[k] != m[i]; k++);
			ans += Change(k, n - 1 - i);
		}
	}
	printf("%d", ans);
	return 0;
}