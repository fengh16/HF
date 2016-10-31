#include<stdio.h>
double a[11][11], x[10];
/*�ڽ���ĳ����ʱ��Ҫʹ����һ����ʱ���飬Ҳ����ֱ����a�ж����һ�С�
�ڴ�����ά����ʱ�����Էֱ���A��b����Ҳ����ֱ�ӽ���������󣨿��Խ�b�ŵ�a�����һ�У�Ҳ����ֱ�ӷŵ���һ�У�������[1][1]��[10][10]Ϊ���10X10��ϵ������A����a[1][0]��a[10][0]��b�е�Ԫ�ء�*/
int row, cross, N, flag = 1; //flag�����ж��Ƿ���Ψһ�⣬
void Get_A_b()
{
	for(row = 1; row <= N; row++)
	{
		for(cross = 1; cross <= N; cross++)
		scanf("%lf", &a[row][cross]);   //�˴����ʹ��%d�����
	}
	for(row = 1; row <= N; row++)  //����b��������a[ ][0]��
		scanf("%lf", &a[row][0]);
}
void exchange(int row1, int row2)   //�ѵ�row1�к͵�row2�н���λ��
{
	int i;
	for(i = 0; i <= N; i++)    //��A��b��������ͬʱ����, a[0][i]����ʱ����
	{
		a[0][i] = a[row1][i];
		a[row1][i] = a[row2][i];
		a[row2][i] = a[0][i];
	}
}
void minus(int row_raw)   //�ѵ�row_raw��������õ�row_raw����������ȥrow_raw�е����ɱ���
{
	int i, t;
	double times;
	for(t = row_raw +1; t <= N; t++)
	{
		times = a[t][row_raw] / a[row_raw][row_raw];
		for(i = 0; i <= N; i++)    //�Ե�i�н��д��������������
			a[t][i] -= a[row_raw][i] * times;
	}
}
int echelon_form(int cross_num)
	//�Ѿ���A��cross_num�л�Ϊ�����Ǿ���ͬʱ�з���ֵ������1����û���⣬����0�������鲻������Ψһ��
{
	int h;
	if(a[cross_num][cross_num] >= -0.00001 && a[cross_num][cross_num] <= 0.00001)
		//�Խ�����Ԫ��Ϊ0����ʱ���Խ���
	{
		for(h = cross_num + 1; h <= N && a[h][cross_num] >= -0.00001 && a[h][cross_num] <= 0.00001; h++);
		//�ֱ���Խ�������û�з���Ԫ�أ�ͬʱ��h��λ����һ������Ԫ����
		if(h == N + 1)   //����Խ�����û�з���Ԫ�أ�������ѭ��һֱ����ֱ��h=N+1
			return flag = 0;
		else     //��ʱ�Ѿ��ҵ��˷���Ԫ�����ڵ�h�У�����Ҫ����h�к�cross_num��
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
void solve()   //�������Ǿ�����нⷽ��
{
	int p, q;
	for(p = N; p > 0; p--)   //�����㣬�����p����
	{
		x[p - 1] = a[p][0] / a[p][p];   //b�еĵ�p������A�е�p���Խ���Ԫ��
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
	//���ζԸ��н�����Ԫ�������ձ�Ϊ���ݾ�������ĳһ�в�����ʱֱ���˳�ѭ��
	if(!flag)
		printf("Error");
	else
	{
		solve();    //���ڽ��ݾ��󣬽ⷽ��
		for(k = 0; k < N; k++)
			printf("%.2lf\n", x[k]);
	}
	return 0;
}
