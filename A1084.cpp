#define PI 3.141592653589793238462643383279502884197169399
//位数一定要取够…………
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct MyC
{
	double R;
	double I;
}C;
C Wn(int n, C w, C WnM1)
{
	C ans;
	if (n == 0)
	{
		ans.R = 1;
		ans.I = 0;
		return ans;
	}
	else if (n == 1)
		return w;
	ans.I = w.R * WnM1.I + w.I * WnM1.R;
	ans.R = w.R * WnM1.R - w.I * WnM1.I;
	return ans;
}
C* Fourier(C* X, int n, C w)
{
	if (n == 1)
		return X;
	C w2 = Wn(2, w, w);
	C wt;
	C* p;
	C* q;
	C* ans;
	ans = (C*)malloc(n * sizeof(C));
	C* xp;
	C* xq;
	xp = (C*)malloc((n / 2) * sizeof(C));
	xq = (C*)malloc((n / 2) * sizeof(C));
	int i;
	for (i = 0; i < n; i++)
	{
		if (i % 2)
			xq[i / 2] = X[i];
		else
			xp[i / 2] = X[i];
	}
	p = Fourier(xp, n / 2, w2);
	//free(xp);不知为何不能free，会触发断点
	q = Fourier(xq, n / 2, w2);
	//free(xq);
	wt.R = 1;
	wt.I = 0;
	for (i = 0; i < n; i++)
	{
		wt = Wn(i, w, wt);
		ans[i].R = p[i % (n / 2)].R + Wn(2, wt, q[i % (n / 2)]).R;
		ans[i].I = p[i % (n / 2)].I + Wn(2, wt, q[i % (n / 2)]).I;
	}
	free(p);
	free(q);
	return ans;
}
int main()
{
	C* X;
	C* Y;
	C w;
	int n, i;
	scanf("%d", &n);
	X = (C*)malloc(n * sizeof(C));
	for (i = 0; i < n; i++)
		scanf("%lf%lf", &X[i].R, &X[i].I);
	w.R = cos(2 * PI / n);
	w.I = sin(2 * PI / n);
	Y = Fourier(X, n, w);
	for (i = 0; i < n; i++)
		printf("%.2lf %.2lf\n", Y[i].R / n, Y[i].I / n);
	return 0;
}