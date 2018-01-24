#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int num[N], i;
	for(i = 0; i < N; i++)
		scanf("%d", &num[i]);
	qsort(num, N, sizeof(int), cmp);
	int count = 0;
	for(i = 0; i < N; i++)
	{
		if(num[i] > count + 1)
			count++;
	}
	printf("%d\n", count);
	return 0;
}