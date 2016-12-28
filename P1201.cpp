#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int x, y, i;
long long A[7][1000000] = {0};
long long Caculate(int x, int y)
{
	int p;
	if(A[x][y] == 0)
	{
		if(x == 0)
			A[x][y] = y + 1;
		else if(y == 0)
			A[x][y] = Caculate(x - 1, 1);
		else
		{
			for(p = 0; p < y - 1 && A[x][p]; p++);
			for(; p <= y - 1; p++)
				Caculate(x, p);
			A[x][y] = Caculate(x - 1, Caculate(x, y - 1));
		}
	}
	return A[x][y];
}
int main()
{
	scanf("%d%d", &x, &y);
	printf("%lld", Caculate(x, y));
	return 0;
}