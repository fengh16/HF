#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct STUDENT
{
	long long ID;
	char Name[15];
	char Gender[10];
	int Score;
	int rank0;
	int Num;//重名个数
	struct STUDENT * Next;
}student;
int M, N, i, t, k, p, temp_rank;
char NoUse[4];
student* temp;
student**Rank;
int main()
{
	scanf("%d", &M);
	Rank = (student**)malloc(M * sizeof(student*));
	for(i = 0; i < M; i++)
	{
		temp = (student*)malloc(sizeof(student));
		scanf("%lld%s%s%d", &temp->ID, temp->Name, temp->Gender, &temp->Score);
		temp->Num = 1;
		temp->Next = NULL;
		for(t = 0; t < i && Rank[t]->Score > temp->Score; t++);
		if(t < i)
		{
			if(Rank[t]->Score == temp->Score)
			{
				for(k = t + 1; k < t + Rank[t]->Num; k++)
					Rank[k]->Num++;
				Rank[t]->Num++;
				temp->Num = Rank[t]->Num;
				for(;t < i && Rank[t]->Score == temp->Score && Rank[t]->ID < temp->ID; t++);
			}
			temp->Next = Rank[t];
			if(t)
			{
				Rank[t - 1]->Next = temp;
				for(k = t - 1; k < i; k++)
					Rank[k + 1] = Rank[k]->Next;
			}
			else
			{
				Rank[0] = temp;
				for(k = 0; k < i; k++)
					Rank[k + 1] = Rank[k]->Next;
			}
		}
		else if(t == 0)
			Rank[0] = temp;
		else
		{
			Rank[i] = Rank[i - 1]->Next = temp;
		}
	}
	p = 0;
	for(i = 0; i < M; i++)
	{
		if(Rank[i]->Num == 0)
			Rank[i]->rank0 = i + 1;
		else
		{
			if(p--)
				Rank[i]->rank0 = temp_rank;
			else
			{
				p = Rank[i]->Num - 1;
				Rank[i]->rank0 = temp_rank = i + 1;
			}
		}
	}
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%s", NoUse);
		scanf("%d", &t);
		if(t > M || t <= 0)
			continue;
		if(Rank[t - 1] != NULL)
		{
			k = Rank[t - 1]->Num;
			while(k-- && t + k - 1 < M && Rank[t + k - 1]->rank0 == t)
				Rank[t + k - 1] = NULL;
		}
	}
	for(i = 0; i < M; i++)
	{
		if(Rank[i] != NULL)
			printf("%lld %s %s %d\n", Rank[i]->ID, Rank[i]->Name, Rank[i]->Gender, Rank[i]->Score);
	}
	return 0;
}
