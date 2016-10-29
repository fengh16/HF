#include<stdio.h>
int main()
{
	int i, t, h, p, a[6];
    for (i=0; i<64; i++) 
	{
		h=i;
		p=0;
		for (t=0; t<6; t++) 
		{
			p+=(a[5-t]=h%2);
			h=h/2;
		}
		if (p%2)
		{
			for (t=0; t<6; t++)
  		   {
				printf("%d",a[t]);
			}
				printf("\n");
			}
			p=0;
		}
	return 0;
}
