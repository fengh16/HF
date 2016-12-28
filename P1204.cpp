#include<stdio.h>
#include<stdlib.h>
typedef struct Student
{
	int num;
	struct Student * next;
} S;
int main()
{
	int n, m, t = 1;
	scanf("%d%d", &n, &m);
	int i;
	S* temp;
	S *now;
	S *head;
	for(i = 1; i < n + 1; i++)
	{
		temp = (S*)malloc(sizeof(S));
		temp->num = i;
		if(i == 1)
			now = head = temp;
		else
			now = now->next = temp;
	}
	now = (now->next = head);
	while(now->next != now)
	{
		if(t == m)
		{
			now->num = n;
			break;
		}
		else if(t == m - 1)
		{
			temp = now->next;
			now = now->next = temp->next;
			free(temp);
			t = 0;
		}
		else
			now = now->next;
		t = (t + 1) % m;
	}
	printf("%d", now->num);
	return 0;
}
