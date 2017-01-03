#include<stdio.h>
int getnum(double i)
{
	int m = (int)i;
	if (i - m > 0.5)
		m++;
	else if (i - m < -0.5)
		m--;
	return m;
}
int main()
{
	int n, i, PosRP, PosTP, dec = -1;
	double T, V[2][4], s[1001][2], PosRT, PosTT, vR, vT, trR, trT, t = 0;
	double tRest, Tnow;
	scanf("%d%lf", &n, &T);
	for (i = 0; i < 4; i++)
	{
		scanf("%lf", &V[0][i]);
	}
	for (i = 0; i < 4; i++)
	{
		scanf("%lf", &V[1][i]);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%lf%lf", &s[i][0], &s[i][1]);
	}
	PosRP = PosTP = 0;
	PosRT = PosTT = s[0][1];
	while (PosRP < n && PosTP < n)
	{
		trR = trT = -1;
		dec++;
		if (dec > 9)
			dec = 9;
		t += T;
		Tnow = T;
		vT = V[0][getnum(s[PosTP][0]) - 1] * (10 - dec) / 10;
		vR = V[1][getnum(s[PosRP][0]) - 1] * (10 - dec) / 10;
		if (PosRT > vR * T)
			PosRT -= vR * T;
		else
		{
			do
			{
				tRest = 1.0 * (vR * Tnow - PosRT) / vR;
				PosRP++;
				if (PosRP >= n)
				{
					trR = tRest;
					break;
				}
				vR = V[1][getnum(s[PosRP][0]) - 1] * (10 - dec) / 10;
				PosRT = s[PosRP][1];
				if (PosRT > vR * tRest)
				{
					PosRT -= vR * tRest;
					break;
				}
				Tnow = tRest;
			} while (tRest > -0.000001);
		}
		Tnow = T;
		if (PosTT > vT * T)
			PosTT -= vT * T;
		else
		{
			do
			{
				tRest = 1.0 * (vT * Tnow - PosTT) / vT;
				PosTP++;
				if (PosTP >= n)
				{
					trT = tRest;
					break;
				}
				vT = V[0][getnum(s[PosTP][0]) - 1] * (10 - dec) / 10;
				PosTT = s[PosTP][1];
				if (PosTT > vT * tRest)
				{
					PosTT -= vT * tRest;
					break;
				}
				Tnow = tRest;
			} while (tRest > -0.000001);
		}
	}
	if (PosRP >= n && PosTP >= n)
	{
		if (trR == trT)
		{
			printf("D");
			printf("\n%.2lf", t - trR);
		}
		else if (trR > trT)
		{
			printf("R");
			printf("\n%.2lf", t - trR);
		}
		else
		{
			printf("T");
			printf("\n%.2lf", t - trT);
		}
	}
	else if (PosRP >= n)
	{
		printf("R");
		printf("\n%.2lf", t - trR);
	}
	else
	{
		printf("T");
		printf("\n%.2lf", t - trT);
	}
	return 0;
}