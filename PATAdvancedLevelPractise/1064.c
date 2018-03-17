#include <stdio.h>
#include <stdlib.h>
int N， pos = 0, CBT[1000], T[1000];
int cmp(const void *a, const void *b)
{
	return (*(int *)a > *(int *)b);
}
void Build(int root, int CBT[], int T[])
{
	if(root >= N) return;
	int left = root * 2 + 1;
	int right  = left + 1;

	Build(left, pos, CBT, T);
	T[root] = CBT[pos++];
	Build(right, pos, CBT, T);
}

void Print(int T[], int N)
{
	printf("%d", T[0]);
	for(int i = 1; i < N; i++)
		printf(" %d", T[i]);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &CBT[i]);
	qsort(CBT, N, sizeof(int), cmp);
	Build(0, CBT, T);
	Print(T, N);
	return 0;
}