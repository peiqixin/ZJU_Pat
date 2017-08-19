#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAXVERTEXNUM 500
#define NIL -1
#define DG 1
#define UDG 2
#define INF 65535
#include <stdbool.h>
#include "../LinkedList/linkedlist.h"

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
	int kind;
};
typedef PtrToGNode Graph;

void dfs(Graph graph);
void dfs_visit(Graph graph, Vertex u);
void bfs(Graph graph, Vertex u);
Graph create_graph();
void insert_edge(Graph graph, Edge edge);
void initialize_single_source(Graph graph, Vertex v);
void relax(Graph graph, Vertex v, PtrToAdjNode adj);
bool bellman_ford(Graph graph, Vertex s);
void print_graph(Graph graph, Vertex s);
void dijkstra(Graph graph, Vertex s);
Vertex find_mindist(Graph graph);
LinkedList topological_sort(Graph graph);
void topo_dfs(Graph graph, LinkedList linkedlist);
void topo_dfs_visit(Graph graph, Vertex u, LinkedList linkedlist);