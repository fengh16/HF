/*数据不会超过1000，但结果可能会超过1000*/
#include <stdio.h>
int num[80001] = { 0 }, i, n, t;
long long ans;
int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &ans);
		num[ans]++;
	}
	ans = 0;
	while (--n)
	{
		for (i = 0; num[i] == 0; i++);
		ans += i;
		t = i;
		num[i]--;
		for (; num[i] == 0; i++);
		ans += i;
		t += i;
		num[i]--;
		num[t]++;
	}
	printf("%lld", ans);
	return 0;
}