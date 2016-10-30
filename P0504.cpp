#include<stdio.h>
int letter[2][26] = {0}, t = 0;
char c;
int main()
{
    do
    {
        c = getchar();
        if(c == ' ' || c == '\n')
            t++;
        else 
        {
            letter[t][c >= 'a' ? c - 'a' : c - 'A']++;
        }
    }
    while(t <= 1);
    for(t = 0; t < 26 && letter[0][t] == letter[1][t]; t++);
    if(t == 26)
        printf("yes");
    else
        printf("no");
    return 0;
}
