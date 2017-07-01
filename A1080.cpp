//void calcF(int n, int m, int &fn, int &fn1)
//{
	int ft, ft1;
	if (n == 1)
	{
		fn1 = fn = 1;
		return;
	}
	if (n % 2)
	{
		calcF(n - 1, m, ft, ft1);
		fn1 = (ft + ft1) % m;
		fn = ft1;
		return;
	}
	else
	{
		calcF(n / 2, m, ft, ft1);
		fn1 = (ft1 * ft1 + ft * ft) % m;
		fn = (ft1 * ft + ft * (ft1 - ft + m)) % m;
		return;
	}
//}