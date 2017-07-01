#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int now = 0, ans, i = 0, decide = 1;
char s[200], ch;
int expression(char* s);
int main()
{
	gets(s);
	ans = expression(s);
	printf("%d", ans);
	return 0;
}
int expression(char* s)
{
	while(1)
	{
		ch = s[i++];
		if(ch >= '0' && ch <= '9')
			now = now * 10 + ch - '0';
		else if(ch == '+')
		{
			ans += now * decide;
			now = 0;
			decide = 1;
		}
		else if(ch == '-')
		{
			ans += now * decide;
			now = 0;
			decide = -1;
		}
		else if(ch == '=')
		{
			ans += now * decide;
			return ans;
		}
		else
			continue;
	}
}
