#include<stdio.h>
int N, i[8], t;
long sum = 0, sum_1 = 0;
int main()
{
    scanf("%d", &N);
    for(i[1] = 1; i[1] <= 3; i[1] ++)
    {
            if(i[1] > N) break;
            else if(i[1] == N) 
            {
                sum += 1;
                for(t = 1; t <= 1; t++)
                {
                    if(i[t] == 1) sum_1 += 1;
                }
            }
            else
            {
        for(i[2] = 1; i[2] <= 3; i[2] ++)
        {
            if(i[2] == 1 && i[1] == 1) continue;
            else if(i[2] + i[1] > N) break;
            else if(i[2] + i[1] == N) 
            {
                sum += 1;
                for(t = 1; t <= 2; t++)
                {
                    if(i[t] == 1) sum_1 += 1;
                }
            }
            else
            {
        for(i[3] = 1; i[3] <= 3; i[3] ++)
        {
            if(i[3] == 1 && i[2] == 1) continue;
            else if(i[3] + i[2] + i[1] > N) break;
            else if(i[3] + i[2] + i[1] == N) 
            {
                sum += 1;
                for(t = 1; t <= 3; t++)
                {
                    if(i[t] == 1) sum_1 += 1;
                }
            }
            else
            {
        for(i[4] = 1; i[4] <= 3; i[4] ++)
        {
            if(i[4] == 1 && i[3] == 1) continue;
            else if(i[4] + i[3] + i[2] + i[1] > N) break;
            else if(i[4] + i[3] + i[2] + i[1] == N) 
            {
                sum += 1;
                for(t = 1; t <= 4; t++)
                {
                    if(i[t] == 1) sum_1 += 1;
                }
            }
            else
            {
        for(i[5] = 1; i[5] <= 3; i[5] ++)
        {
            if(i[5] == 1 && i[4] == 1) continue;
            else if(i[5] + i[4] + i[3] + i[2] + i[1] > N) break;
            else if(i[5] + i[4] + i[3] + i[2] + i[1] == N) 
            {
                sum += 1;
                for(t = 1; t <= 5; t++)
                {
                    if(i[t] == 1) sum_1 += 1;
                }
            }
            else
            {
        for(i[6] = 1; i[6] <= 3; i[6] ++)
        {
            if(i[6] == 1 && i[5] == 1) continue;
            else if(i[6] + i[5] + i[4] + i[3] + i[2] + i[1] > N) break;
            else if(i[6] + i[5] + i[4] + i[3] + i[2] + i[1] == N) 
            {
                sum += 1;
                for(t = 1; t <= 6; t++)
                {
                    if(i[t] == 1) sum_1 += 1;
                }
            }
            else
            {
        for(i[7] = 1; i[7] <= 3; i[7] ++)
        {
            if(i[6] == 1 && i[7] == 1) continue;
            else if(i[7] + i[6] + i[5] + i[4] + i[3] + i[2] + i[1] > N) break;
            else if(i[7] + i[6] + i[5] + i[4] + i[3] + i[2] + i[1] == N) 
            {
                sum += 1;
                for(t = 1; t <= 7; t++)
                {
                    if(i[t] == 1) sum_1 += 1;
                }
            }
        }
        }
        }
            }
        }
            }
        }
            }
        }
            }
        }
    }
    }
    printf("%ld\n", sum);
    printf("%ld", sum_1);
    return 0;
}
