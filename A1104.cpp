#include <iostream>
using namespace std;
int a[6], ans[1001] = { 0 }, i, j, w[6] = { 1, 2, 3, 5, 10, 20 }, num = 0, use[6];
void Ca()
{
	int j, get = 0;
	for (j = 0; j < 6; j++)
		get += use[j] * w[j];
	if (get == 0 || ans[get])
		return;
	ans[get] = 1;
	num++;
}
void Try(int k)
{
	for (use[k] = 0; use[k] <= a[k]; use[k]++)
	{
		if (k == 5)
			Ca();
		else
			Try(k + 1);
	}
}
int main()
{
	for (i = 0; i < 6; i++)
		cin >> a[i];
	Try(0);
	cout << "Total=" << num;
	return 0;
}