#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
double f(double x)
{
	return sin(x / 15);
}
double getRoot(double(*f)(double), double a, double b)
{
	double p = (a + b) / 2;
	if (-0.000001 < f(p) && f(p) < 0.000001)
		return p;
	else if (f(p) * f(a) > 0)
		return getRoot(f, p, b);
	else
		return getRoot(f, a, p);
}
int main()
{
	double k = getRoot(f, 1, 100);
	cout << k;
	return 0;
}