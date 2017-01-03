#include<stdio.h>
int s, t, a, b, c, d, i, ans[10001] = {0};
int F[10001];
int CaF(int p, int m)
{
	if(F[p] >= 0)
		return F[p];
	if(p < 3)
		return F[p] = 1;
	else
		return F[p] = (CaF(p - 1, m) + CaF(p - 2, m)) % m;
}
int main()
{
	scanf("%d%d%d%d%d%d", &s, &t, &a, &b, &c, &d);
	for(i = 1; i <= t; i++)
	{
		F[i] = -1;
		if(CaF(i, a))
			ans[i] = 1;
	}
	for(i = 1; i <= t; i++)
	{
		F[i] = -1;
		if(!CaF(i, b))
			ans[i] = 0;
	}
	for(i = 1; i <= t; i++)
	{
		F[i] = -1;
		if(!CaF(i, c))
			ans[i] = 0;
	}
	for(i = 1; i <= t; i++)
	{
		F[i] = -1;
		if(!CaF(i, d))
			ans[i] = 0;
	}
	for(i = s; i <= t; i++)
	{
		if(ans[i])
			printf("%d ", i);
	}
	return 0;
}