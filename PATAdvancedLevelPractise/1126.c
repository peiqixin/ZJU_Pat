#include <stdio.h>
#include <string.h>

int Graph[500][500];
int N, M;
int OddCount = 0, Count = 0;
int Degree[500];
int visit[500];

void Init()
{
	int i;
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++)
		memset(Graph[i], 0, sizeof(int) * N);
	for(i = 0; i < M; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		v1--;
		v2--;
		Graph[v1][v2] = Graph[v2][v1] = 1;
	}
	memset(visit, 0, sizeof(int) * N);
}

void CalculateDegree()
{
	memset(Degree, 0, sizeof(int) * N);
	int i, j;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			if(Graph[i][j] == 1)
				Degree[j]++;
	for(i = 0; i < N; i++)
		if(Degree[i] % 2)
			OddCount++;
}

void DFS(int v)
{
	visit[v] = 1;
	int w;
	for(w = 0; w < N; w++)
		if(!visit[w] && Graph[v][w] == 1)
			DFS(w);
	Count++;
}

void Print()
{
	int i;
	DFS(0);
	for(i = 0; i < N; i++)
	{
		printf("%d", Degree[i]);
		if(i != N - 1)
			printf(" ");
	}
	printf("\n");
	if(Count == N && OddCount == 0)
		printf("Eulerian\n");
	else if(Count == N && OddCount == 2)
		printf("Semi-Eulerian\n");
	else
		printf("Non-Eulerian\n");
}

int main(int argc, char const *argv[])
{
	Init();
	CalculateDegree();
	Print();
	return 0;
}