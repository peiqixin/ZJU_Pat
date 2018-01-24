#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAXVERTEXNUM 500
#define NIL -1
#define INF 65535

typedef int WeightType;
typedef int DataType;
typedef int Vertex;
typedef int Color;

typedef struct ENode *PtrToENode;
struct ENode
{
	Vertex v1;
	Vertex v2;
	WeightType weight;
};
typedef PtrToENode Edge;

typedef struct AdjNode* PtrToAdjNode;
struct AdjNode
{
	Vertex adjV;
	WeightType weight;
	PtrToAdjNode next;
};

typedef struct VNode* PtrToVNode;
typedef struct VNode
{
	Color color;
	Vertex front;
	WeightType d;
	DataType data;
	PtrToAdjNode first_edge;
} AdjList[MAXVERTEXNUM];

typedef struct GNode* PtrToGNode;
struct GNode
{
	AdjList G;
	int num_vertex;
	int num_edge;
};
typedef PtrToGNode Graph;
Vertex find_mindist(Graph graph);
void insert_edge(Graph graph, Edge edge)
{
	PtrToAdjNode adj;

	adj = (PtrToAdjNode)malloc(sizeof(struct AdjNode));
	adj->adjV = edge->v2;
	adj->weight = edge->weight;
	adj->next = graph->G[edge->v1].first_edge;
	graph->G[edge->v1].first_edge = adj;

	adj = (PtrToAdjNode)malloc(sizeof(struct AdjNode));
	adj->adjV = edge->v1;
	adj->weight = edge->weight;
	adj->next = graph->G[edge->v2].first_edge;
	graph->G[edge->v2].first_edge = adj;

}

Graph create_graph(int nv, int ne)
{
	Graph graph;
	graph = (PtrToGNode)malloc(sizeof(struct GNode));
	graph->num_vertex = nv;
	graph->num_edge = ne;
	Vertex v;
	for(v = 0 ; v < graph->num_vertex; v++){
		graph->G[v].first_edge = NULL;
		scanf("%d", &graph->G[v].data);
		graph->G[v].color = WHITE;
		graph->G[v].front = NIL;
	}
	Edge E;
	E = (PtrToENode)malloc(sizeof(struct ENode));
	int i;
	for(i = 0; i < graph->num_edge; i++){
		scanf("%d %d %d", &E->v1, &E->v2, &E->weight);
		insert_edge(graph, E);
	}
	return graph;
}

void initialize_single_source(Graph graph, Vertex v)
{
	int i;
	for(i = 0; i < graph->num_vertex; i++){
		graph->G[i].d = INF;
		graph->G[i].front = NIL;
	}
	graph->G[v].d = 0;
}

int Max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

void dijkstra(Graph graph, Vertex s, Vertex d)
{

	int team_count[graph->num_vertex];
	memset(team_count, 0, sizeof(team_count));
	int shortest_path[graph->num_vertex];
	memset(shortest_path, 0, sizeof(shortest_path));
	initialize_single_source(graph, s);
	team_count[s] = graph->G[s].data;
	shortest_path[s] = 1;
	while(1){
		Vertex v = find_mindist(graph);
		if(v == NIL) break;
		graph->G[v].color = BLACK;
		PtrToAdjNode adj = graph->G[v].first_edge;
		Vertex u;
		while(adj != NULL){
			u = adj->adjV;
			if(graph->G[u].d > graph->G[v].d + adj->weight){
				graph->G[u].d = graph->G[v].d + adj->weight;
				team_count[u] = team_count[v] + graph->G[u].data;
				shortest_path[u] = shortest_path[v];
			}else if(graph->G[u].d == graph->G[v].d + adj->weight){
				shortest_path[u] = shortest_path[v] + shortest_path[u];
				team_count[u] = Max(team_count[u], team_count[v] + graph->G[u].data);
			}
			adj = adj->next;
		}
	}
	printf("%d %d\n", shortest_path[d], team_count[d]);
}

Vertex find_mindist(Graph graph)
{
	Vertex min_vertex, v;
	WeightType min_dist = INF;
	min_vertex = NIL;
	for(v = 0; v < graph->num_vertex; v++){
		if(graph->G[v].color == WHITE && graph->G[v].d < min_dist){
			min_vertex = v;
			min_dist = graph->G[v].d;
		}
	}
	return min_vertex;
}

int main(int argc, char const *argv[])
{
	int nv, ne, s, d;
	scanf("%d %d %d %d", &nv, &ne, &s, &d);
	Graph graph = create_graph(nv, ne);
	dijkstra(graph, s, d);
	return 0;
}