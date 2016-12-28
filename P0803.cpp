#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int i = 0, j = 0, num[26] = {0};
char s[2000], ch;
void strcompress(char *s)
{
	while(1)
	{
		ch = s[i++];
		if(ch <= 'z' && ch >= 'a')
		{
			num[ch - 'a']++;
			if(num[ch - 'a'] == 1 || num[ch - 'a'] == 3 || num[ch - 'a'] == 6)
				s[j++] = ch;
		}
		else if(ch == ' ')
			s[j++] = ch;
		else
		{
			s[j] = 0;
			break;
		}
	}
}
int main()
{
	gets(s);
	strcompress(s);
	printf("%s", s);
	return 0;
}