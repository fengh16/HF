#include <iostream>
using namespace std;
/*
��ȡn��Լ��������
Լ��n>=1
*/
int getNumDivisor(int n)
{
	int i, j = 0;
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
			j++;
	}
	return j;
}
int main()
{
	int n;
	cin >> n;
	cout << getNumDivisor(n) << endl;
	return 0;
}