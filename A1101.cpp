#include <iostream>
using namespace std;
int main()
{
	int N, i, j, t;
	cin >> N >> i >> j;
	for (t = 1; t <= N; t++)
		cout << "(" << i << "," << t << ")";
	cout << endl;
	for (t = 1; t <= N; t++)
		cout << "(" << t << "," << j << ")";
	cout << endl;
	for (t = 1; t + j - i < 1; t++);
	for (; t + j - i <= N && t <= N; t++)
		cout << "(" << t << "," << (t + j - i) << ")";
	cout << endl;
	for (t = N; j + i - t <= 0; t--);
	for(; j + i - t <= N && t > 0; t--)
		cout << "(" << t << "," << (i + j - t) << ")";
	return 0;
}