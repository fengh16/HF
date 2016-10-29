#include<stdio.h>
int main()
{
    char c;
    int num_kong=0, num_huan=0, num_other=0;
    while(1)
    {
        c=getchar();
        if (c==' ') num_kong++;
        else if (c=='\n') num_huan++;
        else if (c=='#') break;
        else num_other++;
    }
    printf("%d %d %d",num_kong, num_huan, num_other);
    return 0;
}
