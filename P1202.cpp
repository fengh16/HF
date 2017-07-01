#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int x;
long long A[73] = {0, 1, 2, 4};
long long Caculate(int x)
{
	if(x <= 0)
		return 0;
	if(A[x] == 0)
	{
		A[x] = Caculate(x - 1) + Caculate(x - 2) + Caculate(x - 3);
	}
	return A[x];
}
int main()
{
	scanf("%d", &x);
	printf("%lld", Caculate(x));
	return 0;
}