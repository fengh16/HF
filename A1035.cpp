#include<stdio.h>
int N, k, sum[1000] = {0}, t = 0, i;
int main()
{
	do
	{
		scanf("%d", &N);
		for(i = 2; i <= N; i++)
		{
			for(k = 2; k * k <= i && i % k != 0; k++);
			if(k * k > i)
			{
				sum[t] += i;
			}
		}
		t++;
	}
	while(N != 0);
	for(N = 0; N < t - 1; N++)
		printf("%d\n", sum[N]);
	return 0;
}
