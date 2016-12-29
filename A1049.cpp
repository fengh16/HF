/*问题描述
　　在命题逻辑中，每个变元可以取值为真或假，通过逻辑运算符连接得到逻辑表达式，逻辑表达式的值由逻辑变元的值计算得出。
　　以下是常用的逻辑运算符。
　　~：表示否定，~P为真当且仅当P为假。
　　>：蕴含，P>Q为真当且仅当Q为真或者P为假。
　　^：合取，P^Q为真当且仅当P和Q同为真。
　　v：析取，PvQ为真当且仅当P和Q中至少一个为真。

　　重言式是指无论变元如何取值其结果都为真的表达式，矛盾式是指无论变元如何取值其结果都为假的表达式。

　　在表式逻辑表达式的时候，可以使用辅助符号来方便描述，一个辅助符号可能是另外两个变元或辅助符号运算的结果。
　　为了使用辅助符号来表示否定运算，我们设置一个虚拟的辅助符号X0，使用X0和另一个变元运算P运算后即得到~P的结果。

　　给定一系列辅助符号的定义，问最后一个辅助符号是重言式、矛盾式还是其他表达式。
输入格式
　　输入数据第一行是两个整数n、m（1<=n<=4，1<=m<=10）。表示在输入中出现的变元不超过n个、辅助符号为m个，变元依次为P0, P1, ..., Pn-1，辅助符号依次为A0, A1, ..., Am-1。
　　从第二行开始，依次描述A0,A1,…Am-1，并严格依照以下格式：
　　Ai L ? R
　　其中Ai依次为A0, A1, ..., Am-1。?可以为“~”、“>”、“^”、“v”。L和R可以是变元或者之前出现过的辅助符号。
　　若?为“~”，则L必定为X0。
输出格式
　　若Am-1为重言式，输出1。
　　若Am-1为矛盾式，输出-1。
　　若两者都不是，输出0。
样例输入
1 2
A0 X0 ~ P0
A1 A0 v P0
样例输出
1*/
#include<stdio.h>
int n_p, m_a, i, i_a, P[4], Final = 2, t1, t2, m, temp;
char useless[10], u;
typedef struct
{
	char A_P[2];
	int A_P_Num[2];
	char DoNum;/*1--> ~：表示否定，~P为真当且仅当P为假。2-->　>：蕴含，P>Q为真当且仅当Q为真或者P为假。3--> ^：合取，P^Q为真当且仅当P和Q同为真。4-->　v：析取，PvQ为真当且仅当P和Q中至少一个为真。*/
	int ans;
}te;
te a[10];
int Judge()
{
	for(m = 0; m < m_a; m++)
	{
	if(a[m].A_P[0] == 'A')
	{
		if(a[a[m].A_P_Num[0]].ans)
			t1 = 1;
		else
			t1 = 0;
	}
	else if(a[m].A_P[0] == 'P')
	{
		if(P[a[m].A_P_Num[0]])
			t1 = 1;
		else
			t1 = 0;
	}
	if(a[m].A_P[1] == 'A')
	{
		if(a[a[m].A_P_Num[1]].ans)
			t2 = 1;
		else
			t2 = 0;
	}
	else if(a[m].A_P[1] == 'P')
	{
		if(P[a[m].A_P_Num[1]])
			t2 = 1;
		else
			t2 = 0;
	}
	switch (a[m].DoNum)
	{
	case '~':
		a[m].ans = 1 - t2;
		break;
	case '>':
		a[m].ans = 1 - t1 * (1 - t2);
		break;
	case '^':
		a[m].ans = t1 * t2;
		break;
	case 'v':
		a[m].ans = 1 - (1 - t1) * (1 - t2);
		break;
	}
	}
	if(a[m_a - 1].ans)
		return 1;
	else
		return -1;
}
void Try(int n)
{
	for(P[n] = 0; P[n] < 2; P[n]++)
	{
		if(n == n_p - 1)
		{
			temp = Judge();
			if(Final == 2)
				Final = temp;
			else if(Final != temp)
				Final = 0;
		}
		else if(Final)
			Try(n + 1);
	}
}
int main()
{
	scanf("%d%d", &n_p, &m_a);
	for(i = 0; i < m_a; i++)
	{
		scanf("%s", useless);
		getchar();
		scanf("%c%d%c%c%c%c%d", &a[i].A_P[0], &a[i].A_P_Num[0], &u, &a[i].DoNum, &u, &a[i].A_P[1], &a[i].A_P_Num[1]);
	}
	Try(0);
	printf("%d", Final);
	return 0;
}