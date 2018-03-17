#include <stdio.h>
#include <stdlib.h>

// 一个测试点未通过
int N, p;
int Nums[100000];

int cmp(const void *a, const void *b)
{
	return (*(long int *)a - *(long int *)b);
}

void Init()
{
	int i;
	scanf("%d %d", &N, &p);
	for(i = 0; i < N; i++)
		scanf("%d", &Nums[i]);
	qsort(Nums, N, sizeof(int), cmp);
}

void Solve()
{
	int count, i, min;
	if(Nums[N - 1] % p == 0)
		min = Nums[N - 1] / p;
	else
		min = Nums[N - 1] / p + 1;
	for(i = 0; i < N; i++)
		if(Nums[i] >= min)
			break;
	count = N - i;
	int max = Nums[0] * p;
	for(i = N - 1; i >= 0; i--)
		if(Nums[i] <= max)
			break;
	count = count > i + 1? count : i + 1;
	printf("%d\n", count);
}

int main(int argc, char const *argv[])
{
	Init();
	Solve();
	return 0;
}