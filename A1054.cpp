#include<stdio.h>
int main()
{
	long long int p, i, m;
	scanf("%lld", &p);
	for(i = p + 1; ; i++)
	{
		for(m = 2; m < i && i % m; m++);
		if(m == i)
			break;
	}
	printf("%lld", i);
	return 0;
}