#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	char Name[21];
	char Sex[21];
	int Age;
	int Score;
}Student;
int main()
{
	int N, i, k, t;
	Student* m_Students;
	char temp[21];
	scanf("%d", &N);
	m_Students = (Student*)malloc(N * sizeof(Student));
	for(i = 0; i < N; i++)
	{
		scanf("%s%s%d%d", m_Students[i].Name, m_Students[i].Sex, &m_Students[i].Age, &m_Students[i].Score);
	}
	for(t = N - 1; t > 0; t--)
	{
		for(i = 0; i < t; i++)
		{
			if(m_Students[i].Score > m_Students[i + 1].Score)
			{
				strcpy(temp, m_Students[i].Name);
				strcpy(m_Students[i].Name, m_Students[i + 1].Name);
				strcpy(m_Students[i + 1].Name, temp);
				strcpy(temp, m_Students[i].Sex);
				strcpy(m_Students[i].Sex, m_Students[i + 1].Sex);
				strcpy(m_Students[i + 1].Sex, temp);
				k = m_Students[i].Age;
				m_Students[i].Age = m_Students[i + 1].Age;
				m_Students[i + 1].Age = k;
				k = m_Students[i].Score;
				m_Students[i].Score = m_Students[i + 1].Score;
				m_Students[i + 1].Score = k;
			}
		}
	}
	for(i = 0; i < N; i++)
	{
		printf("%s %s %d %d\n", m_Students[i].Name, m_Students[i].Sex, m_Students[i].Age, m_Students[i].Score);
	}
	free(m_Students);
	return 0;
}