#include <iostream>
using namespace std;
int main()
{
	char Source[81], ch, ch1, ch2;
	int i = 0, t = 0, j, k;
	while ((Source[i++] = getchar()) != '.');
	Source[i] = 0;
	do
	{
		ch = getchar();
	} while (ch != 'D' && ch != 'I' && ch != 'R');
	switch (ch)
	{
	case 'D':
		getchar();
		ch1 = getchar();
		while (Source[t++] != ch1 && t <= i);
		t--;
		if (t == i)
			cout << "wrong";
		else
		{
			for (; t < i; t++)
			{
				Source[t] = Source[t + 1];
			}
			cout << Source;
		}
		break;
	case 'I':
		getchar();
		ch1 = getchar();
		getchar();
		ch2 = getchar();
		while (Source[t++] != ch1 && t <= i);
		t--;
		if (t == i)
			cout << "wrong";
		else
		{
			while (t < i)
			{
				k = t;
				while (Source[++t] != ch1 && t < i);
			}
			for (j = i + 1; j > k; j--)
				Source[j] = Source[j - 1];
			Source[j] = ch2;
			cout << Source;
		}
		break;
	default:
		getchar();
		ch1 = getchar();
		getchar();
		ch2 = getchar();
		while (Source[t++] != ch1 && t <= i);
		t--;
		if (t == i)
			cout << "wrong";
		else
		{
			while (t < i)
			{
				Source[t] = ch2;
				t++;
				while (Source[t++] != ch1 && t <= i);
				t--;
			}
			cout << Source;
		}
		break;
	}
	return 0;
}