// 06-图1 列出连通集
/*
	给定一个有NN个顶点和EE条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N-1N−1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

	输入格式:

	输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。

	输出格式:

	按照"{ v1 v2 ... vk}"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

	输入样例:

	8 6
	0 7
	0 1
	2 0
	4 1
	2 4
	3 5
	输出样例:

	{ 0 1 4 2 7 }
	{ 3 5 }
	{ 6 }
	{ 0 1 2 7 4 }
	{ 3 5 }
	{ 6 }
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv;
	int Ne;
	int Matrix[10][10];
};
typedef PtrToGNode MGraph;

PtrToGNode CreateGraph(MGraph Graph, int Nv, int Ne);
void InsertEdge(MGraph Graph, int V1, int V2);
void Init(int n[], int Nv);
void DFS(MGraph Graph, int Vertex, int visit[]);
void BFS(MGraph Graph, int Vertex, int visit[]);

int main(int argc, char const *argv[])
{
	int Nv,Ne;
	scanf("%d %d\n", &Nv, &Ne);
	PtrToGNode Graph = NULL;
	Graph = CreateGraph(Graph, Nv, Ne);
	int i, V1, V2;
	for(i = 0; i < Graph->Ne; i++){
		scanf("%d %d", &V1, &V2);
		InsertEdge(Graph, V1, V2);
	}
	int visit[Nv];
	Init(visit, Nv);

	for(i = 0; i < Nv; i++){
		if(visit[i] != 1){
			printf("{ ");
			DFS(Graph, i, visit);
			printf("}\n");
		}
	}
	Init(visit, Nv);
	for(i = 0; i < Nv; i++){
		if(visit[i] != 1){
			printf("{ ");
			BFS(Graph, i, visit);
			printf("}\n");
		}
	}
	return 0;
}

PtrToGNode CreateGraph(MGraph Graph, int Nv, int Ne)
{
	if(!Graph){
		Graph = (MGraph)malloc(sizeof(struct GNode));
		Graph->Nv = Nv;
		Graph->Ne = Ne;
		int i, j;
		for(i = 0; i < Graph->Nv; i++)
			for(j = 0; j < Graph->Nv; j++)
				Graph->Matrix[i][j] = 0;
	}
	return Graph;
}

void InsertEdge(MGraph Graph, int V1, int V2)
{
	if(!Graph)
		return;
	else{
		if(V1 < Graph->Nv && V2 < Graph->Nv){
			Graph->Matrix[V1][V2] = 1;
			Graph->Matrix[V2][V1] = 1;
		}
	}
}

void Init(int n[], int Nv)
{
	int i;
	for(i=0; i < Nv; i++)
		n[i] = 0;
}

void DFS(MGraph Graph, int Vertex, int visit[])
{
	if(visit[Vertex] == 1)
		return;
	int stack[10];
	Init(stack, 10);
	int top = -1;
	if(Vertex < 0)
		return;
	stack[++top] = Vertex;
	visit[Vertex] = 1;
	printf("%d ", stack[top]);
	int i, j;
	while(top >= 0){
		i = stack[top];
		while(i < Graph->Nv){
			j = 0;
			while(j < Graph->Nv){
				if((visit[j] != 1) && (Graph->Matrix[i][j])){
					stack[++top] = j;
					visit[j] = 1;
					printf("%d ", j);
					break;
				}
				j++;
			}
			i = j;
		}
		top--;
	}
}

void BFS(MGraph Graph, int Vertex, int visit[])
{
	int stack[10];
	Init(stack, 10);
	int top = -1;
	stack[++top] = Vertex;

	int stack2[10];
	Init(stack2, 10);
	int top2;

	printf("%d ", stack[top]);
	visit[stack[top]] = 1;
	int i, j;
	while(top > -1){
		top2 = -1;
		int x = 0;
		while(x <= top){
			i = stack[x];
			j = 0;
			while(j < Graph->Nv){
				if((visit[j] != 1) && (Graph->Matrix[i][j] == 1)){
					stack2[++top2] = j;
					visit[j] = 1;
					printf("%d ", j);
				}
				j++;
			}
			x++;
		}
		j = -1;
		top = -1;
		while((j <= top2) && top2 != -1)
			stack[++top] = stack2[++j];
	}
}