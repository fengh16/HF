#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i;
	long long int rand_bigger = 0, Num, Num_1;
	scanf("%lld", &Num);  /*input the max*/
	Num_1 = (Num - 1) / RAND_MAX + 1;
	srand((unsigned)time(NULL));
	for(i = 1; i <= Num_1; i++)
	{
		rand_bigger += rand();
	}
	rand_bigger = Num * (rand_bigger / ((double)Num_1 * RAND_MAX + 1));
	printf("%lld", rand_bigger);
	return 0;
}
