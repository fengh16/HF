#include<stdio.h>
double lenth[3], cos[3];
char result[3][17] = {"Stable", "Almost Stable", "Not Stable"};
int i;
int main()
{
	for(i = 1; i <= 3; i++)
		scanf("%lf", &lenth[i - 1]);
	for(i = 1; lenth[i % 3] + lenth[(i + 1) % 3] - lenth[i - 1] > 0.0001 && i <= 3; i++);
	if(i == 4)
	{
		for(i = 1; i <= 3; i++)
			cos[i - 1] = (lenth[i % 3] * lenth[i % 3] + lenth[(i + 1) % 3] * lenth[(i + 1) % 3] - lenth[i - 1] * lenth[i - 1]) / lenth[i % 3] / lenth[(i + 1) % 3] / 2;
		for(i = 1; i <= 3; i++)
			printf("%c	%s\n", 'a' + i - 1, result[(lenth[i % 3] * cos[(i + 1) % 3] >= (5 / 4.0 *lenth[i - 1] - 0.001)) + (lenth[(i + 1) % 3] * cos[i % 3] >= (5 / 4.0 *lenth[i - 1] - 0.001)) + (lenth[i % 3] * cos[(i + 1) % 3] > 5 / 4.0 *lenth[i - 1]) + (lenth[(i + 1) % 3] * cos[i % 3] > 5 / 4.0 *lenth[i - 1])]);
	}
	else
		printf("The triangle don't exsit!");
	return 0;
}
