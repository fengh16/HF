#include<stdio.h>
long int N, k, x, y;
int main()
{
	scanf("%ld", &N);
	for(k = 0; k * (2 * k + 1) < N; k++);
	k--;
	y = N - k * (2 * k + 1);
	if(y <= 2 * k + 1)
		x = 2 * k + 2 - y;
	else
	{
		x = y - 2 * k - 1;
		y = 2 * k + 3 - x;
	}
	printf("%ld/%ld", x, y);
	return 0;
}
