#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int m, n, a[11], b[11], result[21], ia, ib, ir;
void merge(int *a, int *b , int m, int n, int *result);
int main()
{
	scanf("%d", &m);
	for(ia = 0; ia < m; ia++)
		scanf("%d", &a[ia]);
	scanf("%d", &n);
	for(ib = 0; ib < n; ib++)
		scanf("%d", &b[ib]);
	merge(a, b , m, n, result);
	for(ir = 0; ir < m + n; ir++)
		printf("%d ", result[ir]);
	return 0;
}
void merge(int *a, int *b , int m, int n, int *result)
{
	for(ia = 0, ib = 0, ir = 0; ia < m && ib < n; )
	{
		if(a[ia] <= b[ib])
			result[ir++] = a[ia++];
		else
			result[ir++] = b[ib++];
	}
	while(ia < m)
		result[ir++] = a[ia++];
	while(ib < n)
		result[ir++] = b[ib++];
}