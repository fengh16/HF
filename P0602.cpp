#include<stdio.h>
#include<string.h>
char origin[101], small[100] = {0}, big[100], temp;
int i, j = 0, k = 0;
int main()
{
	gets(origin);
	for(i = 1; i < strlen(origin); i++)
	{
		if(origin[i] > origin[0])
			big[j++] = origin[i];
		else
			small[k++] = origin[i];
	}
	for(i = k - 2; i >= 0; i--)
	{
		for(j = 0; j <= i; j++)
		{
			if(small[j] > small[j + 1])
			{
				temp = small[j];
				small[j] = small[j + 1];
				small[j + 1] = temp;
			}
		}
	}
	printf("%s%c%s", big, origin[0], small);
	return 0;
}
