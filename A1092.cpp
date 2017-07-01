#include <stdio.h>
char num[5], ch;
int main()
{
	int i;
	scanf("%s", num);
	for (i = 0; i < 4; i++)
	{
		if (num[i] >= '5')
			num[i] -= 5;
		else
			num[i] += 5;
	}
	ch = num[0];
	num[0] = num[3];
	num[3] = ch;
	ch = num[1];
	num[1] = num[2];
	num[2] = ch;
	for (i = 0; i < 4 && num[i] == '0'; i++);
	printf("%s", num + i);
	return 0;
}