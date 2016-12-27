#include<stdio.h>
int main()
{
	int N, i, j, p;
	double ans[4];
	char a[11][101];
	scanf("%d", &N);
	for(i = 1; i <= N; i++)
	{
		scanf("%s", a[i]);
	}
	for(i = 0; ; i++)
	{
		ans[0] = 0.4;
		ans[1] = 0.3;
		ans[2] = 0.2;
		ans[3] = 0.1;
		if(a[1][i] == 0)
			break;
		for(j = 1; j <= N; j++)
		{
			switch(a[j][i])
			{
				case 'A':
					ans[0]++;
					break;
				case 'C':
					ans[1]++;
					break;
				case 'G':
					ans[2]++;
					break;
				case 'T':
					ans[3]++;
					break;
			}
		}
		a[0][0] = 0;
		p = 0;
		for(j = 1; j <= 3; j++)
		{
			if(ans[j] > ans[p])
			{
				a[0][0] = j;
				p = j;
			}
		}
		switch(a[0][0])
		{
		case 0:
			printf("A");
			break;
		case 1:
			printf("C");
			break;
		case 2:
			printf("G");
			break;
		case 3:
			printf("T");
			break;
		}
	}
	return 0;
}
