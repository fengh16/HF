#include<stdio.h>
int letter[256] = {0}, i;
char c;
int main()
{
	c = getchar();
	do
	{
		letter[c - 'A']++;
		c = getchar();
	}
	while((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z'));
	for(i = 0; i < 256; i++)
	{
		if(letter[i] % 2 == 1)
		{
			printf("%c", i + 'A');
			break;
		}
	}
	return 0;
}