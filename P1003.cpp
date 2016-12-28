#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	char MC[101];
	double DJ;
	int SL;
}order;
int main()
{
	int N, i;
	order* Orders;
	double ans = 0;
	scanf("%d", &N);
	Orders = (order*)malloc(N * sizeof(order));
	for(i = 0; i < N; i++)
	{
		scanf("%s%lf%d", Orders[i].MC, &Orders[i].DJ, &Orders[i].SL);
		ans += Orders[i].DJ * Orders[i].SL;
	}
	free(Orders);
	printf("%lf", ans);
	return 0;
}