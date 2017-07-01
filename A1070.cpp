/*第一行为一个整数k，表示要求多项式的k阶导数。
　　第二行为一个整数n，表示要求导的多项式含有n项。
　　接下来输入多项式的各个非零项，每一项占一行，含两个整数a、b，表示多项式含有a*x^b这一项，其中b>=0，a不为0。
　　n,k<=100，结果中的所有系数不会超过int范围。*/
#include<stdio.h>
int k, n, i, j, m;
int num[101][2] = {0};
int main()
{
	scanf("%d%d", &k, &n);
	for(i = 0; i < n; i++)
		scanf("%d%d", &num[i][0], &num[i][1]);
	for(i = 0; i < k; i++)
	{
		for(j = 0; j < n; j++)
		{
			num[j][0] = num[j][0] * num[j][1];
			num[j][1] = num[j][1] - 1;
		}
	}
	printf("f");
	for(i = 0; i < k; i++)
		printf("'");
	printf("(x)=");
	for(i = 0; i < n && num[i][0] == 0; i++);
	if(num[i][0])
	{
		if(num[0][1] > 1)
			printf("%d*x^%d", num[0][0], num[0][1]);
		else if(num[0][1] == 1)
			printf("%d*x", num[0][0]);
		else
			printf("%d", num[0][0]);
		i++;
		for(; i < n; i++)
		{
			if(num[i][1] == 0)
			{
				if(num[i][0] > 0)
					printf("+%d", num[i][0], num[i][1]);
				else if(num[i][0] < 0)
					printf("%d", num[i][0], num[i][1]);
			}
			else if(num[i][1] > 1)
			{
				if(num[i][0] > 0)
					printf("+%d*x^%d", num[i][0], num[i][1]);
				else if(num[i][0] < 0)
					printf("%d*x^%d", num[i][0], num[i][1]);
			}
			else
			{
				if(num[i][0] > 0)
					printf("+%d*x", num[i][0]);
				else if(num[i][0] < 0)
					printf("%d*x", num[i][0]);
			}
		}
	}
	else
		printf("0");
	return 0;
}