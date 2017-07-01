#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int min, max, i, j;
int If_Prime(int num)
{
	for(i = 2; i * i <= num && num % i != 0; i++);
	return i * i > num;
}
int If_Palindromic_Number(int num)
{
	int bit[100] = {0};
	for(i = 0; ; i++)
	{
		bit[i] = num % 10;
		num /= 10;
		if(num == 0)
			break;
	}
	for(j = 0; 2 * j <= i && bit[j] == bit[i - j]; j++);
	return 2 * j > i;
}
int main()
{
	scanf("%d%d", &min, &max);
	if(min < 2)
		min = 2;
	for(; min <= max; min++)
	{
		if(If_Palindromic_Number(min) && If_Prime(min))
			printf("%d ", min);
	}
	return 0;
}