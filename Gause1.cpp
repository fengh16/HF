#include<stdio.h>
double a[11][11], x[10];
/*在交换某两行时需要使用另一个临时数组，也可以直接用a中多余的一行。
在创建二维数组时，可以分别建立A与b，但也可以直接建立增广矩阵（可以将b放到a的最后一列，也可以直接放到第一列）。其中[1][1]到[10][10]为最大10X10的系数矩阵A，而a[1][0]到a[10][0]是b中的元素。*/
int row, cross, N, flag = 1; //flag用来判断是否有唯一解，
void Get_A_b()
{
	for(row = 1; row <= N; row++)
	{
		for(cross = 1; cross <= N; cross++)
		scanf("%lf", &a[row][cross]);   //此处如果使用%d会出错
	}
	for(row = 1; row <= N; row++)  //读入b并储存在a[ ][0]中
		scanf("%lf", &a[row][0]);
}
void exchange(int row1, int row2)   //把第row1行和第row2行交换位置
{
	int i;
	for(i = 0; i <= N; i++)    //把A和b两个矩阵都同时换掉, a[0][i]是临时数组
	{
		a[0][i] = a[row1][i];
		a[row1][i] = a[row2][i];
		a[row2][i] = a[0][i];
	}
}
void minus(int row_raw)   //把第row_raw行下面的用第row_raw行消掉（减去row_raw行的若干倍）
{
	int i, t;
	double times;
	for(t = row_raw +1; t <= N; t++)
	{
		times = a[t][row_raw] / a[row_raw][row_raw];
		for(i = 0; i <= N; i++)    //对第i列进行处理（整个增广矩阵）
			a[t][i] -= a[row_raw][i] * times;
	}
}
int echelon_form(int cross_num)
	//把矩阵A第cross_num列换为上三角矩阵，同时有返回值，返回1代表没问题，返回0代表方程组不满足有唯一解
{
	int h;
	if(a[cross_num][cross_num] >= -0.00001 && a[cross_num][cross_num] <= 0.00001)
		//对角线上元素为0，这时尝试交换
	{
		for(h = cross_num + 1; h <= N && a[h][cross_num] >= -0.00001 && a[h][cross_num] <= 0.00001; h++);
		//分别检查对角线下有没有非零元素，同时将h定位到第一个非零元素上
		if(h == N + 1)   //如果对角线下没有非零元素，及上述循环一直进行直到h=N+1
			return flag = 0;
		else     //此时已经找到了非零元素是在第h行，所以要交换h行和cross_num行
		{
			exchange(h, cross_num);
		}
	}
	if(flag)
	{
		minus(cross_num);
		return 1;
	}
}
void solve()   //对上三角矩阵进行解方程
{
	int p, q;
	for(p = N; p > 0; p--)   //倒着算，算出第p个答案
	{
		x[p - 1] = a[p][0] / a[p][p];   //b中的第p个除以A中第p个对角线元素
		for(q = 1; q < p; q++)
			a[q][0] -= x[p - 1] * a[q][p];
	}
}
int main()
{
	int k;
	scanf("%d", &N);
	Get_A_b();
	for(k = 1; k <= N && echelon_form(k); k++);
	//依次对各列进行消元处理，最终变为阶梯矩阵。其中某一列不满足时直接退出循环
	if(!flag)
		printf("Error");
	else
	{
		solve();    //对于阶梯矩阵，解方程
		for(k = 0; k < N; k++)
			printf("%.2lf\n", x[k]);
	}
	return 0;
}
