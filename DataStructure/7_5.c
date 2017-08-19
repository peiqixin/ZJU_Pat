// 07-图5 Saving James Bond - Hard Version
#include <stdio.h>
#include <stdlib.h>
#define MaxVertextNum 100
#define INFINITY 65535

typedef int Vertex;
typedef int WeightType;
typedef struct ENode *PtrToENode;

struct ENode
{
	Vertex V1, V2;
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

MGraph BuildGraph();
MGraph CreateGraph(int Nv);
void InsertEdge(MGraph Graph, Edge E);

int main(int argc, char const *argv[])
{
	MGraph Graph = BuildGraph();

	return 0;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	int Nv, Ne, i;
	scanf("%d %d", &Nv, &Ne);
	Graph = CreateGraph(Nv);
	Graph->Ne = Ne;
	if(Graph->Ne != 0){
		E = malloc(sizeof(struct ENode));
		for(i = 0; i < Graph->Ne; i++){
			scanf("%d %d", &E->V1, &E->V2);
			E->V1--;
			E->V2--;
			InsertEdge(Graph, E);
		}
	}
}

MGraph CreateGraph(int Nv)
{
	MGraph Graph;
	Graph = malloc(sizeof(struct GNode));
	Graph->Nv = Nv;
	Graph->Ne = 0;
	int i, j;
	for(i = 0; i < Graph->Nv; i++)
		for(j = 0; i <Graph->Nv; j++)
			Graph->Matrix[i][j] = INFINITY;
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->Matrix[E->V1][E->V2] = 1;
	Graph->Matrix[E->V2][E->V1] = 1;
}

void Solve(MGraph Graph)
{
	Vertex Path[Graph->Nv][Graph->Nv];
	Vertex Dist[Graph->Nv][Graph->Nv];
	int i, j;
	for(i = 0; i < Graph->Nv; i++)
		for(j = 0; j < Graph->Nv; j++){
			Dist[i][j] = Graph->Matrix[i][j];
			
		}


}

void Dijkstra(MGraph Graph, Vertex Dist[][], Vertex Path[][])
{

}