#include<stdio.h>
int main()
{
	int i, j, t;
	char A[101] = { 0 }, B[101] = { 0 };
	scanf("%s%s", A, B);
	for (i = 0; i < 101 && A[i]; i++);
	for (j = 0; 2 * j <= i - 1; j++)
	{
		t = A[j];
		A[j] = A[i - 1 - j];
		A[i - 1 - j] = t;
	}
	for (i = 0; i < 101 && B[i]; i++);
	for (j = 0; 2 * j <= i - 1; j++)
	{
		t = B[j];
		B[j] = B[i - 1 - j];
		B[i - 1 - j] = t;
	}
	for (i = 0, t = 0; A[i] && B[i]; i++)
	{
		t += A[i] + B[i] - '0' - '0';
		A[i] = t % 10 + '0';
		t /= 10;
	}
	for (; A[i]; i++)
	{
		t += A[i] - '0';
		A[i] = t % 10 + '0';
		t /= 10;
	}
	for (; B[i]; i++)
	{
		t += B[i] - '0';
		A[i] = t % 10 + '0';
		t /= 10;
	}
	while (t)
	{
		A[i++] = t % 10 + '0';
		t /= 10;
	}
	for (j = 0; 2 * j <= i - 1; j++)
	{
		t = A[j];
		A[j] = A[i - 1 - j];
		A[i - 1 - j] = t;
	}
	printf("%s", A);
	return 0;
}