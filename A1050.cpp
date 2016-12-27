#include<stdio.h>
int main()
{
	int cg = 0, sum = 0;
	char a;
	while(1)
	{
		a = getchar();
		if(a == 'C' || a == 'G')
		{
			cg++;
			sum++;
		}
		else if(a == 'A' || a== 'T')
			sum++;
		else
			break;
	}
	printf("%.0f", (double)cg * 100 / sum);
	return 0;
}
