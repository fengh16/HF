#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char a[21], * ans;

char * RegularPlural(char a[])
{
	int len;
	char * ans;

	len = strlen(a);
	ans = (char*)malloc((len + 3) * sizeof(char));
	strcpy(ans, a);
	switch(ans[len - 1])
	{
	case 's':
	case 'x':
	case 'z':
		ans[len] = 'e';
		ans[len + 1] = 's';
		ans[len + 2] = 0;
		break;
	case 'h':
		if(ans[len - 2] == 'c' || ans[len - 2] == 's')
		{
			ans[len] = 'e';
			ans[len + 1] = 's';
			ans[len + 2] = 0;
		}
		else
		{
			ans[len] = 's';
			ans[len + 1] = 0;
		}
		break;
	case 'y':
		if(!(ans[len - 2] == 'a' || ans[len - 2] == 'e' || ans[len - 2] == 'i' || ans[len - 2] == 'o' || ans[len - 2] == 'u'))
		{
			ans[len - 1] = 'i';
			ans[len] = 'e';
			ans[len + 1] = 's';
			ans[len + 2] = 0;
		}
		else
		{
			ans[len] = 's';
			ans[len + 1] = 0;
		}
		break;
	default:
		ans[len] = 's';
		ans[len + 1] = 0;
		break;
	}
	return ans;
}

int main()
{
	scanf("%s", &a);
	ans = RegularPlural(a);
	printf("%s", ans);
	return 0;
}