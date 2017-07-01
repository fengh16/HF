#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int N_A, N_B, A[1000], B[1000], IS[1000], Union[2000], C[2000], i_a, i_b, i_is = 0, i_u = 0, i_c = 0;
void doIS()
{
	i_a = 0;
	i_b = 0;
	while(i_a < N_A && i_b < N_B)
	{
		if(A[i_a] < B[i_b])
		{
			i_a++;
		}
		if(A[i_a] > B[i_b] && i_a < N_A)
		{
			i_b++;
		}
		if(A[i_a] == B[i_b] && i_a < N_A && i_b < N_B)
		{
			IS[i_is] = B[i_b];
			i_is++;
			i_a++;
			i_b++;
		}
	}
}
void doUnion()
{
	i_a = 0;
	i_b = 0;
	while(i_a < N_A && i_b < N_B)
	{
		if(A[i_a] < B[i_b])
		{
			Union[i_u] = A[i_a];
			i_u++;
			i_a++;
		}
		if(A[i_a] > B[i_b] && i_a < N_A)
		{
			Union[i_u] = B[i_b];
			i_u++;
			i_b++;
		}
		if(A[i_a] == B[i_b] && i_a < N_A && i_b < N_B)
		{
			Union[i_u] = B[i_b];
			i_u++;
			i_a++;
			i_b++;
		}
	}
	if(i_a < N_A)
	{
		for(; i_a < N_A; i_a++)
		{
			Union[i_u] = A[i_a];
			i_u++;
		}
	}
	if(i_b < N_B)
	{
		for(; i_b < N_B; i_b++)
		{
			Union[i_u] = B[i_b];
			i_u++;
		}
	}
}
void doC()
{
	i_a = 0;
	i_b = 0;
	while(i_a < N_A && i_b < N_B)
	{
		if(A[i_a] < B[i_b])
		{
			C[i_c] = A[i_a];
			i_c++;
			i_a++;
		}
		if(A[i_a] > B[i_b] && i_a < N_A)
		{
			i_b++;
		}
		if(A[i_a] == B[i_b] && i_a < N_A && i_b < N_B)
		{
			i_a++;
			i_b++;
		}
	}
	if(i_a < N_A)
	{
		for(; i_a < N_A; i_a++)
		{
			C[i_c] = A[i_a];
			i_c++;
		}
	}
}
int main()
{
	scanf("%d", &N_A);
	for(i_a = 1; i_a <= N_A; i_a++)
	{
		scanf("%d", &A[i_a - 1]);
	}
	scanf("%d", &N_B);
	for(i_b = 1; i_b <= N_B; i_b++)
	{
		scanf("%d", &B[i_b - 1]);
	}
	int i, Num_Compare, Num_Move;
	for(i = 0; i <= N_A - 1; i++)
	{
		for(Num_Compare = 0; Num_Compare < i;)
		{
			if (A[Num_Compare] >= A[i]) break;
			Num_Compare ++;
		}
		if (Num_Compare < i)
		{
			A[N_A + 1] = A[i];
			for(Num_Move = i ; Num_Move >= Num_Compare + 1; Num_Move --)
			{
				A[Num_Move] = A[Num_Move - 1];
			}
			A[Num_Compare] = A[N_A + 1];
		}
	}
	for(i = 0; i <= N_B - 1; i++)
	{
		for(Num_Compare = 0; Num_Compare < i;)
		{
			if (B[Num_Compare] >= B[i]) break;
			Num_Compare ++;
		}
		if (Num_Compare < i)
		{
			B[N_B + 1] = B[i];
			for(Num_Move = i ; Num_Move >= Num_Compare + 1; Num_Move --)
			{
				B[Num_Move] = B[Num_Move - 1];
			}
			B[Num_Compare] = B[N_B + 1];
		}
	}
	doIS();
	doUnion();
	doC();
	for(i_a = 0; i_a < i_is; i_a++)
	{
		printf("%d ", IS[i_a]);
	}
	printf("\n");
	for(i_a = 0; i_a < i_u; i_a++)
	{
		printf("%d ", Union[i_a]);
	}
	printf("\n");
	for(i_a = 0; i_a < i_c; i_a++)
	{
		printf("%d ", C[i_a]);
	}
	return 0;
}