/*��һ��Ϊһ������k����ʾҪ�����ʽ��k�׵�����
�����ڶ���Ϊһ������n����ʾҪ�󵼵Ķ���ʽ����n�
�����������������ʽ�ĸ��������ÿһ��ռһ�У�����������a��b����ʾ����ʽ����a*x^b��һ�����b>=0��a��Ϊ0��
����n,k<=100������е�����ϵ�����ᳬ��int��Χ��*/
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