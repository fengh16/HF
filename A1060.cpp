/*��һ����4���ÿո�ָ���ʵ�����ֱ��ʾ�ž�����7����8����9����10���ĸ��ʡ����ﱣ֤��4��ʵ���ĺ�Ϊ1��
�����ڶ�����4���ÿո�ָ���ʵ�����ֱ��ʾ�ž��������7����8����9����10���ĸ��ʡ�ͬ����4��ʵ���ĺ�ҲΪ1��
�������������У�ÿ����һ���������ֱ��ʾQ1��Q2��Q3��
�����ʽ
����������У�ÿ��һ���������ֱ��ʾ�ž������Q1��Q2��Q3���ĸ��ʣ������ðٷ�����ʾ���ٷֱ��������뵽������
��������
0.0 0.0 0.0 1.0
0.0 0.0 0.0 1.0
-1
0
1

�������
0%
100%
0%
*/
#include<stdio.h>
double Rate[2][4], pans[3] = {0}, ans, pos[7];
int Q, i, p, a, b, QN[3], type[12], ResultScore, t, CAns[13][13] = {0};
int C(int n, int m)
{
	if(m == 0)
		return 1;
	if(CAns[n][m])
		return CAns[n][m];
	if(m == 1)
		return CAns[n][m] = n;
	if(m == n)
		return CAns[n][m] = 1;
	return CAns[n][m] = C(n - 1, m) + C(n - 1, m - 1);
}
int Times()
{
	int i, temp, num = 1, n = 12, times = 1;
	temp = type[0];
	for(i = 1; i < 12; i++)
	{
		if(temp == type[i])
			num++;
		else
		{
			temp = type[i];
			times *= C(n, num);
			n -= num;
			num = 1;
		}
	}
	times *= C(n, num);
	return times;
}
void GET()
{
	int t, m, times;
	double tempget = 1;
	ResultScore = 0;
	for(t = 0; t < 12; t++)
	{
		ResultScore += type[t];
	}
	for(m = 0; m < 3; m++)
	{
		if(ResultScore == QN[m])
		{
			for(t = 0; t < 12; t++)
			{
				tempget *= pos[type[t] + 3];
			}
			times = Times();
			pans[m] += tempget * times;
		}
	}
}
void GetScores(int n)
{
	int t;
	for(t = n > 0? type[n - 1]: -3; t < 4; t++)
	{
		if(!pos[t + 3])
			continue;
		type[n] = t;
		if(n == 11)
			GET();
		else
			GetScores(n + 1);
	}
}
int main()
{
	for(i = 0; i < 8; i++)
		scanf("%lf", &Rate[0][0] + i);
	for(i = 0; i < 3; i++)
		scanf("%d", &QN[i]);
	for(Q = -3; Q <= 3; Q++)
	{
		ans = 0;
		if(Q > 0)
		{
			a = Q + 7;
			b = 10;
		}
		else
		{
			a = 7;
			b = 10 + Q;
		}
		for(p = a - 7; p <= b - 7; p++)
			ans += Rate[0][p] * Rate[1][p - Q];
		pos[Q + 3] = ans;
	}
	GetScores(0);
	for(i = 0; i < 3; i++)
	{
		pans[i] *= 100;
		t = (int)pans[i];
		if(pans[i] - t >= 0.5)
			t++;
		printf("%d%%\n", t);
	}
	return 0;
}