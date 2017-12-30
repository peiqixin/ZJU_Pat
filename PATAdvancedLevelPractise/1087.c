#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x7fff
#define MAX 200

/*
	使用邻接表，麻烦一点，使用邻接矩阵应该会简单点
	使用dijstra算法，附加两个判断条件
	字符串的映射直接使用FindIndex函数查找，比较暴力，没想到什么好的方法，不过题目数据应该不会很复杂
*/
typedef int Vertex;
typedef struct ArcNode *Arc;
struct ArcNode
{
	Vertex adjv;
	Arc nextArc;
	int weight;
};

typedef struct AdjVertexNode
{
	int romance;
	char loc[4];
	Arc FirstArc;		
} GList[MAX];

typedef struct GraphNode *Graph;
struct GraphNode
{
	GList G;
	int vexnum, arcnum;
};

Vertex FindIndex(Graph graph, char str[])
{
	int i;
	for(i = 0; i < graph->vexnum; i++)
		if(strcmp(graph->G[i].loc, str) == 0)
			break;
	if(i < graph->vexnum)
		return i;
	else
		return -1;
}

void Insert(Graph graph)
{
	char loc1[4], loc2[4];
	int weight;
	scanf("%s %s %d", loc1, loc2, &weight);
	int v1 = FindIndex(graph, loc1);
	int v2 = FindIndex(graph, loc2);
	if(v1 == -1 && v2 == -1) return;
	Arc newArc = (Arc)malloc(sizeof(struct ArcNode));
	newArc->weight = weight;
	newArc->adjv = v2;
	newArc->nextArc = graph->G[v1].FirstArc;
	graph->G[v1].FirstArc = newArc;

	newArc = (Arc)malloc(sizeof(struct ArcNode));
	newArc->adjv = v1;
	newArc->weight = weight;
	newArc->nextArc = graph->G[v2].FirstArc;
	graph->G[v2].FirstArc = newArc;
}

Graph BuildGraph()
{
	int Nv, Ne;
	Graph graph = (Graph)malloc(sizeof(struct GraphNode));
	scanf("%d %d %s", &Nv, &Ne, graph->G[0].loc);
	int i;
	graph->G[0].FirstArc = NULL;
	graph->vexnum = Nv;
	graph->arcnum = Ne;
	for(i = 1; i < Nv; i++){
		graph->G[i].FirstArc = NULL;
		scanf("%s %d", graph->G[i].loc, &graph->G[i].romance);
	}
	for(i = 0; i < graph->arcnum; i++)
		Insert(graph);
	return graph;
}

Vertex FindMin(Graph graph, int D[], int visit[])
{
	Vertex min = -1;
	int i, MinWeight = INF;
	for(i = 1; i < graph->vexnum; i++)
		if(!visit[i] && D[i] < MinWeight){
			MinWeight = D[i];
			min = i;
		}
	return min;
}

void Solve(Graph graph)
{
	int D[graph->vexnum], R[graph->vexnum], Path[graph->vexnum], i, visit[graph->vexnum], count[graph->vexnum], path_number[graph->vexnum];
	// 初始化
	for(i = 1; i < graph->vexnum; i++){
		D[i] = INF;
		R[i] = 0;
		Path[i] = -1;
		visit[i] = 0;
		path_number[i] = 0;
		count[i] = 1;
	}
	D[0] = 0;
	visit[0] = 1;
	R[0] = 0;
	Path[0] = -1;
	Arc arc = graph->G[0].FirstArc;
	while(arc){
		D[arc->adjv] = arc->weight;
		R[arc->adjv] = graph->G[arc->adjv].romance;
		path_number[arc->adjv] = 1;
		count[arc->adjv] = 1;
		Path[arc->adjv] = 0;
		arc = arc->nextArc;
	}
	Vertex v;
	while(1){
		v = FindMin(graph, D, visit);
		if(v == -1) break;
		visit[v] = 1;
		Arc w = graph->G[v].FirstArc;
		while(w){
			if(!visit[w->adjv]){
				if(D[w->adjv] > D[v] + w->weight){
					D[w->adjv] = D[v] + w->weight;
					R[w->adjv] = R[v] + graph->G[w->adjv].romance;
					Path[w->adjv] = v;
					count[w->adjv] = count[v] + 1;
					path_number[w->adjv] = path_number[v];
				}else if(D[w->adjv] == D[v] + w->weight){
					path_number[w->adjv] += path_number[v];
					if(R[w->adjv] < R[v] + graph->G[w->adjv].romance){
						R[w->adjv] = R[v] + graph->G[w->adjv].romance;
						Path[w->adjv] = v;
						count[w->adjv] = count[v] + 1;
					}else if(R[w->adjv] == R[v] + graph->G[w->adjv].romance && (count[w->adjv] > count[v] + 1)){
						Path[w->adjv] = v;
						count[w->adjv] = count[v] + 1;
					}
				}
			}
			w = w->nextArc;
		}
	}
	Vertex rom = FindIndex(graph, "ROM");
	printf("%d %d %d %d\n", path_number[rom], D[rom], R[rom], R[rom] / (count[rom]));
	int stack[graph->vexnum], top;
	top = -1;
	while(1){
		rom = Path[rom];
		if(rom == -1) break;
		stack[++top] = rom;
	}
	for(i = top; i >= 0; i--){
		printf("%s->", graph->G[stack[i]].loc);
	}
	printf("ROM\n");
}

int main(int argc, char const *argv[])
{
	Graph graph = BuildGraph();
	Solve(graph);
	return 0;
}