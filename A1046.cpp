#include<stdio.h>
char a;
int i, num = 0, ans = 0, p_or_m = 1;
int main()
{
	while(1)
	{
		a = getchar();
		if(a == '+')
		{
			ans += p_or_m * num;
			p_or_m = 1;
			num = 0;
		}
		else if(a == '-')
		{
			ans += p_or_m * num;
			p_or_m = -1;
			num = 0;
		}
		else if(a == '=')
		{
			ans += p_or_m * num;
			printf("%d", ans);
			break;
		}
		else if(a >= '0' && a <= '9')
			num = num * 10 + a - '0';
		else
			continue;
	}
	return 0;
}
