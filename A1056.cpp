/*问题描述
　　最近FJ为他的奶牛们开设了数学分析课，FJ知道若要学好这门课，必须有一个好的三角函数基本功。所以他准备和奶牛们做一个“Sine之舞”的游戏，寓教于乐，提高奶牛们的计算能力。
　　不妨设
　　An=sin(1–sin(2+sin(3–sin(4+...sin(n))...)
　　Sn=(...(A1+n)A2+n-1)A3+...+2)An+1
　　FJ想让奶牛们计算Sn的值，请你帮助FJ打印出Sn的完整表达式，以方便奶牛们做题。
输入格式
　　仅有一个数：N<201。
输出格式
　　请输出相应的表达式Sn，以一个换行符结束。输出中不得含有多余的空格或换行、回车符。
样例输入
3
样例输出
((sin(1)+3)sin(1–sin(2))+2)sin(1–sin(2+sin(3)))+1*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N, i;
char*ans;
char sinLeft[] = "sin(", sinright[] = ")", plus[] = "+", minus[] = "-", left[] = "(";
int Lenth_Of_Num(int i)
{
	if(i > 99)
		return 3;
	else if(i > 9)
		return 2;
	else
		return 1;
}
char*CreateNum(int n)
{
	char*CreateNum;
	int sum = Lenth_Of_Num(n);
	int i;
	CreateNum = (char*)malloc((1 + sum) * sizeof(char));
	for(i = sum - 1; i >= 0; i--)
	{
		CreateNum[i] = n % 10 + '0';
		n /= 10;
	}
	CreateNum[sum] = 0;
	return CreateNum;
}
char*CreateA(int n)
{
	int i, lenAn;
	char*temp;
	char*temp2;
	char*newAn;
	newAn = (char*)malloc((6 + Lenth_Of_Num(n)) * sizeof(char));
	strcpy(newAn, sinLeft);
	temp = CreateNum(n);
	strcat(newAn, temp);
	free(temp);
	strcat(newAn, sinright);
	for(i = n - 1; i >= 1; i--)
	{
		lenAn = strlen(newAn);
		temp2 = (char*)malloc((7 + Lenth_Of_Num(i) + lenAn) * sizeof(char));
		strcpy(temp2, sinLeft);
		temp = CreateNum(i);
		strcat(temp2, temp);
		free(temp);
		if(i % 2)
			strcat(temp2, minus);
		else
			strcat(temp2, plus);
		strcat(temp2, newAn);
		strcat(temp2, sinright);
		free(newAn);
		newAn = temp2;
	}
	return newAn;
}
char* CreateS(int n)
{
	int i, lenSn;
	char*temp;
	char*temp2;
	char*newSn;
	char*tempAn;
	tempAn = CreateA(1);
	newSn = (char*)malloc((4 + Lenth_Of_Num(n) + strlen(tempAn)) * sizeof(char));
	strcpy(newSn, left);
	strcat(newSn, tempAn);
	free(tempAn);
	strcat(newSn, plus);
	strcat(newSn, CreateNum(n));
	strcat(newSn, sinright);
	for(i = 2; i <= n; i++)
	{
		lenSn = strlen(newSn);
		tempAn = CreateA(i);
		temp2 = (char*)malloc((5 + Lenth_Of_Num(n + 1 - i) + lenSn + strlen(tempAn)) * sizeof(char));
		strcpy(temp2, left);
		strcat(temp2, newSn);
		strcat(temp2, sinright);
		strcat(temp2, tempAn);
		strcat(temp2, plus);
		temp = CreateNum(n + 1 - i);
		strcat(temp2, temp);
		strcat(temp2, sinright);
		free(tempAn);
		free(newSn);
		free(temp);
		newSn = temp2;
	}
	return newSn;
}
int main()
{
	char*RealAns;
	int zero;
	scanf("%d", &N);
	ans = CreateS(N);
	RealAns = ans + 1;
	zero = strlen(RealAns);
	RealAns[zero - 1] = 0;
	printf("%s", RealAns);
	free(ans);
	return 0;
}