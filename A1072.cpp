#include <stdio.h>
#include <string.h>
char ch[26] = { 0 }, used[26] = { 0 }, get[2][101], should[101];
int m, n, i, wrong = 0, num = 0;
int main()
{
	scanf("%s%s%s", get[0], get[1], should);
	m = strlen(get[0]);
	n = strlen(should);
	for (i = 0; i < m && num < 26; i++)
	{
		if ((ch[get[0][i] - 'A'] != 0 && ch[get[0][i] - 'A'] != get[1][i]) || (ch[get[0][i] - 'A'] == 0 && used[get[1][i] - 'A']))
		{
			wrong = 1;
			break;
		}
		else if(ch[get[0][i] - 'A'] == 0)
		{
			ch[get[0][i] - 'A'] = get[1][i];
			used[get[1][i] - 'A'] = 1;
			num++;
		}
	}
	if (wrong || num < 26)
		printf("Failed");
	else
	{
		for (i = 0; i < n; i++)
		{
			printf("%c", ch[should[i] - 'A']);
		}
	}
	return 0;
}