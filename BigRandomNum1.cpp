#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n[100000], i, Num, Num_1;
	scanf("%d", &Num);
	Num_1 = Num % 4;
	Num = Num / 4;
	srand((unsigned)time(NULL));
	for(i = 1; i <= Num_1; i++)
	{
		do
		{
			do 
			n[i - 1] = rand( );
			while(n[i - 1] >= 30000);
			n[i - 1] = (rand( ) % 10);
		}
		while(n[1] == 0 && !(Num == 0 && Num_1 == 0));
		printf("%.1d", n[i - 1]);
	}
	for(i = 1; i <= Num; i++)
	{
		do 
		n[i - 1] = rand( );
		while(n[i - 1] >= 30000);
		n[i - 1] = (rand( ) % 10000);
		printf("%.4d", n[i - 1]);
	}
	return 0;
}
