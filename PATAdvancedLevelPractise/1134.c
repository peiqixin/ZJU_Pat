#include <stdio.h>
#include <string.h>

int N, M, Graph[10000][10000];

void Init()
{
	scanf("%d %d", &N, &M);
	int i;
	for(i = 0; i < N; i++)
		memset(Graph[i], 0, sizoef(int) * N);

	for(i = 0; i < M; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		Graph[v1][v2] = 1;
	}
}

int main(int argc, char const *argv[])
{
	Init();
	int K, i;
	scanf("%d", &K);
	for(i = 0; i < K; i++)
	{
		int nv, j;
		scanf("%d", &nv);
		for(j = 0; j < nv; j++)
		{
			
		}
	}
	return 0;
}