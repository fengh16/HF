#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char s1[11], s2[11], result[21];
int i1, i2, i, t, j, temp = 0;
void multiply(char* s1, char* s2, char* result);
int main()
{
	scanf("%s%s", s1, s2);
	multiply(s1, s2, result);
	printf("%s", result);
	return 0;
}
void multiply(char* s1, char* s2, char* result)
{
	for(i1 = 0; s1[i1] != 0; i1++);
	for(i2 = 0; s2[i2] != 0; i2++);
	i = 0;
	for(t = 0; t < i1 + i2 - 1; t++)
	{
		for(j = 0; j <= t; j++)
		{
			if(j < i1 && (t - j) < i2)
				temp += (s1[i1 - 1 - j] - '0') * (s2[i2 - 1 - t + j] - '0');
		}
		result[i++] = (temp % 10 + '0');
		temp /= 10;
	}
	while(temp > 0)
	{
		result[i++] = (temp % 10 + '0');
		temp /= 10;
	}
	result[i] = 0;
	for(j = 0; j <= (i - 1) / 2; j++)
	{
		temp = result[j];
		result[j] = result[i - 1 - j];
		result[i - 1 - j] = temp;
	}
}