#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(int argc, char const *argv[])
{
	int i, N;
	scanf("%d", &N);
	int A[N], B[N];
	for(i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		B[i] = A[i];
	}
	qsort(A, N, sizeof(int), cmp);
	int Stack[N], top = -1;
	int maxNum = 0;
	for(i = 0; i < N; i++)
		if(B[i] > maxNum && A[i] == B[i])
		{
			Stack[++top] = B[i];
			maxNum = B[i];
		}
		else
			maxNum = maxNum > B[i] ? maxNum : B[i];
	qsort(Stack, top + 1, sizeof(int), cmp);
	printf("%d\n", top + 1);
	for(i = 0; i <= top; i++)
	{
		printf("%d", Stack[i]);
		if(i != top)
			printf(" ");
	}
	printf("\n");
	return 0;
}