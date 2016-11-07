#include<stdio.h>
int f[21], i, sum[21] = {0};
int main()
{
	for(i = 1; i <= 20; i++)
	{
		if(i < 3)
			f[i] = 1;
		else
			f[i] = f[i - 1] + f[i - 2];
		sum[i] = sum[i - 1] + f[i];
	}
	scanf("%d", &i);
	do
	{
		printf("%d\n", sum[i]);
		scanf("%d", &i);
	}
	while(i != 0);
	return 0;
}
