#include<stdio.h>
/*5家奶粉厂家在近期的一次质量评比活动中分获前5名，在评前大家就已经知道E厂肯定不是第2名和第3名。
　　A厂的代表猜：E厂的产品稳获第1名
　　B厂的代表猜：我厂可能获第2名
　　C厂的代表猜：A厂的质量最差
　　D厂的代表猜：C厂的产品不是最好的
　　E厂的代表猜：D厂会获第1名
　　评比结果公布后发现，只有获第1名和第2名的两个厂的代表猜对了。请编程输出A，B，C，D，E各是第几名？*/
int taken[5] = {0}, ans[5], i, t, GotAns = 0;
int get()
{
	if((ans[4] == 0 && ans[0] >= 2) || (ans[4] != 0 && ans[0] < 2))
		return 0;
	if((ans[1] == 1 && ans[1] >= 2) || (ans[1] != 1 && ans[1] < 2))
		return 0;
	if((ans[0] == 4 && ans[2] >= 2) || (ans[0] != 4 && ans[2] < 2))
		return 0;
	if((ans[2] > 0 && ans[3] >= 2) || (ans[2] == 2 && ans[3] < 2))
		return 0;
	if((ans[3] == 0 && ans[4] >= 2) || (ans[3] != 0 && ans[4] < 2))
		return 0;
	if(ans[4] == 1 || ans[4] == 2)
		return 0;
	for(i = 0; i < 5; i++)
		printf("%d ", ans[i] + 1);
	return 1;
}
void Try(int k)
{
	int m;
	for(m = 0; m < 5; m++)
	{
		if(!taken[m])
		{
			ans[k] = m;
			taken[m] = 1;
			if(GotAns)
				break;
			if(k == 4)
			{
				if(GotAns = get())
					break;
			}
			else
				Try(k + 1);
			taken[m] = 0;
		}
	}
}
int main()
{
	Try(0);
	return 0;
}