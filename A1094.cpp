#include <stdio.h>
int a, b, c, d, times = 1;
//我感觉应该times从0开始啊
double f(double z)
{
	return a * z * z * z + b * z * z + c * z + d;
}
double fp(double z)
{
	return 3 * a * z * z + 2 * b * z + c;
}
double GetRoot(double z)
{
	times++;
	double t = z - f(z) / fp(z);
	if (f(t) > -0.0000001 && f(t) < 0.0000001)
		return t;
	else
		return GetRoot(t);
}
int main()
{
	double z, ans;
	scanf("%d%d%d%d%lf", &a, &b, &c, &d, &z);
	ans = GetRoot(z);
	printf("%.3f %d", ans, times);
	return 0;
}