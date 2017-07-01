#include<stdio.h>
int main()
{
    int i;
    scanf("%d",&i);
    char c;
    if (i<60) c='F';
    else if(i<70) c='D';
    else if(i<80) c='C';
    else if(i<90) c='B';
    else c='A';
    printf("%c",c);
    return 0;
}
