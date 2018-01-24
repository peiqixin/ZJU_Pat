#include <stdio.h>
#include <stdlib.h>
// 超级大水题
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int A[N], i;
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);
	qsort(A, N, sizeof(int), cmp);
	int Sum1, Sum2;
	Sum2 = Sum1 = 0;
	for(i = 0; i < N / 2; i++)
			Sum1 += A[i];
	for(; i < N; i++)
			Sum2 += A[i];
	if(N % 2 == 0)
		printf("0 %d\n", Sum2 - Sum1);
	else
		printf("1 %d\n", Sum2 - Sum1);
	return 0;
}