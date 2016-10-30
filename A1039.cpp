#include<stdio.h>
int N, k, happy = 1, t;
long long int a[1001] = {0}, old, i;
int main()
{
	scanf("%d%lld", &N, &old);
	for(k = 1; k < N && happy; k++)
	{
		scanf("%lld", &i);
		if(i - old < N && i - old > -N)
		{
			t = i - old;
			t = t > 0? t: -t;
			if(t == 0)
				happy = 0;
			if(a[t])
				happy = 0;
			else
			{
				a[t]++;
				old = i;
			}
		}
		else
		{
			happy = 0;
			break;
		}
	}
	if(happy)
		printf("I'm happy!!");
	else
		printf("I'm unhappy!!");
	return 0;
}
