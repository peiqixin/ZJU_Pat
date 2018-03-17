#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
void Sort(int N, int A[])
{
	int i = 0;
	while(N != 0)
	{
		int reamin = N % 10;
		A[i++] = reamin;
		N -= reamin;
		N /= 10;
	}
}

int Max(int A[])
{
	int i;
	int res = 0;
	int radix = 1;
	for(i = 0; i < 4; i++)
	{
		res += A[i] * radix;
		radix *= 10;
	}
	return res;
}

int Min(int A[])
{
	int i;
	int res = 0;
	int radix = 1;
	for(i = 3; i >= 0; i--)
	{
		res += A[i] * radix;
		radix *= 10;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int A[4];
	int max, min;
	while(1)
	{
		memset(A, 0, sizeof(int) * 4);
		Sort(N, A);
		qsort(A, 4, sizeof(int), cmp);
		max = Max(A);
		min = Min(A);
		int res = max - min;
		printf("%04d - %04d = %04d\n", max, min, res);
		if(res == 6174 || res == 0) break;
		N = res;
	}
	return 0;
}