#include<stdio.h>
int h, num_3, num_2;
long long sum = 0;
long long int factorial(int a)
{
	if(a == 0 || a == 1)
		return 1;
	else
		return factorial(a - 1) * a;
}
long long int c(int a, int b)
{
	return factorial(a) / factorial(b) / factorial(a - b);
}
int main()
{
	scanf("%d", &h);
	if(h >= 4 && h <= 20)
	{
		for(num_3 = 0; num_3 * 3 <= h; num_3 ++)
		{
			for(num_2 = 0; num_2 * 2 + num_3 * 3 <= h; num_2 ++)
			{
				sum += c(h - num_2 - num_3 * 3, num_2) * c(h - num_2 - num_3 * 2, num_3);
			}
		}
		printf("%ld", sum);
	}
	else
		printf("0");
	return 0;
}
