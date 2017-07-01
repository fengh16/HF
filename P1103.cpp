#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int N1, N2, i;
typedef struct abc
{
	int num;
	int degree;
	struct abc* next;
} Node;
Node* head1 = NULL;
Node* head2 = NULL;
Node* head = NULL;
Node* NewNode;
Node* NowNode;
void CreateNode()
{
	scanf("%d", &N1);
	for (i = 0; i < N1; i++)
	{
		NewNode = (Node *) malloc(sizeof(Node));
		scanf("%d%d", &NewNode->num, &NewNode->degree);
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
		scanf("%d%d", &NewNode->num, &NewNode->degree);
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
}
void PrintNodes()
{
	printf("%d\n", i);
	while (head != NULL)
	{
		printf("%d %d\n", head->num, head->degree);
		NewNode = head;
		head = head->next;
		free(NewNode);
	}
}
void AddNodes()
{
	i = 0;
	while (head1 != NULL && head2 != NULL)
	{
		if (head1->degree < head2->degree)
		{
			if(head == NULL)
				head = NowNode = head1;
			else
				NowNode = NowNode->next = head1;
			head1 = head1->next;
			NowNode->next = NULL;
		}
		else if (head1->degree > head2->degree)
		{
			if(head == NULL)
				head = NowNode = head2;
			else
				NowNode = NowNode->next = head2;
			head2 = head2->next;
			NowNode->next = NULL;
		}
		else
		{
			head1->num += head2->num;
			if(head1->num != 0)
			{
				if(head == NULL)
					head = NowNode = head1;
				else
					NowNode = NowNode->next = head1;
				head1 = head1->next;
				NowNode->next = NULL;
			}
			else
			{
				NewNode = head1;
				head1 = head1->next;
				free(NewNode);
				i--;
			}
			NewNode = head2;
			head2 = head2->next;
			free(NewNode);
		}
		i++;
	}
	while (head1 != NULL)
	{
		if(head == NULL)
			head = NowNode = head1;
		else
			NowNode = NowNode->next = head1;
		head1 = head1->next;
		NowNode->next = NULL;
		i++;
	}
	while (head2 != NULL)
	{
		if(head == NULL)
			head = NowNode = head2;
		else
			NowNode = NowNode->next = head2;
		head2 = head2->next;
		NowNode->next = NULL;
		i++;
	}
}
int main()
{
	CreateNode();
	AddNodes();
	PrintNodes();
	return 0;
}