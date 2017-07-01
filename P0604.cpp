#include<stdio.h>
int num[8] = {0}, i = 0, t, right = 1, k, p = 1;
char c;
int main()
{
	while(right)
	{
		c = getchar();
		if(c >= '1' && c <= '9')
		{
			num[i] = c - '0';
			for(t = 0; t < i; t++)
			{
				if(num[t] == num[i])
				{
					right = 0;
					break;
				}
			}
			i++;
		}
		else
			break;
	}
	t = 0;
	while(right)
	{
		k = (t + num[t]) % i;
		if(k == 0)
		{
			if(p != i)
				right = 0;
			break;
		}
		if(num[k] == 0)
		{
			right = 0;
			break;
		}
		p++;
		num[t] = 0;
		t = k;
	}
	if(right)
		printf("yes");
	else
		printf("no");
	return 0;
}