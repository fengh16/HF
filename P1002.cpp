#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct
{
	double R;
	double i;
}CNum;
CNum C1, C2, AnsC;
//struct CNum
//{
//	double R;
//	double i;
//}C1, C2, AnsC;
double R1, i1, R2, i2;
char ch;
CNum CPlus();
CNum CMinus();
CNum CMulti();
CNum CDiv();
int main()
{
	scanf("%c%lf%lf%lf%lf", &ch, &R1, &i1, &R2, &i2);
	switch (ch)
	{
	case '+':
		AnsC = CPlus();
		break;
	case '-':
		AnsC = CMinus();
		break;
	case '*':
		AnsC = CMulti();
		break;
	case '/':
		AnsC = CDiv();
		break;
	default:
		break;
	}
	printf("%.2lf+%.2lfi", AnsC.R, AnsC.i);
	return 0;
}
CNum CPlus()
{
	CNum AnsC;
	AnsC.R = R1 + R2;
	AnsC.i = i1 + i2;
	return AnsC;
}
CNum CMinus()
{
	CNum AnsC;
	AnsC.R = R1 - R2;
	AnsC.i = i1 - i2;
	return AnsC;
}
CNum CMulti()
{
	CNum AnsC;
	AnsC.R = R1 * R2 - i1 * i2;
	AnsC.i = R1 * i2 + R2 * i1;
	return AnsC;
}
CNum CDiv()
{
	CNum AnsC;
	AnsC.R = (R1 * R2 + i1 * i2) / (R2 * R2 + i2 * i2);
	AnsC.i = (i1 * R2 - R1 * i2) / (R2 * R2 + i2 * i2);
	return AnsC;
}