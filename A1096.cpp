#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char All[1001];
char **Shorts;
char * temp;
int n, k, i, t;
int main()
{
	scanf("%s%d", All, &k);
	n = strlen(All);
	Shorts = (char**)malloc((n - k + 1) * sizeof(char*));
	temp = (char*)malloc((k + 1) * sizeof(char));
	for (i = 0; i < n - k + 1; i++)
	{
		Shorts[i] = (char*)malloc((k + 1) * sizeof(char));
		for (t = 0; t < k; t++)
		{
			Shorts[i][t] = All[i + t];
		}
		Shorts[i][t] = 0;
	}
	for (i = 0; i < n - k; i++)
	{
		for (t = 0; t < n - k - i; t++)
		{
			if (strcmp(Shorts[t], Shorts[t + 1]) > 0)
			{
				strcpy(temp, Shorts[t]);
				strcpy(Shorts[t], Shorts[t + 1]);
				strcpy(Shorts[t + 1], temp);
			}
		}
	}
	for (i = 0; i < n - k + 1; i++)
		printf("%s ", Shorts[i]);
	return 0;
}