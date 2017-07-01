//����A1106�������õ��˶�ȡ���ݣ��ַ�����ʽ������10���ڣ���������ݣ�ͬʱת�����ƣ�10���ڣ��������������������ڲ�����10���õ��̺��������������ӷ������������Ӵ����ʹ��������������������˷������������˴������ʹ�����������������������10���ݴΣ���
#include <iostream>
#include <stdlib.h>
#define LongNumMax 100//������λ����ʮ���ƣ�
using namespace std;
int ans[21] = { 0 }, p, q;
struct Words
{
	int len;
	char w[200];
};
struct LongNum //�Ӹ�λ��ʼ����0������Ǹ�λ��֮����ε������������λ֮����-1
{
	int Num[LongNumMax];
};
struct LongNumDivideAns
{
	LongNum Quotient;
	int Reminder;
};
LongNum LPlus(LongNum a, int temp)
{
	LongNum ans;
	int i;
	for (i = 0; i < LongNumMax; i++)
	{
		if (a.Num[i] >= 0)
			temp += a.Num[i];
		else if (temp == 0)
			break;
		ans.Num[i] = temp % 10;
		temp /= 10;
	}
	for (; i < LongNumMax; i++)
		ans.Num[i] = -1;
	return ans;
}
LongNum LPlus(LongNum a, LongNum b)
{
	LongNum ans;
	int i, temp = 0;
	for (i = 0; i < LongNumMax; i++)
	{
		if (a.Num[i] >= 0 && b.Num[i] >= 0)
			temp += a.Num[i] + b.Num[i];
		else if (a.Num[i] >= 0)
			temp += a.Num[i];
		else if (b.Num[i] >= 0)
			temp += b.Num[i];
		else if (temp == 0)
			break;
		ans.Num[i] = temp % 10;
		temp /= 10;
	}
	for (; i < LongNumMax; i++)
		ans.Num[i] = -1;
	return ans;
}
LongNum LMulti(LongNum a, int b, int from = 0)
{
	LongNum ans;
	int i, temp = 0;
	for (i = from; i < LongNumMax; i++)
	{
		if (a.Num[i] >= 0)
			temp += a.Num[i] * b;
		else if (temp == 0)
			break;
		ans.Num[i] = temp % 10;
		temp /= 10;
	}
	for (; i < LongNumMax; i++)
		ans.Num[i] = -1;
	return ans;
}
LongNum LMulti(LongNum a, LongNum b)
{
	LongNum ans;
	int i;
	for (i = 0; i < LongNumMax; i++)
		ans.Num[i] = -1;
	for (i = 0; i < LongNumMax && b.Num[i] >= 0; i++)
		ans = LPlus(ans, LMulti(a, b.Num[i], i));
	return ans;
}
LongNum WordToNum(char * Source, int len, int p)
{
	LongNum times, ans;
	int i;
	ans.Num[0] = 0;
	for (i = 1; i < LongNumMax; i++)
		ans.Num[i] = -1;
	for (i = 0; i < len - 1; i++)
	{
		if (Source[i] < '0' || Source[i] > '9')
			break;
		ans = LPlus(LMulti(ans, p), Source[i] - '0');
	}
	return ans;
}
LongNumDivideAns LDivide(LongNum a, int b)//b<10
{
	LongNumDivideAns ans;
	int i, t;
	for (i = 0; a.Num[i] >= 0; i++);
	for (t = i; t < LongNumMax; t++)
		ans.Quotient.Num[t] = -1;
	i--;
	t = a.Num[i];
	if (t < b)
		ans.Quotient.Num[i--] = -1;
	else
		ans.Quotient.Num[i--] = t / b;
	t %= b;
	for (; i >= 0; i--)
	{
		t = t * 10 + a.Num[i];
		ans.Quotient.Num[i] = t / b;
		t %= b;
	}
	ans.Reminder = t;
	return ans;
}
Words NumToWord(LongNum Source, int p)
{
	Words ans;
	int i = 0;
	LongNumDivideAns temp;
	while (!(Source.Num[0] <= 0 && Source.Num[1] < 0))
	{
		temp = LDivide(Source, p);
		ans.w[i++] = temp.Reminder + '0';
		Source = temp.Quotient;
	}
	ans.w[i] = 0;
	ans.len = i;
	return ans;
}
int main()
{
	char Source[100], ch;
	int i = 0;
	do
	{
		ch = getchar();
		Source[i++] = ch;
	} while (ch != '<');
	Source[--i] = 0;
	cin >> p;
	getchar();
	cin >> q;
	LongNum got;
	got = WordToNum(Source, i + 1, p);
	Words ans;
	ans = NumToWord(got, q);
	cout << Source << "<" << p << ">=";
	for (i = ans.len; i > 0; i--)
	{
		cout << ans.w[i - 1];
	}
	cout << "<" << q << ">";
	return 0;
}