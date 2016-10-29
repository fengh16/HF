#include<stdio.h>
#include<string.h>
char origin[21], test[100][21];
int N, i, origin_n, test_n, OK = 0;
int main()
{
    scanf("%s%d", origin, &N);
    for(i = 1; i <= N; i ++)
    {
        scanf("%s", test[i - 1]);
    }
    i = 1;
    while(i <= N && OK == 0)
    {
        if(strlen(origin) - strlen(test[i - 1]) == 0)
        {
            for(origin_n = test_n = 1; origin[origin_n - 1] == test[i - 1][test_n - 1] && test_n <= strlen(test[i - 1]); origin_n++, test_n++);
            if(test_n > strlen(test[i - 1]) - 1)
            {
                OK = 1;
                printf("%s", test[i - 1]);
            }
        }
        i++;
    }
    i = 1;
    while(i <= N && OK == 0)
    {
        if(strlen(origin) - strlen(test[i - 1]) == 1)
        {
            for(origin_n = test_n = 1; origin[origin_n - 1] == test[i - 1][test_n - 1] && test_n <= strlen(test[i - 1]); origin_n++, test_n++);
            if(origin[origin_n] == test[i - 1][test_n - 1])
            {
                for(; origin[origin_n] == test[i - 1][test_n - 1] && test_n <= strlen(test[i - 1]); origin_n++, test_n++);
            }
            if(test_n > strlen(test[i - 1]))
            {
                OK = 1;
                printf("%s", test[i - 1]);
            }
        }
        else if(strlen(origin) - strlen(test[i - 1]) == - 1)
        {
            for(origin_n = test_n = 1; origin[origin_n - 1] == test[i - 1][test_n - 1] && test_n <= strlen(test[i - 1]) - 1; origin_n++, test_n++);
            if(origin[origin_n - 1] == test[i - 1][test_n])
            {
                for(; origin[origin_n - 1] == test[i - 1][test_n] && test_n <= strlen(test[i - 1]) - 1; origin_n++, test_n++);
            }
            if(test_n > strlen(test[i - 1]) - 1)
            {
                OK = 1;
                printf("%s", test[i - 1]);
            }
        }
        else if(strlen(origin) - strlen(test[i - 1]) == 0)
        {
            for(origin_n = test_n = 1; origin[origin_n - 1] == test[i - 1][test_n - 1] && test_n <= strlen(test[i - 1]); origin_n++, test_n++);
            if(origin[origin_n] == test[i - 1][test_n])
            {
                for(; origin[origin_n] == test[i - 1][test_n] && test_n <= strlen(test[i - 1]) - 1; origin_n++, test_n++);
            }
            if(test_n > strlen(test[i - 1]) - 1)
            {
                OK = 1;
                printf("%s", test[i - 1]);
            }
        }
        i++;
    }
    if(OK == 0)
        printf("NOANSWER");
    return 0;
}
