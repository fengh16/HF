#include <stdio.h>
char nums[24][10] = { {"zero"}, {"one"}, {"two"}, {"three"}, {"four"}, {"five"}, {"six"}, {"seven"}, {"eight"}, {"nine"}, {"ten"}, {"eleven"}, {"twelve"}, {"thirteen"}, {"fourteen"}, {"fifteen"}, {"sixteen"}, {"seventeen"}, {"eighteen"}, {"nineteen"}, {"twenty"}, {"thirty"}, {"forty"}, {"fifty"} };
int main()
{
	int h, m;
	scanf("%d%d", &h, &m);
	if (h < 21)
		printf("%s ", nums[h]);
	else
		printf("%s %s ", nums[20], nums[h - 20]);
	if (m == 0)
		printf("o'clock");
	else if (m < 21)
		printf("%s", nums[m]);
	else if (m < 30)
		printf("%s %s", nums[20], nums[m - 20]);
	else if (m == 30)
		printf("%s", nums[21]);
	else if (m < 40)
		printf("%s %s", nums[21], nums[m - 30]);
	else if (m == 40)
		printf("%s", nums[22]);
	else if (m < 50)
		printf("%s %s", nums[22], nums[m - 40]);
	else if (m == 50)
		printf("%s", nums[23]);
	else
		printf("%s %s", nums[23], nums[m - 50]);
	return 0;
}