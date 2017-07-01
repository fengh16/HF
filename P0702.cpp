#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char s1[1001] = {0}, s2[1001] = {0};
int i;
int my_strcmp(char s1[], char s2[])
{
	for(i = 0; s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i]; i++);
	if(s1[i] == s2[i])
		return 0;
	else
		return s1[i] - s2[i];
}
int main()
{
	gets(s1);
	gets(s2);
	printf("%d", my_strcmp(s1, s2));
	return 0;
}