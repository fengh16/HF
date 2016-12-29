#include<stdio.h>
int a, b, c, x, y;
int main()
{
	scanf("%d,%d,%d", &a, &b, &c);
	for(x = 1; x * a < c; x++)
	{
		for(y = x; x * a + y * b <= c; y++)
		{
			printf("%d,%d\n", x, y);
		}
	}
	return 0;
}