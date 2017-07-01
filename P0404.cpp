#include<stdio.h>
#define year_week_plus 365 % 7
int week_num, year, Sum_Leap = 0, Final_Year, month[12] = {0, 1, -2, 1, 0, 1, 0, 1, 1, 0, 1, 0}, month_num;
int main()
{
    scanf("%d", &Final_Year);
    for(year = 1998; year < Final_Year; year++)
    {
        Sum_Leap += (year % 4 == 0 && (!year % 100 == 0 || year % 400 == 0)) ? 1: 0;
        Sum_Leap += year_week_plus;
    }
    month[2] += (Final_Year % 4 == 0 && (!Final_Year % 100 == 0 || Final_Year % 400 == 0)) ? 1: 0;
    week_num = (4 + Sum_Leap + 12) % 7;
    for(month_num = 1; month_num <= 11; month_num++)
    {
        if(week_num == 5)
            printf("%.4d-%.2d-13\n", Final_Year, month_num);
        week_num = (week_num + month[month_num] + 30) % 7;
    }
    if(week_num == 5)
        printf("%.4d-%.2d-13\n", Final_Year, month_num);
    return 0;
}
