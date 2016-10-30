#include<stdio.h>
int min, max, k, now, sec[10001][1000] = {0}, t, m;
int main()
{
	scanf("%d%d", &min, &max);
	for(m = min; m <= max; m++)
	{
		now = m;
		k = 2;
		t = 0;
		while(k <= now)
		{
			if(now % k == 0)
			{
				now /= k;
				sec[m - min][t] = k;
				k --;
				t ++;
			}
			k ++;
		}
	}
	for(m = min; m <= max; m++)
	{
		printf("%d=%d", m, sec[m - min][0]);
		t = 1;
		while(1)
		{
			if(sec[m - min][t] == 0)
				break;
			else
			{
				printf("*%d", sec[m - min][t]);
			}
			t++;
		}
		printf("\n");
	}
	return 0;
}
