#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(int argc, char const *argv[])
{
	int N, i;
	scanf("%d", &N);
	int Num[N];
	for(i = 0; i < N; i++)
		scanf("%d", &Num[i]);
	qsort(Num, N, sizeof(int), cmp);
	double len = Num[0];
	for(i = 1; i < N; i++)
		len = (len + Num[i]) / 2;
	printf("%d\n", (int)len);
	return 0;
}