#include<stdio.h>
int main()
{
	int v1, v2, t, s, l, i = 0, s1 = 0, s2 = 0, ifsleep = 0;
	scanf("%d%d%d%d%d", &v1, &v2, &t, &s, &l);
	while(s1 < l && s2 < l)
	{
		i++;
		if(!ifsleep)
			s1 += v1;
		else
			ifsleep--;
		s2 += v2;
		if(s1 - s2 >= t && !ifsleep)
			ifsleep = s;
	}
	if(s1 >= l && s2 >= l)
		printf("D");
	else if(s1 >= l)
		printf("R");
	else
		printf("T");
	printf("\n%d", i);
	return 0;
}