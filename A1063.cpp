#include<stdio.h>
long long n, x0, xn = 1, i, ans = 0, a;
int main()
{
	scanf("%lld%lld%lld", &n, &x0, &a);
	for(i = 1; i <= n; i++)
	{
		scanf("%lld", &a);
		ans += xn * a * i;
		ans %= 9999;
		if(ans < 0)
			ans = (ans + 9999 * (-ans / 9999 + 3)) % 9999;
		xn *= x0;
		xn %= 9999;
		if(xn < 0)
			xn = (xn + 9999 * (-xn / 9999 + 3)) % 9999;
	}
	if(ans < 0)
		ans = (ans + 9999 * (-ans / 9999 + 3)) % 9999;
	printf("%lld", ans);
	return 0;
}