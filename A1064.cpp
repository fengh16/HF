#include<stdio.h>
/*5���̷۳����ڽ��ڵ�һ���������Ȼ�зֻ�ǰ5��������ǰ��Ҿ��Ѿ�֪��E���϶����ǵ�2���͵�3����
����A���Ĵ���£�E���Ĳ�Ʒ�Ȼ��1��
����B���Ĵ���£��ҳ����ܻ��2��
����C���Ĵ���£�A�����������
����D���Ĵ���£�C���Ĳ�Ʒ������õ�
����E���Ĵ���£�D������1��
�������Ƚ���������֣�ֻ�л��1���͵�2�����������Ĵ���¶��ˡ��������A��B��C��D��E���ǵڼ�����*/
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