// 07-图6 旅游规划
/*
	有了一张自驾旅游路线图，你会知道城市间的高速公路长度、以及该公路要收取的过路费。现在需要你写一个程序，帮助前来咨询的游客找一条出发地和目的地之间的最短路径。如果有若干条路径都是最短的，那么需要输出最便宜的一条路径。

	输入格式:

	输入说明：输入数据的第1行给出4个正整数NN、MM、SS、DD，其中NN（2\le N\le 5002≤N≤500）是城市的个数，顺便假设城市的编号为0~(N-1N−1)；MM是高速公路的条数；SS是出发地的城市编号；DD是目的地的城市编号。随后的MM行中，每行给出一条高速公路的信息，分别是：城市1、城市2、高速公路长度、收费额，中间用空格分开，数字均为整数且不超过500。输入保证解的存在。

	输出格式:

	在一行里输出路径的长度和收费总额，数字间以空格分隔，输出结尾不能有多余空格。

	输入样例:

	4 5 0 3
	0 1 1 20
	1 3 2 30
	0 3 4 10
	0 2 2 20
	2 3 1 20
	输出样例:

	3 40
*/

#include <stdio.h>
#include <stdlib.h>
#define MaxVertextNum 500
#define INFINITY 65535

typedef int Vertex;
typedef int WeightType;

typedef struct ENode *PtrToENode;
struct ENode
{
	Vertex V1, V2;
	WeightType Length, Charge;
};
typedef PtrToENode Edge;

typedef struct GNode * PtrToGNode;
struct GNode
{
	int Nv;
	int Ne;
	WeightType Length[MaxVertextNum][MaxVertextNum];
	WeightType Charge[MaxVertextNum][MaxVertextNum];
};
typedef PtrToGNode MGraph;

MGraph BuildGraph(int Nv, int Ne);
MGraph CreateGraph(int Nv);
void InsertEdge(MGraph Graph, Edge E);
void Dijkstra(MGraph Graph, int S, int D[], int charge[]);
Vertex FindMin(MGraph Graph, Vertex D[], int collected[]);
void Solve(MGraph Graph, Vertex S, Vertex D);

int main(int argc, char const *argv[])
{

	int N, M, S, D;
	scanf("%d %d %d %d", &N, &M, &S, &D);
	MGraph Graph = BuildGraph(N, M);
	Solve(Graph, S, D);
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
			scanf("%d %d %d %d", &E->V1, &E->V2, &E->Length, &E->Charge);
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
			Graph->Charge[i][j] = INFINITY;
			Graph->Length[i][j] = INFINITY;
		}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->Length[E->V1][E->V2] = E->Length;
	Graph->Length[E->V2][E->V1] = E->Length;
	Graph->Charge[E->V1][E->V2] = E->Charge;
	Graph->Charge[E->V2][E->V1] = E->Charge;
}

void Dijkstra(MGraph Graph, int S, int D[], int charge[])
{

	Vertex Path[Graph->Nv], V, W;
	int i;
	int collected[Graph->Nv];
	for(i = 0; i < Graph->Nv; i++){
		D[i] = Graph->Length[S][i];
		charge[i] = Graph->Charge[S][i];
		if(D[i] < INFINITY)
			Path[i] = S;
		else
			Path[i] = -1;
		collected[i] = 0;
	}
	Path[S] = 0;
	D[S] = 0;
	charge[S] = 0;
	collected[S] = 1;
	while(1){
		V = FindMin(Graph, D, collected);
		if(V == -1)
			break;
		collected[V] = 1;
		for(W = 0; W < Graph->Nv; W++){
			if(collected[W] != 1 && Graph->Length[V][W] < INFINITY){
				if(D[V] + Graph->Length[V][W] < D[W]){
					D[W] = D[V] + Graph->Length[V][W];
					Path[W] = V;
					charge[W] = charge[V] + Graph->Charge[V][W];
				}else if(D[V] + Graph->Length[V][W] == D[W]){
					if(charge[V] + Graph->Charge[V][W] < charge[W]){
						D[W] = D[V] + Graph->Length[V][W];
						Path[W] = V;
						charge[W] = charge[V] + Graph->Charge[V][W];
					}
				}
			}
		}
	}
}

Vertex FindMin(MGraph Graph, Vertex D[], int collected[])
{
	Vertex V, MinV;
	int MinDist = INFINITY;
	for(V = 0; V < Graph->Nv; V++){
		if(collected[V] != 1 && D[V] < MinDist){
			MinDist = D[V];
			MinV = V;
		}
	}
	if(MinDist < INFINITY)
		return MinV;
	else
		return -1;
}

void Solve(MGraph Graph, Vertex S, Vertex D)
{
	int Length[Graph->Nv], charge[Graph->Nv];
	Dijkstra(Graph, S, Length, charge);
	printf("%d %d\n", Length[D], charge[D]);
}