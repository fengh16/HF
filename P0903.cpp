#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

char* strncpy(char *s, char *t, int n);/* 复制t的前n个字符至s */
char* strncat(char *s, char *t, int n);/* 连接t的前n个字符至s末尾 */

char s[2001], t[1001], temp[2001];
int n, i, p;

int main()
{
	scanf("%s%s%d", s, t, &n);
	for(i = 0; s[i] != 0; i++)
		temp[i] = s[i];
	temp[i] = 0;
	printf("%s\n", strncpy(s, t, n));
	for(i = 0; temp[i] != 0; i++)
		s[i] = temp[i];
	s[i] = 0;
	printf("%s", strncat(s, t, n));
	return 0;
}

char* strncpy(char *s, char *t, int n)/* 复制t的前n个字符至s */
{
	for(i = 0, p = 0; p < n; i++, p++)
		s[i] = t[p];
	s[i] = 0;
	return s;
}
char* strncat(char *s, char *t, int n)/* 连接t的前n个字符至s末尾 */
{
	for(i = 0; s[i] != 0; i++);
	for(p = 0; p < n; i++, p++)
		s[i] = t[p];
	s[i] = 0;
	return s;
}