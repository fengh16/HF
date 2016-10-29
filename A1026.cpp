#include<stdio.h>
#include<string.h>
char input[101];
int num[26], i;
int main()
{
    scanf("%s", input);
    for(i = 0; i <= strlen(input) - 1; i++)
        num[input[i] - 'a'] ++;
    for(i = 0; i <= 25; i++)
    {
        if(num[i] != 0)
        {
            printf("%c %d\n", i + 'a', num[i]);
        }
    }
    return 0;
}
