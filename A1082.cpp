int t = s[0], i, sp = 0, lp = n - 1;
while (sp < lp)
{
	for (; s[lp] >= t && lp > sp; lp--);
	i = s[sp];
	s[sp] = s[lp];
	s[lp] = i;
	for (; s[sp] <= t && lp > sp; sp++);
	i = s[sp];
	s[sp] = s[lp];
	s[lp] = i;
}
s[sp] = t;
if (sp > K - 1)
return findKth(s, sp, K);
else if (sp == K - 1)
return t;
else
return findKth(s + sp + 1, n - sp - 1, K - sp - 1);
/*ʹ�õĲ��Գ���
#include <iostream>
using namespace std;
int findKth(int *s, int n, int K)
{
	//�������
}
int main()
{
	int n, K, s[99999], i;
	cin >> n >> K;
	for (i = 0; i < n; i++)
		cin >> s[i];
	i = findKth(s, n, K);
	cout << i;
	return 0;
}
*/
/*���������Ҳ���ʱ�ĵ��㷨
int a[140000] = { 0 }, i, t;
for (i = 0; i < n; i++)
a[s[i] + 70000]++;
i = 0;
for (t = 0; t < 140000 && i < K; t++)
i += a[t];
return t - 70001;
*/