/* 图的邻接矩阵表示法 */

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode *PtrToENode;
strcut ENode
{
	Vertex V1, V2;     /* 有向边<V1, V2> */
	WeightType Weight; /* 权重 */
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

/* 初始化一个有VertexNum个顶点但没有边的图 */
MGraph CreateGraph( int VertexNum )
{
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Ne = 0;
	Graph->Nv = VertexNum;
	/* 初始化邻接矩阵 */
	/* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
	int i,j;
	for(i = 0; i < Graph->Nv; i++)
		for(j = 0; j < Graph->Nv; i++)
			Graph->G[i][j] = INFINITY;

	return Graph;
}

void InsertEdge( MGraph Graph, Edge E )
{
	if(Graph){
		Graph->G[E->V1][E->V2] = E->Weight;
		Graph->G[E->V2][E->V1] = E->Weight;
	}
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);
	Graph = CreateGraph(Graph);

	scanf("%d", &Graph->Ne);
	if(Graph->Ne != 0){
		E = (Edge)malloc(sizeof(struct ENode));
		for(i=0; i<Graph->Ne; i++){
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}
	for(V=0; V<Graph->Nv; V++)
		scanf(" %c", &(Graph->Data[V]));
	return Graph;
}