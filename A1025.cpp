#include<stdio.h>
#include<string.h>
char a[11], b[11];
int a_lenth, b_lenth, i, num_BS = 0;
int main()
{
    scanf("%s%s", a, b);
    a_lenth = strlen(a);
    b_lenth = strlen(b);
    if(a_lenth == b_lenth)
    {
        for(i = 0; i <= a_lenth; i++)
        {
            if ((a[i] == b[i] + 'A' - 'a') || (a[i] == b[i] - 'A' + 'a'))
                num_BS ++;
            else if (a[i] != b[i])
            {
                printf("4");
                num_BS = -1;
                break;
            }
        }
        if (num_BS == 0) printf("2");
        else if (num_BS != -1) printf("3");
    }
    else 
        printf("1");
    return 0;
}
