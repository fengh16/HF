#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int N1, N2, i;
typedef struct abc
{
	int num;
	struct abc* next;
}Node;
Node* head1 = NULL;
Node* head2 = NULL;
Node* head = NULL;
Node* NewNode;
Node* NowNode;
Node* intersect(Node* head1, Node* head2)
{
	while (head1 != NULL && head2 != NULL)
	{
		if (head1->num < head2->num)
		{
			NewNode = head1;
			head1 = head1->next;
			free(NewNode);
		}
		else if (head1->num > head2->num)
		{
			NewNode = head2;
			head2 = head2->next;
			free(NewNode);
		}
		else
		{
			if (head == NULL)
			{
				head = NowNode = head1;
			}
			else
			{
				NowNode = NowNode->next = head1;
			}
			head1 = head1->next;
			NowNode->next = NULL;
			NewNode = head2;
			head2 = head2->next;
			free(NewNode);
		}
	}
	while (head1 != NULL)
	{
		NewNode = head1;
		head1 = head1->next;
		free(NewNode);
	}
	while (head2 != NULL)
	{
		NewNode = head2;
		head2 = head2->next;
		free(NewNode);
	}
	return head;
}
int main()
{
	scanf("%d", &N1);
	for (i = 0; i < N1; i++)
	{
		NewNode = (Node *) malloc(sizeof(Node));
		scanf("%d", &NewNode->num);
		NewNode->next = NULL;
		if (head1 == NULL)
			head1 = NewNode;
		else if (head1->next == NULL)
		{
			NowNode = NewNode;
			head1->next = NowNode;
		}
		else
			NowNode = (NowNode->next = NewNode);
	}
	scanf("%d", &N2);
	for (i = 0; i < N2; i++)
	{
		NewNode = (Node *) malloc(sizeof(Node));
		scanf("%d", &NewNode->num);
		NewNode->next = NULL;
		if (head2 == NULL)
			head2 = NewNode;
		else if (head2->next == NULL)
		{
			NowNode = NewNode;
			head2->next = NowNode;
		}
		else
			NowNode = (NowNode->next = NewNode);
	}
	head = intersect(head1, head2);
	while (head != NULL)
	{
		printf("%d ", head->num);
		NewNode = head;
		head = head->next;
		free(NewNode);
	}
	return 0;
}