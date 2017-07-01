#include<stdio.h>
#include<string.h>
char a[100][100];
int i = 0, t;
int main()
{
    do
    {
        scanf("%s", &a[i]);
        for(t = 0; t < i && strcmp(a[t], a[i]); t++);
        if(t == i)
            i++;
    }
    while(getchar() != '\n');
    printf("%d", i);
    return 0;
}
