#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int lenth[51] = {0}, i = 0;
char ch;
int main()
{
	while(1)
	{
		ch = getchar();
		if((ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a'))
			lenth[i]++;
		else if(ch == '-' || ch == '*')
		{
			if(lenth[i])
				i++;
			continue;
		}
		else
			break;
	}
	scanf("%d", &i);
	printf("%d", lenth[i - 1]);
	return 0;
}