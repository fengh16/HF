#include <stdio.h>
int main()
{
	int a, b, ans;
	scanf("%d%d", &a, &b);
	ans = a * b;
	printf("%4d\n*%3d\n----\n", a, b);
	if (b < 10)
		printf("%4d", ans);
	else
	{
		printf("%4d\n%3d\n----\n%4d", a * (b % 10), a * (b / 10), ans);
	}
	return 0;
}