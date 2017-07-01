#include<stdio.h>
#include<string.h>

int num[10] = {0}, i, IfYi = 0, IfWan = 0;
char S[] = "shi ", B[] = "bai ", Q[] = "qian ", W[] = "wan ", Y[] = "yi ", n[10][6] = {{"ling "}, {"yi "}, {"er "}, {"san "}, {"si "}, {"wu "}, {"liu "}, {"qi "}, {"ba "}, {"jiu "}}, ans[500] = {0};
long long int nums;

void AddWordsInWan(int N3, int N2, int N1, int N0, int Wei)
{
	int if_add_Zero = 0;
	if((IfYi && Wei == 1) || ((IfYi || IfWan) && Wei == 2))
		if_add_Zero = 1;
	if(N3 != 0)
	{
		strcat(ans, n[N3]);
		strcat(ans, Q);
	}
	else if(if_add_Zero)
		strcat(ans, n[0]);
	if(N2 != 0)
	{
		strcat(ans, n[N2]);
		strcat(ans, B);
	}
	if(N1 != 0)
	{
		if(N2 == 0 && N3 != 0)
			strcat(ans, n[0]);
		if(N1 != 1)
			strcat(ans, n[N1]);
		strcat(ans, S);
	}
	if(N0 != 0)
	{
		if((N2 == 0 && N1 == 0 && N3 != 0) || (N1 == 0 && N2 != 0))
			strcat(ans, n[0]);
		strcat(ans, n[N0]);
	}
}

int main()
{
	scanf("%lld", &nums);
	for(i = 0; i < 10 && nums; i++)
	{
		num[i] = nums % 10;
		nums /= 10;
	}
	if(num[9] || num[8])
	{
		AddWordsInWan(0, 0, num[9], num[8], 0);
		strcat(ans, Y);
		IfYi = 1;
	}
	if(num[7] || num[6] || num[5] || num[4])
	{
		AddWordsInWan(num[7], num[6], num[5], num[4], 1);
		strcat(ans, W);
		IfWan = 1;
	}
	if(num[3] || num[2] || num[1] || num[0])
		AddWordsInWan(num[3], num[2], num[1], num[0], 2);
	printf("%s", ans);
	return 0;
}