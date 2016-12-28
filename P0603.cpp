#include<stdio.h>
int num[10] = {0}, i, origin, ans, big, small;
int main()
{
	scanf("%d", &origin);
	do
	{
		ans = origin;
		big = small = 0;
		for(i = 1; i <= 4; i++)
		{
			num[origin % 10]++;
			origin /= 10;
		}
		for(i = 0; i <= 9; i++)
		{
			if(num[i] > 0)
			{
				small = small * 10 + i;
				num[i--]--;
			}
		}
		origin = ans;
		for(i = 1; i <= 4; i++)
		{
			num[origin % 10]++;
			origin /= 10;
		}
		for(i = 9; i >= 0; i--)
		{
			if(num[i] > 0)
			{
				big = big * 10 + i;
				num[i++]--;
			}
		}
		origin = big - small;
	}
	while(big - small != ans);
	printf("%d", ans);
	return 0;
}