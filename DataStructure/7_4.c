// 07-图4 哈利·波特的考试 
/*
	哈利·波特要考试了，他需要你的帮助。这门课学的是用魔咒将一种动物变成另一种动物的本事。例如将猫变成老鼠的魔咒是haha，将老鼠变成鱼的魔咒是hehe等等。反方向变化的魔咒就是简单地将原来的魔咒倒过来念，例如ahah可以将老鼠变成猫。另外，如果想把猫变成鱼，可以通过念一个直接魔咒lalala，也可以将猫变老鼠、老鼠变鱼的魔咒连起来念：hahahehe。

	现在哈利·波特的手里有一本教材，里面列出了所有的变形魔咒和能变的动物。老师允许他自己带一只动物去考场，要考察他把这只动物变成任意一只指定动物的本事。于是他来问你：带什么动物去可以让最难变的那种动物（即该动物变为哈利·波特自己带去的动物所需要的魔咒最长）需要的魔咒最短？例如：如果只有猫、鼠、鱼，则显然哈利·波特应该带鼠去，因为鼠变成另外两种动物都只需要念4个字符；而如果带猫去，则至少需要念6个字符才能把猫变成鱼；同理，带鱼去也不是最好的选择。

	输入格式:

	输入说明：输入第1行给出两个正整数NN (\le 100≤100)和MM，其中NN是考试涉及的动物总数，MM是用于直接变形的魔咒条数。为简单起见，我们将动物按1~NN编号。随后MM行，每行给出了3个正整数，分别是两种动物的编号、以及它们之间变形需要的魔咒的长度(\le 100≤100)，数字之间用空格分隔。

	输出格式:

	输出哈利·波特应该带去考场的动物的编号、以及最长的变形魔咒的长度，中间以空格分隔。如果只带1只动物是不可能完成所有变形要求的，则输出0。如果有若干只动物都可以备选，则输出编号最小的那只。

	输入样例:

	6 11
	3 4 70
	1 2 1
	5 4 50
	2 6 50
	5 6 60
	1 3 70
	4 6 60
	3 6 80
	5 1 100
	2 4 60
	5 2 80
	输出样例:

	4 70
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;

typedef struct ENode * PtrToENode;
struct ENode
{
	Vertex V1;
	Vertex V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;
struct GNode
{
	int Matrix[MaxVertexNum][MaxVertexNum];
	int Nv;
	int Ne;
};
typedef PtrToGNode MGraph;

MGraph CreateGraph(int Nv);
MGraph BuildGraph();
void InsertEdge(MGraph Graph, Edge E);
void Floyd(MGraph Graph, WeightType D[][MaxVertexNum]);
void FindAnimal(MGraph Graph);
WeightType FindMaxDist(WeightType D[][MaxVertexNum], Vertex i, int N);
//bool Floyd(MGraph Graph,int D[][MaxVertexNum], int Path[][MaxVertexNum]);

int main(int argc, char const *argv[])
{
	MGraph Graph = BuildGraph();

	FindAnimal(Graph);

	return 0;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	int Nv, i, Ne;
	scanf("%d %d", &Nv, &Ne);
	Graph = CreateGraph(Nv);
	Graph->Ne = Ne;
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
	MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = Nv;
	Graph->Ne = 0;
	int i, j;
	for(i = 0; i < Graph->Nv; i++)
		for(j = 0; j < Graph->Nv; j++)
			Graph->Matrix[i][j] = INFINITY;
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->Matrix[E->V1][E->V2] = E->Weight;
	Graph->Matrix[E->V2][E->V1] = E->Weight;
}

// bool Floyd(MGraph Graph,int D[][MaxVertexNum], int Path[][MaxVertexNum])
// {
// 	int i, j, k;
// 	for(i = 0; i < Graph->Nv; i++)
// 		for(j = 0; j < Graph->Nv; j++){
// 			D[i][j] = Graph->Matrix[i][j];
// 			Path[i][j] = -1;
// 		}

// 	for(k = 0; k < Graph->Nv; k++)
// 		for(i = 0; i < Graph->Nv; i++)
// 			for(j = 0; j < Graph->Nv, j++)
// 				if(D[i][k] + D[k][j] < D[i][j]){
// 					D[i][j] = D[i][k] + D[k][j];
// 					if(i == j && D[i][j] < 0)
// 						return false;
// 					Path[i][j] = k;
// 				}
// 	return true;
// }

void Floyd(MGraph Graph, WeightType D[][MaxVertexNum])
{	
	Vertex i, j, k;
	for(i = 0; i < Graph->Nv; i++)
		for(j = 0; j < Graph->Nv; j++)
			D[i][j] = Graph->Matrix[i][j];
	for(k = 0; k < Graph->Nv; k++)
		for(i = 0; i < Graph->Nv; i++)
			for(j = 0; j < Graph->Nv; j++)
				if(D[i][j] > D[i][k] + D[k][j])
					D[i][j] = D[i][k] + D[k][j];
}

void FindAnimal(MGraph Graph)
{
	Vertex V, Animal;
	WeightType D[MaxVertexNum][MaxVertexNum], Max;
	Floyd(Graph, D);
	WeightType Min = INFINITY;
	for(V = 0; V < Graph->Nv; V++){
		Max = FindMaxDist(D, V, Graph->Nv);
		if(Max == INFINITY){
			printf("0\n");
			return;
		}
		if(Min > Max){
			Min = Max;
			Animal = V + 1;
		}
	}
	printf("%d %d\n", Animal, Min);
}

WeightType FindMaxDist(WeightType D[][MaxVertexNum], Vertex i, int N)
{
	WeightType Max = -1;
	int j;
	for(j = 0; j < N; j++)
		if(i != j && Max < D[i][j])
			Max = D[i][j];
	return Max;
}