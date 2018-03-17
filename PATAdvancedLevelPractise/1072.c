#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 1024
#define INF 0x7fffffff

// 最后一个测试点未通过
typedef struct GraphNode *Graph;
struct GraphNode
{
	int G[MAX][MAX];
	int vexnum;
	int arcnum;
};

void Insert(Graph graph, int v1, int v2, int weight)
{
	graph->G[v1][v2] = weight;
	graph->G[v2][v1] = weight;
}

Graph BuildGraph(int Nv, int M, int Ne)
{
	Graph graph = (Graph)malloc(sizeof(struct GraphNode));
	graph->vexnum = Nv + M;
	graph->arcnum = Ne;
	int i, weight, v1, v2, j;
	for(i = 0; i < graph->vexnum; i++)
		for(j = 0; j < graph->vexnum; j++)
			graph->G[i][j] = INF;

	char s1[2], s2[2];
	for(i = 0; i < graph->arcnum; i++){
		scanf("%s %s %d", s1, s2, &weight);
		if(isalpha(s1[0]))
			v1 = s1[1] - '1' + Nv;
		else
			v1 = s1[0] - '1';
		if(isalpha(s2[0]))
			v2 = s2[1] - '1' + Nv;
		else
			v2 = s2[0] - '1';
		Insert(graph, v1, v2, weight);
	}
	return graph;
}

int FindMin(Graph graph, int Dist[], int collected[])
{
	int minDist = INF;
	int min, i;
	for(i = 0; i < graph->vexnum; i++)
		if(!collected[i] && Dist[i] < minDist)
		{
			min = i;
			minDist = Dist[i];
		}
	if(minDist < INF)
		return min;
	else
		return -1;
}

int main(int argc, char const *argv[])
{
	int N, M, K, D;
	scanf("%d %d %d %d", &N, &M, &K, &D);
	Graph graph = BuildGraph(N, M, K);
	int j;
	double finalTotalWeight = INF;
	int finalMinDist = -1;
	int MinIndex;
	for(j = N; j < N + M; j++)
	{
		// dijkstra
		int collected[N + M];
		int Dist[N + M];
		int i;
		for(i = 0; i < N + M; i++)
		{
			Dist[i] = graph->G[j][i];
			collected[i] = 0;
		}
		collected[j] = 1;
		Dist[j] = 0;
		while(1)
		{
			int v = FindMin(graph, Dist, collected);
			if(v == -1) break;
			collected[v] = 1;
			int w;
			for(w = 0; w < N + M; w++)
			{
				if(!collected[w] && graph->G[v][w] < INF){
					if(Dist[w] > Dist[v] + graph->G[v][w])
						Dist[w] = Dist[v] + graph->G[v][w];
				}
			}
		}
		double totalWeight = 0;
		int minDist = INF;
		int flag = 1;
		for(i = 0; i < N; i++){
			if(Dist[i] > D){
				flag = 0;
				break;
			}
			totalWeight += Dist[i];
			if(Dist[i] < minDist)
				minDist = Dist[i];
		}
		if(flag == 1){
			if(minDist > finalMinDist){
				finalMinDist = minDist;
				finalTotalWeight = totalWeight;
				MinIndex = j - N + 1;
			}else if(minDist == finalMinDist){
				if(finalTotalWeight / N > totalWeight / N){
					finalTotalWeight = totalWeight;
					MinIndex = j - N + 1;
				}
			}
		}
	}
	if(finalMinDist == -1)
		printf("No Solution\n");
	else
		printf("G%d\n%d.0 %0.1f\n", MinIndex, finalMinDist, finalTotalWeight / N);
	return 0;
}