#include<stdio.h>
long int min, max, i, k, old = -100, ok = 1;
int main()
{
    scanf("%ld%ld", &min, &max);
	if(min <= 2)
        min = 3;        //因为孪生素数对必须大于等于3
    for(i = min; i <= max; i++)       //从min到max遍历所有数，查到每一个质数
    {
        for(k = 2; k * k <= i && i % k != 0; k++);     //素数i满足对于k=2到根号i的所有数都不能整除，也就是k最终会大于根号i；否则i%k==0，提前退出循环，k不会大于根号i
        if(k * k > i)
        {
            if(i - old == 2)       //如果下一个质数与上一个质数（old）相差2，则满足孪生素数，输出
            {
                printf("%ld %ld\n", old, i);
                ok = 0;      //k=0说明存在符合条件的孪生素数对
            }
            old = i;       //old表示上一个质数
        }
    }
    if(ok == 1)      //说明不存在符合条件的孪生素数对，输出-1
        printf("-1");
    return 0;
}
