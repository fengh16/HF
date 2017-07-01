#include<stdio.h>
int main()
{
	long m;
	int i, sum = 0;
	scanf("%ld", &m);
	for(i = 1; i * i < m; i++)
	{
		if(m % i == 0)
			sum += 2;
	}
	if(i * i == m)
		sum++;
	printf("%d", sum);
	return 0;
}