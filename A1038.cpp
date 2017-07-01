#include<stdio.h>
#include<string.h>
int i, j, N, longest = 0, k, L;
char S[101];
int main()
{
	scanf("%s", S);
	N = strlen(S);
	for(i = 1; i <= N; i ++)
	{
		for(j = i; j <= N; j++)
		{
			if((j - i + 1) % 2 != 0)
				continue;
			L = (j - i + 1) / 2;
			for(k = 0; k < L && S[i + k - 1] == S[i + L + k - 1]; k++);
			if(k == L)
				longest = longest >= j - i + 1? longest: j - i + 1;
		}
	}
	if(longest != 0)
		printf("%d", longest);
	return 0;
}
