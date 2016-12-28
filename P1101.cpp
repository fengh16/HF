#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int N, i;
typedef struct abc
{
	int num;
	struct abc* next;
} Node;
Node* head = NULL;
Node* NewNode;
Node* NowNode = NULL;
Node* removeDuplicates(Node* head)
{
	NowNode = head;
	if (NowNode->next == NULL)
		return head;
	NewNode = NowNode->next;
	while (NewNode->next != NULL)
	{
		if (NowNode->num == NewNode->num)
		{
			NewNode = NewNode->next;
			free(NowNode->next);
			NowNode->next = NewNode;
		}
		else
		{
			NowNode = NewNode;
			NewNode = NewNode->next;
		}
	}
	if (NowNode->num == NewNode->num)
	{
		NowNode->next = NULL;
		free(NewNode);
	}
	return head;
}
int main()
{
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		NewNode = (Node *) malloc(sizeof(Node));
		scanf("%d", &NewNode->num);
		NewNode->next = NULL;
		if (head == NULL)
			head = NewNode;
		else if (head->next == NULL)
		{
			NowNode = NewNode;
			head->next = NowNode;
		}
		else
			NowNode = (NowNode->next = NewNode);
	}
	head = removeDuplicates(head);
	while (head != NULL)
	{
		printf("%d ", head->num);
		NowNode = head;
		head = head->next;
		free(NowNode);
	}
	return 0;
}