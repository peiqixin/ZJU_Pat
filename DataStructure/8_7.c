//08-图7 公路村村通
/*
	现有村落间道路的统计数据表中，列出了有可能建设成标准公路的若干条道路的成本，求使每个村落都有公路连通所需要的最低成本。

	输入格式:

	输入数据包括城镇数目正整数NN（\le 1000≤1000）和候选道路数目MM（\le 3N≤3N）；随后的MM行对应MM条道路，每行给出3个正整数，分别是该条道路直接连通的两个城镇的编号以及该道路改建的预算成本。为简单起见，城镇从1到NN编号。

	输出格式:

	输出村村通需要的最低成本。如果输入数据不足以保证畅通，则输出-1−1，表示需要建设更多公路。

	输入样例:

	6 15
	1 2 5
	1 3 3
	1 4 7
	1 5 4
	1 6 2
	2 3 4
	2 4 6
	2 5 2
	2 6 6
	3 4 6
	3 5 1
	3 6 1
	4 5 10
	4 6 8
	5 6 3
	输出样例:

	12
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxVertextNum 1000
#define INFINITY 65535

typedef int Vertex;
typedef int WeightType;
typedef struct ENode * PtrToENode;
struct ENode
{
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct GNode * PtrToGNode;
struct GNode
{
	int Nv;
	int Ne;
	WeightType Matrix[MaxVertextNum][MaxVertextNum];
};
typedef PtrToGNode MGraph;

typedef struct AdjVNode * PtrToAdjVNode;
struct AdjVNode
{
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
};

typedef struct VNode * PtrToVNode;
struct VNode
{
	PtrToAdjVNode FirstEdge;
};

typedef struct MSTNode *PtrToMSTNode;
struct MSTNode
{
	PtrToVNode list[MaxVertextNum];
	int Nv;
	int Ne;
};
typedef PtrToMSTNode LGraph;

MGraph BuildGraph(int Nv, int Ne);
MGraph CreateGraph(int Nv);
void InsertEdge(MGraph Graph, Edge E);
int Prim(MGraph Graph, LGraph MST);
Vertex FindMinDist(MGraph Graph, WeightType dist[]);
LGraph CreateLGraph(int Nv);
void InsertLEdge(LGraph Graph, Edge E);

int main(int argc, char const *argv[])
{
	int Nv, Ne;
	scanf("%d %d", &Nv, &Ne);
	MGraph Graph = BuildGraph(Nv, Ne);
	LGraph MST;
	printf("%d\n", Prim(Graph, MST));
	return 0;
}

MGraph BuildGraph(int Nv, int Ne)
{
	MGraph Graph;
	Edge E;
	Graph = CreateGraph(Nv);
	Graph->Ne = Ne;
	int i;
	if(Graph->Ne != 0){
		E = malloc(sizeof(struct ENode));
		for(i = 0; i < Graph->Ne; i++){
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			E->V1--;
			E->V2--;
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}

MGraph CreateGraph(int Nv)
{
	MGraph Graph;
	Graph = malloc(sizeof(struct GNode));
	Graph->Nv = Nv;
	Graph->Ne = 0;
	int i, j;
	for(i = 0; i < Graph->Nv; i++)
		for(j = 0; j <Graph->Nv; j++){
			Graph->Matrix[i][j] = INFINITY;
		}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->Matrix[E->V1][E->V2] = E->Weight;
	Graph->Matrix[E->V2][E->V1] = E->Weight;
}

int Prim(MGraph Graph, LGraph MST)
{
	WeightType dist[MaxVertextNum], TotalWeight;
	Vertex V, W, parent[MaxVertextNum];
	for(V = 0; V < Graph->Nv; V++){
		dist[V] = Graph->Matrix[0][V];
		parent[V] = 0;
	}

	TotalWeight = 0;
	int VCount = 1;
	dist[0] = 0;
	parent[0] = -1;
	MST = CreateLGraph(Graph->Nv);
	Edge E;
	E = malloc(sizeof(struct ENode));

	while(1){
		V = FindMinDist(Graph, dist);
		if(V == -1)
			break;

		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertLEdge(MST, E);

		TotalWeight += dist[V];
		dist[V] = 0;
		VCount++;
		for(W = 0 ; W < Graph->Nv; W++){
			if(dist[W] != 0 && Graph->Matrix[V][W] < INFINITY){
				if(Graph->Matrix[V][W] < dist[W]){
					dist[W] = Graph->Matrix[V][W];
					parent[W] = V;
				}
			}
		}
	}
	if(VCount < Graph->Nv)
		return -1;
	else
		return TotalWeight;
}

Vertex FindMinDist(MGraph Graph, WeightType dist[])
{
	Vertex V, MinV;
	WeightType MinDist = INFINITY;
	for(V = 0; V < Graph->Nv; V++){
		if(dist[V] < MinDist && dist[V] != 0){
			MinDist = dist[V];
			MinV = V;
		}
	}
	if(MinDist < INFINITY)
		return MinV;
	else
		return -1;
}

LGraph CreateLGraph(int Nv)
{
	LGraph Graph;
	Graph = malloc(sizeof(struct MSTNode));
	Graph->Nv = Nv;
	Graph->Ne = 0;
	int i;
	for(i = 0; i < Graph->Nv; i++)
		Graph->list[i]->FirstEdge = NULL;
	return Graph;
}

void InsertLEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode AdjNode;
	AdjNode = malloc(sizeof(struct AdjVNode));
	AdjNode->Weight = E->Weight;
	AdjNode->AdjV = E->V2;
	AdjNode->Next = Graph->list[E->V1]->FirstEdge;
	Graph->list[E->V1]->FirstEdge = AdjNode;
}