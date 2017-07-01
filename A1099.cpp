#include <stdio.h>
#include <string.h>
int Day[8][2], i, t, k;
char temp1[10], temp2[10], Days[7][10] = {{"monday"}, {"tuesday"}, {"wednesday"}, {"thursday"}, {"friday"}, {"saturday"}, {"sunday"}};
void Mstrlwr(char* a)
{
	int temp = strlen(a);
	for(k = 0; k < temp; k++)
	{
		if(a[k] >= 'A' && a[k] <= 'Z')
			a[k] += 'a' - 'A';
	}
}
int main()
{
	for(i = 0; i <8; i++)
	{
		scanf("%s%s", temp1, temp2);
		Mstrlwr(temp1);
		for(t = 0; t < 7; t++)
		{
			if(!strcmp(temp1, Days[t]))
				break;
		}
		Day[i][0] = t;
		Mstrlwr(temp2);
		for(t = 0; t < 7; t++)
		{
			if(!strcmp(temp2, Days[t]))
				break;
		}
		Day[i][1] = t;
	}
	for(i = 0; i < 7; i++)
	{
		for(t = 0; t < 8; t++)
		{
			if((Day[t][0] == i && Day[t][1] != i) || (Day[t][0] != i && Day[t][1] == i))
			   break;
		}
		if(t == 8)
			break;
	}
	Days[i][0] += 'A' - 'a';
	printf("%s", Days[i]);
	return 0;
}