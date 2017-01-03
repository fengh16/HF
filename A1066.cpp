#include<stdio.h>
#include<stdlib.h>
int n, m, i, a, b, p, q, ans;
int *nums;
int *t;
int main()
{
	scanf("%d%d", &n, &m);
	t = (int*)malloc((n + 1) * sizeof(int));
	nums = (int*)malloc((n + 1) * sizeof(int));
	ans = n;
	for (i = 1; i <= n; i++)
	{
		t[i] = i;
		nums[i] = 1;
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		if (t[a] == t[b])
			continue;
		if (a > n || a < 1 || b > n || b < 1)
			continue;
		if (nums[t[a]] <= nums[t[b]])
		{
			p = t[a];
			t[a] = t[b];
			nums[t[b]]++;
			ans--;
			if (--nums[p])
			{
				for (q = 1; q <= n; q++)
				{
					if (t[q] == p)
					{
						t[q] = t[b];
						nums[t[b]]++;
						if (!(--nums[p]))
							break;
					}
				}
			}
		}
		else
		{
			p = t[b];
			t[b] = t[a];
			nums[t[a]]++;
			ans--;
			if (--nums[p])
			{
				for (q = 1; q <= n; q++)
				{
					if (t[q] == p)
					{
						t[q] = t[a];
						nums[t[a]]++;
						if (!(--nums[p]))
							break;
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}