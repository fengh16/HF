#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i, N;
char now[30];
typedef struct NAME
{
	char text[30];
	struct NAME *next;
} Name;
Name *head;
Name *newname;
Name *NowName;
Name *FindName = NULL;
int main()
{
	scanf("%d%s", &N, now);
	NowName = head = (Name*)malloc(sizeof(Name));
	scanf("%s", &head->text);
	head->next = NULL;
	for(i = 1; i < N; i++)
	{
		newname = (Name*)malloc(sizeof(Name));
		scanf("%s", &newname->text);
		newname->next = NULL;
		if(strcmp(newname->text, head->text) < 0)
		{
			newname->next = head;
			head = newname;
		}
		else
		{
			NowName = head;
			while(NowName->next != NULL && (!(strcmp(NowName->text, newname->text) < 0) || !(strcmp(NowName->next->text, newname->text) > 0)))
			{
				NowName = NowName->next;
			}
			newname->next = NowName->next;
			NowName->next = newname;
		}
		if(strcmp(newname->text, now) == 0)
			FindName = newname;
	}
	if(FindName->next != NULL)
		printf("%s", FindName->next->text);
	else
		printf("The End");
	return 0;
}