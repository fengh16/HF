#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int N1, N2, i;
typedef struct donode
{
	int num;
	struct donode* next;
} Node;
typedef struct ppp
{
	int num;
	int OperatorNum;
	struct ppp* next;
} LB;
Node* head1 = NULL;
LB* head2 = NULL;
Node* NewNode;
LB* NewNodeB;
Node* NowNode;
LB* NowNodeB;
void CreateNode()
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
		NewNodeB = (LB *) malloc(sizeof(LB));
		scanf("%d%d", &NewNodeB->num, &NewNodeB->OperatorNum);
		NewNodeB->next = NULL;
		if (head2 == NULL)
			head2 = NewNodeB;
		else if (head2->next == NULL)
		{
			NowNodeB = NewNodeB;
			head2->next = NowNodeB;
		}
		else
			NowNodeB = (NowNodeB->next = NewNodeB);
	}
}
void PrintNodes()
{
	while (head1 != NULL)
	{
		printf("%d\n", head1->num);
		NewNode = head1;
		head1 = head1->next;
		free(NewNode);
	}
}
void AddNodes()
{
	NewNode = (Node *) malloc(sizeof(Node));
	NewNode->num = head2->num;
	NewNode->next = NULL;
	if(head1->num >= head2->num)
	{
		NewNode->next = head1;
		head1 = NewNode;
	}
	else
	{
		for (NowNode = head1; NowNode->next != NULL; NowNode = NowNode->next)
		{
			 if(NowNode->num < head2->num && NowNode->next->num >= head2->num)
				 break;
		}
		NewNode->next = NowNode->next;
		NowNode->next = NewNode;
	}
	NewNodeB = head2;
	head2 = head2->next;
	free(NewNodeB);
}
void DeleteNodes()
{
	if(head1->num == head2->num)
	{
		NewNode = head1;
		head1 = head1->next;
		free(NewNode);
	}
	else
	{
		for (NowNode = head1; NowNode->next != NULL; NowNode = NowNode->next)
		{
			 if(NowNode->next->num == head2->num)
				 break;
		}
		if(NowNode->next != NULL && NowNode->next->num == head2->num)
		{
			NewNode = NowNode->next;
			NowNode->next = NowNode->next->next;
			free(NewNode);
		}
	}
	NewNodeB = head2;
	head2 = head2->next;
	free(NewNodeB);
}
int main()
{
	CreateNode();
	while(head2 != NULL)
	{
		if(head2->OperatorNum == 0)
			DeleteNodes();
		else
			AddNodes();
	}
	PrintNodes();
	return 0;
}