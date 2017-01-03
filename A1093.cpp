#include<stdio.h>
int main()
{
	int year;
	scanf("%d", &year);
	if(year % 400 && (year % 100 == 0 || year % 4))
		printf("no");
	else
		printf("yes");
	return 0;
}