#include<stdio.h>
char str[21], ch;
int i;
int main()
{
    scanf("%[^\n]", str);
    do
        scanf("%c", &ch);
    while(ch == '\n');
    for(i = 0; str[i] != 0; i++)
    {
        if(str[i] != ch)
            printf("%c", str[i]);
    }
    return 0;
}
