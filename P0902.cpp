#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int *a, n, sum, p, q;

int findTwoSum(int *a, int n, int sum);

int main()
{
	scanf("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	for(p = 0; p < n; p++)
	scanf("%d", a + p);
	scanf("%d", &sum);
	printf("%d", findTwoSum(a, n, sum));
	return 0;
}

int findTwoSum(int *a, int n, int sum)
{
	if(n < 2)
		return -1;
	for(p = 0; p < n; p++)
	{
		for(q = p + 1; q < n; q++)
		{
			if(a[p] + a[q] == sum)
				return 1;
		}
	}
	return -1;
}