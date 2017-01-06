#include <iostream>
#include <stdlib.h>
#define LongNumMax 500
using namespace std;
struct LongNum //从个位开始，即0代表的是个位，之后逐次递增，遇到最高位之后都是-1
{
	int Num[LongNumMax];
};
LongNum LPlus(LongNum a, int temp)
{
	LongNum ans;
	int i;
	for (i = 0; i < LongNumMax; i++)
	{
		if (a.Num[i] >= 0)
			temp += a.Num[i];
		else if (temp == 0)
			break;
		ans.Num[i] = temp % 10;
		temp /= 10;
	}
	for (; i < LongNumMax; i++)
		ans.Num[i] = -1;
	return ans;
}
LongNum LPlus(LongNum a, LongNum b)
{
	LongNum ans;
	int i, temp = 0;
	for (i = 0; i < LongNumMax; i++)
	{
		if (a.Num[i] >= 0 && b.Num[i] >= 0)
			temp += a.Num[i] + b.Num[i];
		else if (a.Num[i] >= 0)
			temp += a.Num[i];
		else if (b.Num[i] >= 0)
			temp += b.Num[i];
		else if (temp == 0)
			break;
		ans.Num[i] = temp % 10;
		temp /= 10;
	}
	for (; i < LongNumMax; i++)
		ans.Num[i] = -1;
	return ans;
}
LongNum LMulti(LongNum a, int b, int from = 0)
{
	LongNum ans;
	int i, temp = 0;
	for (i = from; i < LongNumMax; i++)
	{
		if (a.Num[i] >= 0)
			temp += a.Num[i] * b;
		else if (temp == 0)
			break;
		ans.Num[i] = temp % 10;
		temp /= 10;
	}
	for (; i < LongNumMax; i++)
		ans.Num[i] = -1;
	return ans;
}
LongNum LMulti(LongNum a, LongNum b)
{
	LongNum ans;
	int i;
	for (i = 0; i < LongNumMax; i++)
		ans.Num[i] = -1;
	for (i = 0; i < LongNumMax && b.Num[i] >= 0; i++)
		ans = LPlus(ans, LMulti(a, b.Num[i], i));
	return ans;
}
int main()
{
	int i, N;
	cin >> N;
	LongNum ans, F;
	ans.Num[0] = 1;
	F.Num[0] = 1;
	for (i = 1; i < LongNumMax; i++)
	{
		ans.Num[i] = -1;
		F.Num[i] = -1;
	}
	for (i = 2; i <= N; i++)
		ans = LPlus(ans, F = LMulti(F, i));
	for (i = 0; ans.Num[i] >= 0; i++);
	while (i--)
		cout << ans.Num[i];
	return 0;
}