#include <iostream>
using namespace std;
int main()
{
	int a, b, j;
	cin >> a >> b;
	int i, t = 0;
	for (i = 1; i <= a && i <= b; i++)
		t += (a - i + 1) * (b - i + 1);
	int ans = 0;
	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= b; j++)
		{
			if (i == j)
				continue;
			ans += (a - i + 1) * (b - j + 1);
		}
	}
	cout << t << " "<<ans<<endl;
	return 0;
}