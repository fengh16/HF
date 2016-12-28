#include<stdio.h>

int num = 0, i = 0, j, now[26] = {0};
char ch;
struct Source
{
	int n[26];
	char text[500];
	int used;
};
struct Source s[500] = {{{0}, {0}, 0}};

int main()
{
	while(1)
	{
		ch = getchar();
		if(ch >= 'a' && ch <= 'z')
		{

			s[num].n[ch - 'a']++;
			s[num].text[i++] = ch;
		}
		else if(ch == ' ')
		{
			num++;
			i = 0;
		}
		else
		{
			num++;
			break;
		}
	}
	while(1)
	{
		ch = getchar();
		if(ch >= 'a' && ch <= 'z')
			now[ch - 'a']++;
		else
		{
			for(i = 0; i < num; i++)
			{
				if(s[i].used == 1)
					continue;
				for(j = 0; j < 26 && s[i].n[j] == now[j]; j++);
				if(j == 26)
				{
					printf("%s ", s[i].text);
					s[i].used = 1;
					break;
				}
			}
			for(j = 0; j < 26; j++)
				now[j] = 0;
			if(ch != ' ')
				break;
		}
	}
	return 0;
}