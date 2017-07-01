#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int *a, int n);

int n, *a, i, r;

int main()
{
	scanf("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
		scanf("%d", a + i);
	n = removeDuplicates(a, n);
	printf("%d\n", n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	free(a);
	return 0;
}

int removeDuplicates(int *a, int n)
{
	int m = n;
	for(i = 1, r = 1; i < n; i++)
	{
		if(a[i] == a[i - 1])
			m--;
		else
			a[r++] = a[i];
	}
	return m;
}