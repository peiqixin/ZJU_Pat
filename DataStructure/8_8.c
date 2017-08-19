// 08-图8 How Long Does It Take
/*
	Given the relations of all the activities of a project, you are supposed to find the earliest completion time of the project.

	Input Specification:

	Each input file contains one test case. Each case starts with a line containing two positive integers NN (\le 100≤100), the number of activity check points (hence it is assumed that the check points are numbered from 0 to N-1N−1), and MM, the number of activities. Then MM lines follow, each gives the description of an activity. For the i-th activity, three non-negative numbers are given: S[i], E[i], and L[i], where S[i] is the index of the starting check point, E[i] of the ending check point, and L[i] the lasting time of the activity. The numbers in a line are separated by a space.

	Output Specification:

	For each test case, if the scheduling is possible, print in a line its earliest completion time; or simply output "Impossible".

	Sample Input 1:

	9 12
	0 1 6
	0 2 4
	0 3 5
	1 4 1
	2 4 1
	3 5 2
	5 4 0
	4 6 9
	4 7 7
	5 7 4
	6 8 2
	7 8 4
	Sample Output 1:

	18
	Sample Input 2:

	4 5
	0 1 1
	0 2 2
	2 1 3
	1 3 4
	3 2 5
	Sample Output 2:

	Impossible
*/
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
	WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct GNode * PtrToGNode;
struct GNode
{
	int Nv;
	int Ne;
	WeightType Matrix[MaxVertextNum][MaxVertextNum];
	int Indgree[MaxVertextNum];
};
typedef PtrToGNode MGraph;

MGraph BuildGraph();
MGraph CreateGraph(int Nv);
void InsertEdge(MGraph Graph, Edge E);
WeightType TopSort(MGraph Graph);

int main(int argc, char const *argv[])
{
	MGraph Graph = BuildGraph();
	WeightType Weight = TopSort(Graph);
	if(Weight != -1)
		printf("%d\n", Weight);
	else
		printf("Impossible\n");
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
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
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
	Vertex i, j;
	for(i = 0; i < Graph->Nv; i++){
		Graph->Indgree[i] = 0;
		for(j = 0; j <Graph->Nv; j++){
			Graph->Matrix[i][j] = INFINITY;
		}
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->Matrix[E->V1][E->V2] = E->Weight;
	Graph->Indgree[E->V2]++;
}

WeightType TopSort(MGraph Graph)
{
	WeightType Earliest[MaxVertextNum];
	int countV = 0;
	Vertex queue[MaxVertextNum];
	Vertex rear, top;
	rear = top = -1;
	Vertex V, W;
	for(V = 0; V < Graph->Nv; V++){
		Earliest[V] = 0;
		if(Graph->Indgree[V] == 0){
			queue[++top] = V;
		}
	}
	countV++;
	while(top > rear){
		V = queue[++rear];
		for(W = 0; W < Graph->Nv; W++){
			if(Graph->Matrix[V][W] < INFINITY){
				if(Earliest[W] < Earliest[V] + Graph->Matrix[V][W]){
					Earliest[W] = Earliest[V] + Graph->Matrix[V][W];
				}
				Graph->Indgree[W]--;
				if(Graph->Indgree[W] == 0){
					queue[++top] = W;
				}
				countV++;
			}
		}
	}
	WeightType MaxWeight = 0;
	for(V = 0; V < Graph->Nv; V++){
		if(Earliest[V] > MaxWeight){
			MaxWeight = Earliest[V];
		}
	}
	if(countV < Graph->Nv)
		return -1;
	else
		return MaxWeight;
}