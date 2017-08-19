#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

void dfs(Graph graph)
{
	int i;
	for(i = 0; i < graph->num_vertex; i++){
		graph->G[i].color = WHITE;
		graph->G[i].front = NIL;
	}
	graph->G[0].d = 0;

	Vertex v;
	for(v = 0; v < graph->num_vertex; v++)
		if(graph->G[v].color == WHITE)
			dfs_visit(graph, v);
}

void dfs_visit(Graph graph, Vertex u)
{
	PtrToAdjNode adj;
	adj = graph->G[u].first_edge;
	graph->G[u].color = GRAY;
	printf("vertex = %d\n", u);
	while(adj != NULL){
		if(graph->G[adj->adjV].color == WHITE){
			graph->G[adj->adjV].d = graph->G[u].d + adj->weight;
			dfs_visit(graph, adj->adjV);
		}
		adj = adj->next;
	}
}

Graph create_graph()
{
	int nv, ne, kind;
	scanf("%d %d %d", &nv, &ne, &kind);
	Graph graph;
	graph = (PtrToGNode)malloc(sizeof(struct GNode));
	graph->num_vertex = nv;
	graph->num_edge = ne;
	graph->kind = kind;
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

void insert_edge(Graph graph, Edge edge)
{
	PtrToAdjNode adj;

	adj = (PtrToAdjNode)malloc(sizeof(struct AdjNode));
	adj->adjV = edge->v2;
	adj->weight = edge->weight;
	adj->next = graph->G[edge->v1].first_edge;
	graph->G[edge->v1].first_edge = adj;
	// 无向图
	if(graph->kind == UDG){
		adj = (PtrToAdjNode)malloc(sizeof(struct AdjNode));
		adj->adjV = edge->v1;
		adj->weight = edge->weight;
		adj->next = graph->G[edge->v2].first_edge;
		graph->G[edge->v2].first_edge = adj;
	}
}

void bfs(Graph graph, Vertex u)
{
	int queue[graph->num_vertex];
	int top, rear;
	top = rear = -1;
	queue[++top] = u;
	Vertex v;
	PtrToAdjNode adj;
	while(top != rear){
		rear++;
		rear = rear >= graph->num_vertex ? rear % graph->num_vertex : rear;
		v = queue[rear];
		graph->G[v].color = GRAY;
		printf("vertex = %d\n", v);
		adj = graph->G[v].first_edge;
		Vertex u;
		while(adj != NULL){
			u = adj->adjV;
			if(graph->G[u].color == WHITE){
				graph->G[u].color = GRAY;
				++top;
				top = top >= graph->num_vertex ? top % graph->num_vertex : top;
				queue[top] = u;
			}
			adj = adj->next;
		}
		graph->G[v].color = BLACK;
	}
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

void relax(Graph graph, Vertex v, PtrToAdjNode adj)
{
	Vertex u = adj->adjV;
	if(graph->G[u].d > graph->G[v].d + adj->weight){
		graph->G[u].d = graph->G[v].d + adj->weight;
		graph->G[u].front = v;
	}
}

bool bellman_ford(Graph graph, Vertex s)
{
	initialize_single_source(graph, s);
	Vertex v, w;
	PtrToAdjNode adj;
	for(w = 0; w < graph->num_vertex - 1; w++){
		for(v = 0; v < graph->num_vertex; v++){
			adj = graph->G[v].first_edge;
			while(adj != NULL){
				relax(graph, v, adj);
				adj = adj->next;
			}
		}
	}
	for(v = 0; v < graph->num_vertex; v++){
		adj = graph->G[v].first_edge;
		while(adj != NULL){
			if(graph->G[adj->adjV].d < graph->G[v].d + adj->weight)
				return false;
			adj = adj->next;
		}
	}
	return true;
}
void print_graph(Graph graph, Vertex s)
{
	Vertex v;
	for(v = 0; v < graph->num_vertex; v++){
		printf("Vertex %d to Vertex %d minist path is %d.\n", s, v, graph->G[v].d);
	}
}

void dijkstra(Graph graph, Vertex s)
{
	initialize_single_source(graph, s);
	while(1){
		Vertex v = find_mindist(graph);
		if(v == NIL) break;
		graph->G[v].color = BLACK;
		Vertex u;
		PtrToAdjNode adj;
		adj = graph->G[v].first_edge;
		while(adj != NULL){
			u = adj->adjV;
			if(graph->G[u].color == WHITE){
				if(adj->weight < 0){
					printf("There is no solution\n");
					return;
				}else{
					relax(graph, v, adj);
				}
			}
			adj = adj->next;
		}
	}
}
Vertex find_mindist(Graph graph)
{
	Vertex min_vertex, v;
	WeightType min_dist = INF;
	min_vertex = NIL;
	for(v = 0; v < graph->num_vertex; v++){
		if(graph->G[v].color == WHITE && graph->G[v].d < min_dist){
			min_dist = graph->G[v].d;
			min_vertex = v;
		}
	}
	return min_vertex;
}

LinkedList topological_sort(Graph graph)
{
	LinkedList linkedlist = create_linkedlist();
	topo_dfs(graph, linkedlist);
	return linkedlist;
}

void topo_dfs(Graph graph, LinkedList linkedlist)
{
	int i;
	for(i = 0; i < graph->num_vertex; i++){
		graph->G[i].color = WHITE;
		graph->G[i].front = NIL;
	}
	graph->G[0].d = 0;

	Vertex v;
	for(v = 0; v < graph->num_vertex; v++)
		if(graph->G[v].color == WHITE)
			topo_dfs_visit(graph, v, linkedlist);
}

void topo_dfs_visit(Graph graph, Vertex u, LinkedList linkedlist)
{
	PtrToAdjNode adj;
	adj = graph->G[u].first_edge;
	graph->G[u].color = GRAY;
	printf("vertex = %d\n", u);
	while(adj != NULL){
		if(graph->G[adj->adjV].color == WHITE){
			graph->G[adj->adjV].d = graph->G[u].d + adj->weight;
			dfs_visit(graph, adj->adjV);
		}
		adj = adj->next;
	}
	insert_front(linkedlist, graph->G[u].data);
}
/*
5 6 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

5 10 1
1 2 1 5 3
0 1 6
0 4 7
1 2 5
1 4 8
1 3 -4
2 1 -2
3 2 7
3 0 2
4 2 -3
4 3 9

5 10 1
1 2 1 5 3
0 1 10
0 4 5
1 2 1
1 4 2
2 3 4
3 2 6
3 0 7
4 1 3
4 2 9
4 3 2

*/
int main(int argc, char const *argv[])
{
	Graph graph = create_graph();
	//dfs(graph);
	//bfs(graph, 0);
	Vertex s = 0;
	// if(bellman_ford(graph, s))
	// 	print_graph(graph, s);
	// else
	// 	printf("This graph has not a solution\n");
	dijkstra(graph, s);
	print_graph(graph, s);

	LinkedList linkedlist = topological_sort(graph);
	return 0;
}