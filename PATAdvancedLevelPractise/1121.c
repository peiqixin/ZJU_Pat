#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(int argc, char const *argv[])
{
	int Object[100000], N, M, i;
	scanf("%d", &N);
	memset(Object, -1, sizeof(int) * 100000);
	for(i = 0; i < N; i++)
	{
		int m, w;
		scanf("%d %d", &m, &w);
		Object[m] = w;
		Object[w] = m;
	}
	scanf("%d", &M);
	int SingleCount = 0, BanquetStack[M], SingleStack[M];
	int BanquetList[100000];
	memset(BanquetList, 0, sizeof(int) * 100000);
	for(i = 0; i < M; i++)
	{
		int guest;
		scanf("%d", &guest);
		BanquetList[guest] = 1;
		BanquetStack[i] = guest;
	}
	for(i = 0; i < M; i++)
		// 如果没有对象 或者有对象但是对象没参加宴会，则被加入单身狗行列
		if(Object[BanquetStack[i]] == -1 || !BanquetList[Object[BanquetStack[i]]])  
			SingleStack[SingleCount++] = BanquetStack[i];

	qsort(SingleStack, SingleCount, sizeof(int), cmp);
	printf("%d\n", SingleCount);
	if(SingleCount == 0) return 0;
	for(i = 0; i < SingleCount; i++)
	{
		printf("%05d", SingleStack[i]);
		if(i != SingleCount - 1)
			printf(" ");
	}
	printf("\n");
	return 0;
}